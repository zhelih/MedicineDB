#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include "translate_load.h"
#include "mysqlmodel.h"
#include "procedurecall.h"

#define USER_PREFIX (QString("DB2ADMIN."))

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init();
    void set_database(QSqlDatabase*);
    void set_mode(int);
    
private:
    Ui::MainWindow *ui;
    QSqlDatabase* db2;
    mySqlTableModel* model_sql;
    translation t;
    void show_error();
    bool inited;
    void update_filter();
    void open_table(QString);
    QString current_table;
    ProcedureCall* p;

public slots:
    void mode_maintables();
    void mode_helpers();

    void sql_submit();
    void sql_revert();
    void sql_insert();//insert empty row into a table
    void sql_delete();//delete selected rows

    void myexit();

    void tab_changed(int);
    void filter();

    void about_devs();
    void about_qt();

    void start_insert();
    void start_edit();

    // dovid table's actions slots
    void procces_action1 ();
    void procces_action2 ();
    void procces_action3 ();
    void procces_action4 ();
    void procces_action5 ();
    void procces_action6 ();
    void procces_action8 ();
    void procces_action9 ();
    void procces_action10();
    void procces_action11();
    void procces_action12();
    void procces_action13();
    void procces_action14();
    void procces_action15();
    void procces_action16();
    void procces_action17();
    // procedures
    void procces_action18();
    void procces_action19();
    void procces_action20();
    void procces_action21();
    void procces_action22();
    void procces_action23();
};

#endif // MAINWINDOW_H
