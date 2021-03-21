#include "taskparser.h"

#include <QDir>
#include <QDebug>

#include "task.h"

Task *TaskParser::parse(const QString &path, Task *parent)
{
    Task *task = new Task(parent);
    QDir dir(path);
    task->path = path;
    task->label = dir.dirName();
    const QFileInfoList entryList = dir.entryInfoList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for (auto &entry : entryList) {
        QDir child(entry.absoluteFilePath());
        if (child.exists(Task::JSON_NAME)) {
            parse(child.absolutePath(), task);
        }
    }
    return task;
}
