#ifndef TASK_H
#define TASK_H

#include <QObject>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    
    Task(const QString &label, QObject *parent = nullptr);
    
    QString label() const;

private:
    QString m_label;
};

#endif // TASK_H
