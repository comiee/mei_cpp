#ifndef COROUTINE_H
#define COROUTINE_H

#include "Promise.h"

template<typename Y, typename R>
class Coroutine : public std::coroutine_handle<Promise<Y, R>> {
public:
    using promise_type = Promise<Y, R>;

    Coroutine(std::coroutine_handle<Promise<Y, R>> h)
            : std::coroutine_handle<Promise<Y, R>>(h) {
    }
};

#endif //COROUTINE_H
