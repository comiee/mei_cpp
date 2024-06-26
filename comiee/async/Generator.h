#pragma once

#include "Coroutine.h"
#include <vector>

template<typename Y>
class Generator : public Coroutine<Y, void, std::suspend_never> {
public:
    class value_ptr : public std::iterator<std::forward_iterator_tag, Y> {
    public:
        value_ptr(Generator generator) : generator(generator) {
        }

        value_ptr &operator++() {
            generator.resume();
            return *this;
        }

        bool operator!=(const value_ptr &) {
            return !generator.done();
        }

        Y operator*() {
            return generator.get();
        }

        Generator generator;
    };

    Generator(auto handle) : Coroutine<Y, void, std::suspend_never>(handle) {
    }

    value_ptr begin() {
        return *this;
    }

    value_ptr end() {
        return *this;
    }

    Y get() {
        return this->promise().get_yield_value();
    }

    Y next() { // 不能用return *++begin();，否则当没有元素时代码还没有执行完，生成器不会done
        Y temp = get();
        this->resume();
        return temp;
    }

    bool empty() {
        return this->done();
    }

    operator bool() {
        return !empty();
    }

    std::vector<Y> toVector() { // 不可以用vector<Y>{begin(),end()}，vector的构造函数中会多次遍历迭代器
        std::vector<Y> res;
        for (const Y &x: *this) {
            res.push_back(x);
        }
        return res;
    }
};

#define YIELD_FROM(ge) \
for(auto x:ge){        \
    co_yield x;        \
}
