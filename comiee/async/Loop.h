#pragma once

#include <initializer_list>
#include <list>
#include "Task.h"

class [[maybe_unused]] Loop {
public:
    Loop() = default;

    Loop(std::initializer_list<Task> tasks);

    void add(const Task &task);

    void run(bool forever = false);

    size_t size();

private:
    std::list<Task> task_list;
};
