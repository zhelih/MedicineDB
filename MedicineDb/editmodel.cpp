#include "editmodel.h"
#include "mysqlmodel.h"
#include <QDate>
#include <QDateTime>
#include <QDateEdit>
#include <QMessageBox>

EditModel::EditModel(mySqlTableModel* m, int r, QObject *parent) :
    QAbstractTableModel(parent), row(r)
{
    model_sql = m;
    vars = new QVariant[model_sql->columnCount()]();
    if(r == -1)
        for (int i = 0; i < model_sql->columnCount(); ++i)
            vars[i] = model_sql->record().field(i).value();
    else
        for (int i = 0; i < model_sql->columnCount(); ++i)
            vars[i] = model_sql->record(r).field(i).value();
}

EditModel::~EditModel() { printf("editmodel destuctor really called\n"); delete [] vars; }

int EditModel::rowCount(const QModelIndex & parent = QModelIndex()) const
{
    return model_sql->columnCount();
}

int EditModel::columnCount(const QModelIndex & parent = QModelIndex()) const
{
    return 2;
}

QSqlRecord EditModel::record()
{
    QSqlRecord res(model_sql->record());
    for(int i=0; i < model_sql->columnCount(); ++i)
        /*if(vars[i].isNull())
            res.setNull(i);
        else*/
            res.setValue(i, vars[i]);
    return res;
}

QVariant EditModel::data(const QModelIndex & index, int role = Qt::DisplayRole) const
{
    if (role != Qt::DisplayRole && role != Qt::EditRole) return QVariant();
  //  QDate res = QDate::currentDate();
    if(index.column() == 0)
    {
        return QVariant(model_sql->headerData(index.row()));
    }
    return vars[index.row()];
}

QVariant EditModel::headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const
{
    if (role != Qt::DisplayRole) return QVariant();
    if (orientation != Qt::Horizontal) return QVariant();
    if (section == 0) return QVariant("Атрибут");
    else if (section == 1) return QVariant("Значення");
    return QVariant();
}

Qt::ItemFlags EditModel::flags(const QModelIndex & index) const
{
    if(index.column() == 0) return Qt::ItemIsEnabled;
    if(index.column() == 1) return Qt::ItemIsEditable | Qt::ItemIsEnabled;
    return Qt::NoItemFlags;
}

bool EditModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole)
    {
        vars[index.row()] = value;
        return true;
    }
    else
        return QAbstractItemModel::setData(index, value, role);
    return false;
}
