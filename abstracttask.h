#ifndef ABSTRACTTASK_H
#define ABSTRACTTASK_H

#include <QObject>

class AbstractTask : public QObject
{
    Q_OBJECT
public:
    AbstractTask() {}
    virtual ~AbstractTask() {}
    
    virtual QString label() = 0;
};

#endif // ABSTRACTTASK_H
