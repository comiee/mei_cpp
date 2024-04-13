#include "comm.h"
#include "AsyncClient.h"
#include "log.h"
#include "CustomException.h"


static Logger logger("asyncClient", Logger::INFO, Logger::DEBUG);
#define EXEC(fn)        \
do {                    \
    auto ret = fn;      \
    if (ret) {         \
        logger.error("异步客户端执行出错，函数：%s， 行号：%d，返回值：%d", __FUNCTION__, __LINE__, ret); \
    }                   \
} while(0)


AsyncClient::AsyncClient(string cmd) :
        cmd(std::move(cmd)) {
    WSADATA wsa_data;
    EXEC(WSAStartup(MAKEWORD(1, 1), &wsa_data)); // TODO 这么做可能有问题
}

Future<string> AsyncClient::send(const string &message) const {
    if (sock == INVALID_SOCKET) {
        logger.error("异步客户端%s发生错误：在调用send之前没有调用connectSock", cmd.c_str());
    }
    sendMsg(sock, message);
    logger.debug("异步客户端%s向服务器发送：%s", cmd.c_str(), message.c_str());
    WAIT(result, receive())
    logger.debug("异步客户端%s收到服务器响应：%s", cmd.c_str(), message.c_str());
    co_return result;
}

void AsyncClient::close() const {
    if (sock != INVALID_SOCKET) {
        closesocket(sock);
    }
    WSACleanup(); // TODO 这么做可能有问题
}

AsyncClient::~AsyncClient() {
    close();
}

Future<void> AsyncClient::connectSock() {
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in address = {0};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(HOST);
    address.sin_port = htons(ASYNC_PORT);
    while (connect(sock, (struct sockaddr *) &address, sizeof(address)) == SOCKET_ERROR) {
        co_await std::suspend_always();
    }

    // 设置sock为非阻塞模式
    int iMode = 1;
    EXEC(ioctlsocket(sock, FIONBIO, (u_long FAR *)&iMode));

    sendMsg(sock, cmd);
    WAIT(receive())

    logger.debug("异步客户端%s与服务器建立连接", cmd.c_str());
}

Future<string> AsyncClient::receive() const {
    while (true) {
        string result;
        try {
            result = recvMsg(sock);
        } catch (SocketException &e) {
        }
        if (result.empty()) {
            co_await std::suspend_always();
            WAIT(asleep(1))
        } else {
            co_return result;
        }
    }
}

EventLoop &getLoop() {
    static EventLoop loop;
    return loop;
}