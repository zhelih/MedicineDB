#include "database.h"
#include <Qt>
#include <QtSql/QDB2Driver>
#include <QtSql/QDB2Result>
#include <QtSql/QtSql>
#include <QMessageBox>

void connectdb2()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QDB2"); //use db2 driver
    db.setHostName("127.0.0.1");
    db.setPort(50000);
    db.setDatabaseName("SAMPLE");
    db.setUserName("db2admin");
    db.setPassword("db2admin");

    if(!db.open())
    {
        QMessageBox::information(NULL, "Error", QString("Error: %1").arg(db.lastError().text()));
    } else
    {
        QMessageBox::information(NULL, "IBM DB2 driver inicialized", "Success");
      //  appLogger->Log(Logger::LOG_DRIVER, "Connected to " + db.connectionName());
    }
}
