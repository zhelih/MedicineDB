#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QtSql>
#include <Qt>
#include <QTableView>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QtSql/QSqlError>

void MainWindow::open_table(QString table)
{
    mode_helpers();
    emit model_sql->revertAll();
    model_sql->setTable(table);
    model_sql->select();
    ui->tableView->setModel(model_sql);
    ui->tableView->horizontalHeader()->reset();
    ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    emit ui->tableView->repaint();
    current_table = table;
    show_error();
}

void MainWindow::sql_submit()
{
    emit model_sql->submitAll();
    if(model_sql->lastError().type() != (QSqlError::NoError))
    {
        QMessageBox::information(this, "Помилка", model_sql->lastError().text());
        emit model_sql->revertAll();
    }
}

void MainWindow::sql_revert()
{
    emit model_sql->revertAll();
}

void MainWindow::sql_insert()
{
    model_sql->insertRow(0);
    ui->tableView->horizontalHeader()->repaint();
}

void MainWindow::sql_delete()
{
    /* HACK TO USE IN BOTH DOVID'S AND MAIN'S TABLES */
    QModelIndexList indexes;
     if (ui->stackedWidget->currentIndex() == 1)
        indexes = ui->tableView->selectionModel()->selectedIndexes();
     else
        indexes = ui->tableview_main->selectionModel()->selectedIndexes();

    for (int i = 0; i < indexes.count(); ++i)
    {
        QModelIndex index = indexes.at(i);
        model_sql->removeRow(index.row());
    }
    if (ui->stackedWidget->currentIndex() == 0)
        emit model_sql->submitAll();
}

void MainWindow::procces_action1 ()
{
    open_table("DB2ADMIN.OPERATION_TYPE");
}

void MainWindow::procces_action2 ()
{
    open_table("DB2ADMIN.PATIENT_SERVICE");
}

void MainWindow::procces_action3 ()
{
    open_table("DB2ADMIN.SURVEY_OF_PATIENT");
}
void MainWindow::procces_action4 ()
{
    open_table("DB2ADMIN.SURVEY_TYPE");
}
void MainWindow::procces_action5 ()
{
    open_table("DB2ADMIN.TRACED_SURVEY");
}
void MainWindow::procces_action6 ()
{
    open_table("DB2ADMIN.UNIT");
}
void MainWindow::procces_action8 ()
{
    open_table("DB2ADMIN.OPERATION");
}
void MainWindow::procces_action9 ()
{
    open_table("DB2ADMIN.EQUIPMENT");
}
void MainWindow::procces_action10()
{
    open_table("DB2ADMIN.LEAVE");
}
void MainWindow::procces_action11()
{
    open_table("DB2ADMIN.ILLNESS_IN_HISTORY");
}
void MainWindow::procces_action12()
{
    open_table("DB2ADMIN.MEDICINE");
}
void MainWindow::procces_action13()
{
    open_table("DB2ADMIN.CUSTOM");
}
void MainWindow::procces_action14()
{
    open_table("DB2ADMIN.CONDITION");
}
void MainWindow::procces_action15()
{
    open_table("DB2ADMIN.SUPPLIER");
}
void MainWindow::procces_action16()
{
    open_table("DB2ADMIN.ILLNESS");
}
void MainWindow::procces_action17()
{
    open_table("DB2ADMIN.GIVEN_MEDICINE");
}
