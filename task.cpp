#include "task.h"

const QString Task::JSON_NAME = "task.json";

const QString Task::DIR_NAME = "tasks";

const QString Task::ICON_NAME = "icon.svg";

bool Task::tryDelete(Task *&task)
{
    if (task) {
        delete task;
        task = nullptr;
        return true;
    } else {
        return false;
    }
}

Task::Task(Task *parent) : parent(parent)
{
    if (parent) {
        parent->children.append(this);
    }
}

Task::~Task()
{
    for (int i = 0; i < children.count(); ++i) {
        Task *currentChild = children.at(i);
        children[i] = 0;
        delete currentChild;
    }
    children.clear();
    
    tryDelete(windows);
    tryDelete(linux);
    tryDelete(osx);
}
