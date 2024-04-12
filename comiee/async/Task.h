#ifndef TASK_H
#define TASK_H

#include <queue>
#include <functional>
#include "Future.h"

class Task : public Future<void> {
public:
    Task(handle_type handle);
};


#endif //TASK_H
