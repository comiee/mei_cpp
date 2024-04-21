#include "tools.h"
#include "print.h"
#include <iostream>
#include <cassert>

using namespace std;

void testJoin() {
    uchar a = 'x';
    ulong b = 1;
    ullong c = 2;
    llong d = 3;
    println(stringJoin(",", a, b, c, d, "abc"));
}

void testSplit() {
    string s = "a,b,c";
    auto g = stringSplit(s, ',');
    for (auto x: g) {
        println(x);
    }
    println(g.done());
    assert(g.done() == true);
    g = stringSplit(s, ',');
    auto h = g;
    while (g) {
        println(g.next());
    }
    println(g.done(), h.done());
    assert(g.done() == true && h.done() == true);
    println(stringSplit(s, ',').toVector());
    println(stringSplit(s, ',', 0).toVector());
    println(stringSplit(s, ',', 1).toVector());
}

void testToolsMain() {
    testJoin();
    testSplit();
}

int main() {
    testToolsMain();
    return 0;
}