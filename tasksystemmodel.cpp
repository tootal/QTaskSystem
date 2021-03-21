#include "tasksystemmodel.h"

TaskSystemModel::TaskSystemModel(QObject *parent)
    : QFileSystemModel(parent)
{
    
}

int TaskSystemModel::rowCount(const QModelIndex &parent) const
{
    return QFileSystemModel::rowCount(parent);
}

int TaskSystemModel::columnCount(const QModelIndex &) const
{
    return 1;
}

QVariant TaskSystemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return QFileSystemModel::headerData(section, orientation, role);

    QString returnValue;
    switch (section) {
    case 0: returnValue = tr("Name");
            break;
    default: return QVariant();
    }
    return returnValue;
}
