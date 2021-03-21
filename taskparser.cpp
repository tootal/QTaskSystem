#include "taskparser.h"

#include <QDir>
#include <QDebug>

#include "task.h"

Task *TaskParser::parse(const QString &path, Task *parent)
{
    Task *task = new Task(parent);
    QDir dir(path);
    task->label = dir.dirName();
    const QFileInfoList entryList = dir.entryInfoList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for (auto &entry : entryList) {
        QDir child(entry.absoluteFilePath());
        if (child.exists("task.json")) {
            parse(child.absolutePath(), task);
        }
    }
    return task;
}
