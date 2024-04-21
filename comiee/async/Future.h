#pragma once

#include <ctime>
#include "Coroutine.h"

template<typename R>
class Future : public Coroutine<void, R, std::suspend_always> {
public:
    Future(Coroutine<void, R, std::suspend_always>::handle_type handle)
            : Coroutine<void, R, std::suspend_always>(handle) {
    }
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
