#include <iostream>
#include "Loop.h"

Loop::Loop(std::initializer_list<Task> tasks) : task_list(tasks) {

}

void Loop::add(const Task &task) {
    task_list.push_back(task);
}

void Loop::run(bool forever) {
    while(!task_list.empty() || forever){
        for(const auto& task:task_list){
            if(task.done()){
                task_list.remove(task);
                break;
            }
            task.resume();
        }
    }
}

size_t Loop::size() {
    return task_list.size();
}