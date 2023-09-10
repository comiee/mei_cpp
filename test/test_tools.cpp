#include "tools.h"
#include <iostream>

using namespace std;

void testJoin() {
    uchar a = 'x';
    ulong b = 1;
    ullong c = 2;
    llong d = 3;
    cout << stringJoin(",", a, b, c, d, "abc") << endl;
}

void testToolsMain() {
    testJoin();
}