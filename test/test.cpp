#include <iostream>
#include "Client.h"

using namespace std;

void test_json_main();

int main() {
    cout << Client("demo").getName() << endl;

    test_json_main();
    return 0;
}
