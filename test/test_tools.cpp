#include "tools.h"
#include "print.h"
#include <iostream>

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
    auto v = stringSplit(s, ',').toVector();
    println(v.size());
    for (auto x: v) {
        println(x);
    }
    println(stringSplit(s, ',').toVector());
    println(stringSplit(s, ',', 0).toVector());
    println(stringSplit(s, ',', 1).toVector());
}

void testToolsMain() {
    testJoin();
    testSplit();
}