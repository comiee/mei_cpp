#include <iostream>
#include "Client.h"
#include "log.h"

using namespace std;

void testJsonMain();
void testToolsMain();

int main() {
    Logger logger("test", Logger::DEBUG);
    logger.debug(Client("demo").getName());

    testJsonMain();
    testToolsMain();

    logger.info("test end");
    return 0;
}
