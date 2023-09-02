#include <iostream>
#include "Client.h"

void test_json_main();

int main() {
    cout << Client("demo").getName() << endl;

    test_json_main();
    return 0;
}
