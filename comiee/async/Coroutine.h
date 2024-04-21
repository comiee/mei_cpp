#pragma once

#include "Promise.h"
#include "CoHandle.h"
#include "memory"

template<typename Y, typename R, typename I>
class Coroutine {
public:
    using promise_type = Promise<Y, R, I>;

    Coroutine(std::coroutine_handle<promise_type> handle) {
        co_handle = std::make_shared<CoHandle<promise_type>>(handle);
    }

    Coroutine(const Coroutine &co) = default;

    Coroutine &operator=(const Coroutine &) = default;

    bool operator==(const Coroutine &other) const {
        return co_handle == other.co_handle;
    }

    bool done() const {
        if (!co_handle) throw "co_handle为空";
        return co_handle->done();
    }

    void resume() const {
        if (!co_handle) throw "co_handle为空";
        co_handle->resume();
    }

    auto promise() const {
        if (!co_handle) throw "co_handle为空";
        return co_handle->promise();
    }

private:
    std::shared_ptr<CoHandle<promise_type>> co_handle;
};
