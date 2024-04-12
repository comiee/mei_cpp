#ifndef FUTURE_H
#define FUTURE_H

#include <ctime>
#include "Promise.h"

template<typename R>
class Future {
public:
    using promise_type = Promise<void, R, std::suspend_always>;

    using handle_type = std::coroutine_handle<promise_type>;

    Future(handle_type handle) : handle(handle) {
    }

    Future(const Future &co) = default;

    Future(Future &&co) noexcept: handle(co.handle) {
        co.handle = nullptr;
    }

    ~Future() {
        if (handle && handle.done()) {
            handle.destroy();
        }
    }

    Future &operator=(const Future &) = default;

    Future &operator=(Future &&co) noexcept {
        handle = co.handle;
        co.handle = nullptr;
        return *this;
    }

    bool operator==(const Future &other) const {
        return handle == other.handle;
    }

    [[nodiscard]] bool done() const {
        return handle.done();
    }

    void resume() const {
        handle.resume();
    }

    [[nodiscard]] auto promise() const {
        return handle.promise();
    }

private:
    handle_type handle;
};

#define CONCAT(x, y) x##y

#define WAIT_VOID(fu, n)            \
const auto& CONCAT(__temp_, n) = fu;        \
while(!CONCAT(__temp_, n).done()){          \
    CONCAT(__temp_, n).resume();            \
    co_await std::suspend_always(); \
}

#define WAIT_RETURN(res, fu, n)      \
WAIT_VOID(fu, n);                    \
auto res = CONCAT(__temp_, n).promise().get_return_value();

#define GET_F(f3, f2, f1, f0, ...) f0
#define WAIT(...) GET_F(, ##__VA_ARGS__, WAIT_RETURN, WAIT_VOID)(__VA_ARGS__, __COUNTER__)

template<typename R>
R run(const Future<R> &fu) {
    while (!fu.done()) {
        fu.resume();
    }
    return fu.promise().get_return_value();
}

Future<void> asleep(time_t t);

#endif //FUTURE_H
