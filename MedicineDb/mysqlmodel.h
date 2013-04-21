#ifndef MYSQLMODEL_H
#define MYSQLMODEL_H

#include <QtSql/QtSql>
#include "translate_load.h"

// simply map attributes to translations
class mySqlTableModel : public QSqlTableModel
{
private:
    translation *t;
public:
    mySqlTableModel(QObject* parent, QSqlDatabase db, translation *t_) : QSqlTableModel(parent, db) { t = t_; }
    QVariant headerData (int section, Qt::Orientation orientation = Qt::Horizontal, int role = Qt::DisplayRole) const
    {
        QVariant prev = QSqlTableModel::headerData(section, orientation, role);
        QString v = prev.toString();
        QString trans = (v!="")?t->get(v):"";
        if (trans == v)
            return prev;
        else
            return QVariant(trans);
    }
    QVariant realHeaderData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const
    {
        return QSqlTableModel::headerData(section, orientation, role);
    }
    QVariant::Type columnType(int i)
    {
        return record().field(i).type();
    }
};

#endif // MYSQLMODEL_H
