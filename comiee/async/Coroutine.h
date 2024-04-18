#ifndef COROUTINE_H
#define COROUTINE_H

#include "Promise.h"

template<typename Y, typename R, typename I>
class Coroutine {
public:
    using promise_type = Promise<Y, R, I>;

    using handle_type = std::coroutine_handle<promise_type>;

    Coroutine(handle_type handle) : handle(handle) {
    }

    Coroutine(const Coroutine &co) = default;

    Coroutine(Coroutine &&co) noexcept: handle(co.handle) {
        co.handle = nullptr;
    }

    ~Coroutine() {
        if (handle && handle.done()) {
            handle.destroy();
        }
    }

    Coroutine &operator=(const Coroutine &) = default;

    Coroutine &operator=(Coroutine &&co) noexcept {
        handle = co.handle;
        co.handle = nullptr;
        return *this;
    }

    bool operator==(const Coroutine &other) const {
        return handle == other.handle;
    }

    bool done() const {
        if (!handle) throw "handle为空";
        return handle.done();
    }

    void resume() const {
        if (!handle) throw "handle为空";
        if (handle.done()) throw "handle已结束";
        handle.resume();
    }

    auto promise() const {
        if (!handle) throw "handle为空";
        return handle.promise();
    }

private:
    handle_type handle;
};

#endif //COROUTINE_H
