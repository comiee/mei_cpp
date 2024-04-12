#include "Client.h"
#include "log.h"

using namespace std;

void testJsonMain();
void testToolsMain();
void testMessageMain();
void testAsyncMain();

int main() {
    Logger logger("test", Logger::DEBUG);
    logger.debug("%s", Client("demo").getName().c_str());

    testJsonMain();
    testToolsMain();
    testMessageMain();
    testAsyncMain();

    logger.info("test end");
    return 0;
}
