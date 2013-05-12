#ifndef PROCEDURECALL_H
#define PROCEDURECALL_H
#include <QtSql>
#include <QtSql/QSqlDatabase>

struct ill
{
    QString illness;
    QDate adm;
    QDate leave;
};

class ProcedureCall
{
private:
    QSqlDatabase* db;
public:
    ProcedureCall(QSqlDatabase*);
    int total_patients(int);
    int total_costs(int);
    QList<ill> illness(int);
    void increase_salary(int);
    void remove_old_contracts();
    void remove_empty_medicine();
};

#endif // PROCEDURECALL_H
