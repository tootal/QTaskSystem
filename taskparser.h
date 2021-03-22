#ifndef TASKPARSER_H
#define TASKPARSER_H

#include <QString>
#include <QJsonDocument>

class Task;

class TaskParser
{
    struct Options {
        Task *parent;
        QString path;
        Options() {
            parent = nullptr;
        }
    };

public:
    static Task *parse(const QString &path, Task *parent = nullptr);
    
    static Task *parseJson(const QJsonDocument &json, const Options &options);
};

#endif // TASKPARSER_H
