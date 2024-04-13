#pragma once

#include "LoopQueue.h"
#include "Task.h"


class EventLoop : public LoopQueue<Task> {
public:
    void run();
};