#ifndef GENERATOR_H
#define GENERATOR_H

#include "Promise.h"

template<typename Y>
class Generator {
public:
    using promise_type = Promise<Y, void>;
    using handle_type = std::coroutine_handle<promise_type>;

    class value_ptr {
    public:
        value_ptr(handle_type handle) : handle(handle) {

        }

        value_ptr &operator++() {
            if (handle.done()) {
                throw CustomException("生成器已停止");
            }
            handle.resume();
            return *this;
        }

        bool operator!=(const value_ptr &) {
            return !handle.done();
        }

        Y operator*() {
            return handle.promise().get_yield_value();
        }

    private:
        handle_type handle;
    };

    Generator(handle_type handle) : handle(handle) {
    }

    Generator(const Generator &) = delete;

    Generator(Generator &&co) noexcept: handle(co.handle) {
        co.handle = nullptr;
    }

    ~Generator() {
        if (handle) {
            handle.destroy(); //注意如果定义了拷贝构造，这里会出问题
        }
    }

    Generator &operator=(const Generator &) = delete;

    Generator &operator=(Generator &&co) noexcept {
        handle = co.handle;
        co.handle = nullptr;
        return *this;
    }

    value_ptr begin() {
        return {handle};
    }

    value_ptr end() {
        return {handle};
    }

    Y get() {
        return *begin();
    }

    Y next() {
        return *++begin();
    }

private:
    handle_type handle;
};

#endif //GENERATOR_H
