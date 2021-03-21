#ifndef TASKSYSTEMMODEL_H
#define TASKSYSTEMMODEL_H

#include <QAbstractItemModel>

class Task;

class TaskSystemModel : public QAbstractItemModel
{
    Q_OBJECT
    
public:
    explicit TaskSystemModel(QObject *parent = nullptr);
    ~TaskSystemModel();
    
    void setRootTask(Task *newRootTask);
    
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    
    QModelIndex parent(const QModelIndex &child) const override;
    
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    
private:
    Task *taskFromIndex(const QModelIndex &index) const;
    
    Task *rootTask;
};

#endif // TASKSYSTEMMODEL_H
