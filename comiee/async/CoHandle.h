#pragma once

#include <coroutine>

template<typename P>
class CoHandle {
public:
    CoHandle(std::coroutine_handle<P> handle) : handle(handle) {
    }

    CoHandle(const CoHandle &) = delete;

    ~CoHandle() {
        if (handle) {
            handle.destroy();
            handle = nullptr;
        }
    }

    CoHandle &operator=(const CoHandle &) = delete;

    bool operator==(const CoHandle &other) const {
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

    void* address() const {
        if (!handle) throw "handle为空";
        return handle.address();
    }

    operator bool() const {
        return bool(handle);
    }

private:
    std::coroutine_handle<P> handle;
};
