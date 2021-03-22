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

Task::Task(Task *parent, Task::Kind kind)
    : parent(parent), kind(kind)
{
    if (!parent) return ;
    switch (kind) {
    case Node:
        parent->children.append(this);
        break;
    case Windows:
        tryDelete(parent->windows);
        parent->windows = this;
        break;
    case Linux:
        tryDelete(parent->linux);
        parent->linux = this;
        break;
    case Osx:
        tryDelete(parent->osx);
        parent->osx = this;
        break;
    default:
        break;
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
