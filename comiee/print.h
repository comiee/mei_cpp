#ifndef TEST23_COMIEE_H
#define TEST23_COMIEE_H

#include <iostream>
#include <vector>


template<typename T>
void print(const std::vector<T> &v) {
    std::cout << "vector(";
    for (const T &x: v) {
        std::cout << x;
        if (&x != &*v.rbegin()) {
            std::cout << ", ";
        }
    }
    std::cout << ")";
}

template<typename A, typename B>
void print(const std::pair<A, B> &v) {
    print("pair(", v.first, ", ", v.second, ")");
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

#endif //TEST23_COMIEE_H
