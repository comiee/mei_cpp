#ifndef PROMISE_H
#define PROMISE_H

#include <coroutine>

template<typename Y, typename R, typename I=std::suspend_never>
class Promise {
public:
    std::suspend_always yield_value(Y v) {
        yieldValue = v;
        return {};
    }

    void return_value(R v) {
        returnValue = v;
    }

    I initial_suspend() {
        return {};
    }

    std::suspend_always final_suspend() noexcept {
        return {};
    }

    auto get_return_object() {
        return std::coroutine_handle<Promise<Y, R, I>>::from_promise(*this);
    }

    void unhandled_exception() {
    }

    Y get_yield_value() {
        return yieldValue;
    }

    R get_return_value() {
        return returnValue;
    }

private:
    Y yieldValue;
    R returnValue;
};

template<typename Y, typename I>
class Promise<Y, void, I> {
public:
    std::suspend_always yield_value(Y v) {
        yieldValue = v;
        return {};
    }

    void return_void() {
    }

    I initial_suspend() {
        return {};
    }

    std::suspend_always final_suspend() noexcept {
        return {};
    }

    auto get_return_object() {
        return std::coroutine_handle<Promise<Y, void, I>>::from_promise(*this);
    }

    void unhandled_exception() {
    }

    Y get_yield_value() {
        return yieldValue;
    }

private:
    Y yieldValue;
};

template<typename R, typename I>
class Promise<void, R, I> {
public:
    void return_value(R v) {
        returnValue = v;
    }

    I initial_suspend() {
        return {};
    }

    std::suspend_always final_suspend() noexcept {
        return {};
    }

    auto get_return_object() {
        return std::coroutine_handle<Promise<void, R, I>>::from_promise(*this);
    }

    void unhandled_exception() {
    }

    R get_return_value() {
        return returnValue;
    }

private:
    R returnValue;
};

template<typename I>
class Promise<void, void, I> {
public:
    void return_void() {
    }

    I initial_suspend() {
        return {};
    }

    std::suspend_always final_suspend() noexcept {
        return {};
    }

    auto get_return_object() {
        return std::coroutine_handle<Promise<void, void, I>>::from_promise(*this);
    }

    void unhandled_exception() {
    }
};

#endif //PROMISE_H
