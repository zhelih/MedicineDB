#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QtSql>

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
    
private:
    Ui::MainWindow *ui;
    QSqlDatabase* db2;
    QSqlTableModel* model_sql;
public slots:
    void open_table(QModelIndex);
    void sql_submit();
    void sql_revert();
    void sql_insert();//insert empty row into a table
    void sql_delete();//delete selected rows
};

#endif // MAINWINDOW_H
