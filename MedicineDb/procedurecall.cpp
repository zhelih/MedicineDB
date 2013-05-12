#include "procedurecall.h"
#include <QtSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>

ProcedureCall::ProcedureCall(QSqlDatabase* db_in)
{
    db=db_in;
}

int ProcedureCall::total_patients(int id)
{
    QSqlQuery query("SELECT db2admin.total_patients("+ QString::number(id) + ") FROM sysibm.sysdummy1", *db);
    query.exec();
    qDebug("performig query : %s", qPrintable(query.lastQuery()));
    if(query.lastError().type() != QSqlError::NoError)
        QMessageBox::critical(0, "Помилка", query.lastError().text());
    int res;
    if(query.next())
        res = query.value(0).toInt();
    else
        res = 0;
    query.clear();
    return res;
}

int ProcedureCall::total_costs(int id)
{
    QSqlQuery query("SELECT db2admin.total_costs("+ QString::number(id) + ") FROM sysibm.sysdummy1", *db);
    query.exec();
    qDebug("performig query : %s", qPrintable(query.lastQuery()));
    if(query.lastError().type() != QSqlError::NoError)
        QMessageBox::critical(0, "Помилка", query.lastError().text());
    int res;
    if(query.next())
        res = query.value(0).toInt();
    else
        res = 0;
    query.clear();
    return res;
}

QList<ill> ProcedureCall::illness(int id)
{
    QSqlQuery query("select t.Illness, t.Date_of_admission, t.Date_of_leaving from table(db2admin.illnesses(" + QString::number(id) + ")) as t", *db);
    query.exec();
    qDebug("performig query : %s", qPrintable(query.lastQuery()));
    if(query.lastError().type() != QSqlError::NoError)
        QMessageBox::critical(0, "Помилка", query.lastError().text());
    QList<ill> res;
    while(query.next())
    {
        ill i;
        i.illness = query.value(0).toString();
        i.adm = query.value(1).toDate();
        i.leave = query.value(2).toDate();
        res.append(i);
    }
    return res;
}

void ProcedureCall::increase_salary(int diff)
{
    QSqlQuery query("CALL db2admin.increase_salary("+ QString::number(diff) + ")", *db);
    query.exec();
    qDebug("performig query : %s", qPrintable(query.lastQuery()));
    if(query.lastError().type() != QSqlError::NoError)
        QMessageBox::critical(0, "Помилка", query.lastError().text());
    else
        QMessageBox::information(0, "Інформація", "Виконано");
    query.clear();
}

void ProcedureCall::remove_old_contracts()
{
    QSqlQuery query("CALL db2admin.remove_old_contracts()", *db);
    query.exec();
    qDebug("performig query : %s", qPrintable(query.lastQuery()));
    if(query.lastError().type() != QSqlError::NoError)
        QMessageBox::critical(0, "Помилка", query.lastError().text());
    else
        QMessageBox::information(0, "Інформація", "Виконано");
    query.clear();
}

void ProcedureCall::remove_empty_medicine()
{
    QSqlQuery query("CALL db2admin.remove_empty_medicine()", *db);
    query.exec();
    qDebug("performig query : %s", qPrintable(query.lastQuery()));
    if(query.lastError().type() != QSqlError::NoError)
        QMessageBox::critical(0, "Помилка", query.lastError().text());
    else
        QMessageBox::information(0, "Інформація", "Виконано");
    query.clear();
}
