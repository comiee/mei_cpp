#include "Client.h"
#include "log.h"
#include "CustomException.h"
#include "comm.h"
#include "RegisterMsg.h"
#include "ResultMsg.h"

Logger logger("client", Logger::INFO, Logger::DEBUG);

Client::Client(string name) :
        name(std::move(name)) {
    WSADATA wsa_data;
    int ret = WSAStartup(MAKEWORD(1, 1), &wsa_data);
    if (ret != 0) {
        logger.error("初始化socket失败：%d", ret);
    }
}

string Client::getName() {
    return name;
}

Json::Value Client::send(const string &message) {
    for (uint i = 0; i < RECONNECT_COUNT; i++) {
        try {
            if (sender == INVALID_SOCKET) {
                sender = registerClient("sender");
            }
            sendMsg(sender, message);
            logger.debug("客户端[%s]发送消息到服务器：%s", name.c_str(), message.c_str());
            string result = recvMsg(sender);
            logger.debug("客户端[%s]收到服务器回响应：%s", name.c_str(), result.c_str());
            return ResultMsg::parse(result);
        } catch (MessageException &e) {
            logger.error("客户端[%s]解析服务器响应消息失败：%s", name.c_str(), e.getMsg());
            return Json::nullValue;
        }
        catch (SocketException &e) {
            logger.warning("客户端[%s]连接服务器失败：%s，将在%u秒后进行第%u重试",
                           name.c_str(), e.getMsg(), RECONNECT_TIME, i);
            Sleep(RECONNECT_TIME);
        }
    }
    return Json::nullValue;
}

void Client::listenServer() {
    for (uint i = 0; i < RECONNECT_COUNT; i++) {
        try {
            receiver = registerClient("receiver");
            while (true) {
                string message = recvMsg(receiver);
                logger.debug("客户端[%s]收到服务器消息：%s", name.c_str(), message.c_str());
                Json::Value value;
                try {
                    value = Message::parse(message);
                } catch (MessageException &e) {
                    logger.error("客户端[%s]解析服务器消息失败：%s", name.c_str(), e.getMsg());
                    continue;
                }
                string result = ResultMsg::build(value);
                logger.debug("客户端[%s]向服务器回响应：%s", name.c_str(), result.c_str());
                sendMsg(receiver, result);
            }
        } catch (SocketException &e) {
            logger.error("客户端[%s]监听服务器时出现异常：%s，将在%u秒后进行第%u次重试",
                         name.c_str(), e.getMsg(), RECONNECT_TIME, i);
        }
    }
}

void Client::close() const {
    if (sender != INVALID_SOCKET) {
        closesocket(sender);
    }
    if (receiver != INVALID_SOCKET) {
        closesocket(receiver);
    }
    WSACleanup();
}

Client::~Client() {
    close();
}

SOCKET Client::registerClient(const string &client_type) {
    logger.info("客户端[%s]正在向服务器注册%s", name.c_str(), client_type.c_str());
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in address = {0};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(HOST);
    address.sin_port = htons(PORT);
    while (connect(sock, (struct sockaddr *) &address, sizeof(address)) == SOCKET_ERROR);

    sendMsg(sock, RegisterMsg::build(name, client_type));
    logger.info("客户端[%s] %s 成功连接服务器", name.c_str(), client_type.c_str());
    return sock;
}