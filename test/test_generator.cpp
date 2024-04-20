#include "Generator.h"
#include "print.h"

Generator<int> f(){
    co_yield 1;
    co_yield 2;
    co_yield 3;
}

Generator<int> g(){
    YIELD_FROM(f());
}

int main() {
    println(g().toVector());
    return 0;
}