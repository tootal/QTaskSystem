#ifndef TASKFILEMODEL_H
#define TASKFILEMODEL_H

#include <QAbstractItemModel>
#include <QJsonDocument>

class TaskFileModel : public QAbstractItemModel
{
    Q_OBJECT
    
public:
    TaskFileModel(QObject *parent);
    
    QString fileName() const;
    
    void setFileName(const QString &newFileName);
    
    QModelIndex index(int row, 
                      int column, 
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    
    QVariant data(const QModelIndex &index, 
                  int role = Qt::DisplayRole) const override;
    
    bool setData(const QModelIndex &index, 
                 const QVariant &value, 
                 int role = Qt::EditRole) override;
    
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    
private:
    QString m_fileName;
    
    QJsonDocument m_json;
};

#endif // TASKFILEMODEL_H
