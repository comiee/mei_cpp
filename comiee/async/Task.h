#pragma once

#include <queue>
#include <functional>
#include "Future.h"

class Task : public Future<void> {
public:
    Task(auto handle) : Future<void>(handle) {
    }
};
