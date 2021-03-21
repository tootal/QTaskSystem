#ifndef TASK_H
#define TASK_H

#include <QObject>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    
    Task *parent() const;
    
    Task *child(int index) const;
    
    QString label;
};

#endif // TASK_H
