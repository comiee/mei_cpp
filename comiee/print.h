#pragma once

#include <iostream>
#include <vector>

template<typename T>
void printRepr(T x) {
    std::cout << x;
}

template<>
void printRepr<std::string>(std::string x);

template<typename T>
void print(const std::vector<T> &v) {
    std::cout << "vector(";
    for (const T &x: v) {
        printRepr(x);
        if (&x != &*v.rbegin()) {
            std::cout << ", ";
        }
    }
    std::cout << ")";
}

template<typename A, typename B>
void print(const std::pair<A, B> &v) {
    std::cout << "pair(" << v.first << ", " << v.second << ")";
}

template<typename T>
void print(T x) {
    std::cout << x;
}

template<typename T, typename...Args>
void print(T x, Args...args) {
    print(x);
    std::cout << ", ";
    print(args...);
}

template<typename...Args>
void println(Args...args) {
    print(args...);
    std::cout << std::endl;
}

#define PRINT_FUN(...) println(__FUNCTION__, __LINE__, ##__VA_ARGS__)
