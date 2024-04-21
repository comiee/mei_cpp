#pragma once

#include <queue>
#include <functional>
#include "Future.h"

class Task : public Future<void> {
public:
    Task(handle_type handle);
};
