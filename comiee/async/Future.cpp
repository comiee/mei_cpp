#include "Future.h"

Future<void> asleep(time_t t) {
    time_t s = time(nullptr);
    while (time(nullptr) - s < t) {
        co_await std::suspend_always();
    }
}