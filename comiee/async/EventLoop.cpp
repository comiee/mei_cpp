#include "EventLoop.h"

void EventLoop::run() {
    while (!empty()) {
        if (get().done()) {
            del();
        } else {
            get().resume();
            next();
        }
    }
}