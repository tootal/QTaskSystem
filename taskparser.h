#ifndef TASKPARSER_H
#define TASKPARSER_H

#include <QString>

class Task;

class TaskParser
{
public:
    static Task *parse(const QString &path, Task *parent = nullptr);
};

#endif // TASKPARSER_H
