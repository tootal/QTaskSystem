#include "task.h"

Task::Task(QObject *parent) : QObject(parent)
{
    
}

Task::Task(const QString &label, QObject *parent)
    : QObject(parent), m_label(label)
{
    
}

QString Task::label() const
{
    return m_label;
}
