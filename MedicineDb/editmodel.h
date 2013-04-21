#ifndef EDITMODEL_H
#define EDITMODEL_H

#include <QAbstractTableModel>
#include <QVariant>
#include "mysqlmodel.h"

class EditModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    mySqlTableModel* model_sql;
    int row;
    QVariant* vars;
    QWidget* father;
public:
    explicit EditModel(mySqlTableModel*, int row, QWidget *parent = 0);
    int rowCount(const QModelIndex&) const;
    int columnCount(const QModelIndex&) const;
    QVariant data(const QModelIndex&, int) const;
    QVariant headerData(int, Qt::Orientation, int) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex&) const;
    QSqlRecord record();
    ~EditModel();
    
signals:
    
public slots:
    
};

#endif // EDITMODEL_H
