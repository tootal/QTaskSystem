#ifndef TASKSYSTEMMODEL_H
#define TASKSYSTEMMODEL_H

#include <QFileSystemModel>

class TaskSystemModel : public QFileSystemModel
{
    Q_OBJECT
    
public:
    explicit TaskSystemModel(QObject *parent = nullptr);
    
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif // TASKSYSTEMMODEL_H
