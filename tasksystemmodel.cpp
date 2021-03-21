#include "tasksystemmodel.h"

#include <QDebug>
#include <QDir>
#include <QIcon>
#include <QSvgRenderer>
#include <QPixmap>
#include <QPainter>

#include "task.h"

TaskSystemModel::TaskSystemModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    rootTask = nullptr;
}

TaskSystemModel::~TaskSystemModel()
{
    if (rootTask) delete rootTask;
}

void TaskSystemModel::setRootTask(Task *newRootTask)
{
    if (rootTask) delete rootTask;
    rootTask = newRootTask;
}

QModelIndex TaskSystemModel::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || column < 0 || row >= rowCount(parent) || column >= columnCount(parent))
        return QModelIndex();
    
    Task *parentTask = taskFromIndex(parent);
    Task *childTask = parentTask->child(row);
    Q_ASSERT(childTask);

    return createIndex(row, column, childTask);
}

QModelIndex TaskSystemModel::parent(const QModelIndex &child) const
{
    Task *childTask = taskFromIndex(child);
    if (!childTask) return QModelIndex();
    Task *parentTask = childTask->parent();
    if (!parentTask) return QModelIndex();
    Task *grandparentTask = parentTask->parent();
    if (!grandparentTask) return QModelIndex();
    int row = grandparentTask->children().indexOf(parentTask);
    return createIndex(row, 0, parentTask);
}

int TaskSystemModel::rowCount(const QModelIndex &parent) const
{
    Task *parentTask = taskFromIndex(parent);
    if (!parentTask) return 0;
    return parentTask->children().size();
}

int TaskSystemModel::columnCount(const QModelIndex &) const
{
    return 1;
}

QVariant TaskSystemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (section) {
    case 0: 
        return tr("Name");
    default: 
        return QVariant();
    }
}

Task *TaskSystemModel::taskFromIndex(const QModelIndex &index) const
{
    if (index.isValid()) {
        Task *task = static_cast<Task*>(index.internalPointer());
        return task;
    } else {
        return rootTask;
    }
}

QIcon TaskSystemModel::iconFromIndex(const QModelIndex &index) const
{
    Task *task = taskFromIndex(index);
    QDir dir(task->path);
    if (!dir.exists(Task::ICON_NAME)) {
        return QIcon();
    }
    QString path = dir.absoluteFilePath(Task::ICON_NAME);
    QSvgRenderer renderer(path);
    QPixmap pixmap(32, 32);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    renderer.render(&painter, pixmap.rect());
    return QIcon(pixmap);
}

QVariant TaskSystemModel::data(const QModelIndex &index, int role) const
{
    Task *task = taskFromIndex(index);
    switch (role) {
    case Qt::EditRole:
    case Qt::DisplayRole:
        switch (index.column()) {
        case 0: return task->label;
        default:
            qWarning("data: invalid display value column %d", index.column());
            break;
        }
        break;
    case Qt::DecorationRole:
        switch (index.column()) {
        case 0: return iconFromIndex(index);
        default:
            qWarning("data: invalid decorate value column %d", index.column());
            break;
        }
        break;
    }
    return QVariant();
}
