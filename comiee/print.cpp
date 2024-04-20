#include "print.h"

template<>
void printRepr<std::string>(std::string x) {
    std::cout << "\"" << x << "\"";
}