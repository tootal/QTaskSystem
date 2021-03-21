#include "task.h"

Task::Task(QObject *parent) : QObject(parent)
{
    
}

Task *Task::parent() const
{
    return qobject_cast<Task*>(QObject::parent());
}

Task *Task::child(int index) const
{
    return qobject_cast<Task*>(QObject::children().at(index));
}
