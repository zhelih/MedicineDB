#define QT_NO_DEBUG_OUTPUT

#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QtSql/QDB2Driver>
#include <QtSql/QDB2Result>
#include <QtSql/QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int no_exit = 1;
    QSqlDatabase db = QSqlDatabase::addDatabase("QDB2"); //use db2 driver
    Dialog login_dialog(&db);

    if(login_dialog.exec())
    {
        login_dialog.close();
        w.set_database(&db);
        w.init();
        w.show();
        w.set_mode(login_dialog.get_mode());
    }
    else
    {
        no_exit = 0;
        a.exit();
    }
    return no_exit && a.exec();
}
