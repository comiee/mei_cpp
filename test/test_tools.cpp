#include "tools.h"
#include <iostream>

using namespace std;

void testJoin() {
    cout << stringJoin(",", 1, "abc") << endl;
}

void testToolsMain() {
    testJoin();
}