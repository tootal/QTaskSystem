#ifndef TASK_H
#define TASK_H

#include <QObject>

class Task : public QObject
{
    Q_OBJECT
public:
    static const QString JSON_NAME;
    
    static const QString ICON_NAME;
    
    static const QString DIR_NAME;
    
    explicit Task(QObject *parent = nullptr);
    
    Task *parent() const;
    
    Task *child(int index) const;
    
    QString label;
    
    QString path;
};

#endif // TASK_H
