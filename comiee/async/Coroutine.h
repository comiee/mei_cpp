#pragma once

#include <cassert>
#include "Promise.h"
#include "memory"

template<typename Y, typename R, typename I>
class Coroutine {
public:
    using promise_type = Promise<Y, R, I>;

    using handle_type = std::coroutine_handle<promise_type>;

    class MemoryHelper {
    public:
        MemoryHelper(handle_type handle) : handle(handle) {
        }

        ~MemoryHelper() {
            assert(handle);
            handle.destroy();
        }

    private:
        handle_type handle;
    };

    Coroutine(handle_type handle) : handle(handle) {
        helper = std::make_shared<MemoryHelper>(handle);
    }

    Coroutine(const Coroutine &co) = default;

    Coroutine(Coroutine &&co) noexcept: handle(co.handle), helper(co.helper) {
        co.handle = nullptr;
        co.helper = nullptr;
    }

    ~Coroutine() {
    }

    Coroutine &operator=(const Coroutine &) = default;

    Coroutine &operator=(Coroutine &&co) noexcept {
        handle = co.handle;
        co.handle = nullptr;
        helper = co.helper;
        co.helper = nullptr;
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
    std::shared_ptr<MemoryHelper> helper;
};
