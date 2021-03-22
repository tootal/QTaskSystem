#include "taskparser.h"

#include <QDir>
#include <QDebug>

#include "task.h"

Task *TaskParser::parse(const QString &path, Task *parent)
{
    Task *task = nullptr;
    QDir dir(path);
    if (dir.exists(Task::JSON_NAME)) {
        Options options;
        options.parent = parent;
        options.path = path;
        QFile file(dir.absoluteFilePath(Task::JSON_NAME));
        if (file.open(QFile::ReadOnly)) {
            task = parseJson(QJsonDocument::fromJson(file.readAll()), options);
            file.close();
        }
    }
    if (task == nullptr) {
        task = new Task(parent);
    }
    const QFileInfoList entryList = dir.entryInfoList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for (auto &entry : entryList) {
        QDir child(entry.absoluteFilePath());
        if (child.exists(Task::JSON_NAME)) {
            parse(child.absolutePath(), task);
        }
    }
    return task;
}

Task *TaskParser::parseJson(const QJsonDocument &json, const TaskParser::Options &options)
{
    if (!json.isObject()) return nullptr;
    
}
