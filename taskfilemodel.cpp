#include "taskfilemodel.h"

#include <QFile>
#include <QDebug>

TaskFileModel::TaskFileModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    
}

QString TaskFileModel::fileName() const
{
    return m_fileName;
}

void TaskFileModel::setFileName(const QString &newFileName)
{
    m_fileName = newFileName;
    QFile file(m_fileName);
    if (!file.open(QIODevice::ReadOnly)) return ;
    auto data = file.readAll();
    file.close();
    
    QJsonParseError e;
    m_json = QJsonDocument::fromJson(data, &e);
    
    if (e.error != QJsonParseError::NoError) {
        qDebug() << e.errorString();
    }
}

QModelIndex TaskFileModel::index(int row, 
                                 int column, 
                                 const QModelIndex &parent) const
{
    return QModelIndex();
}

QModelIndex TaskFileModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int TaskFileModel::rowCount(const QModelIndex &parent) const
{
    return 0;
}

int TaskFileModel::columnCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant TaskFileModel::data(const QModelIndex &index, 
                             int role) const
{
    return QVariant();
}

bool TaskFileModel::setData(const QModelIndex &index, 
                            const QVariant &value, 
                            int role)
{
    return QAbstractItemModel::setData(index, value, role);
}

Qt::ItemFlags TaskFileModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index);
}
