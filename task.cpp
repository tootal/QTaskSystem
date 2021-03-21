#include "task.h"

const QString Task::JSON_NAME = "task.json";

const QString Task::DIR_NAME = "tasks";

const QString Task::ICON_NAME = "icon.svg";

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
