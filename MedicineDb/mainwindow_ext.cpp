#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendardelegate.h"
#include <QtSql/QtSql>
#include <Qt>
#include <QTableView>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QtSql/QSqlError>
#include <QInputDialog>

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
    ui->tableView->setItemDelegate(new CalendarDelegate());
    show_error();
}

void MainWindow::sql_submit()
{
    emit model_sql->submitAll();
    if(model_sql->lastError().type() != (QSqlError::NoError))
    {
        QMessageBox::critical(this, "Помилка", model_sql->lastError().text());
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
    open_table(USER_PREFIX+"OPERATION_TYPE");
}

void MainWindow::procces_action2 ()
{
    open_table(USER_PREFIX+"PATIENT_SERVICE");
}

void MainWindow::procces_action3 ()
{
    open_table(USER_PREFIX+"SURVEY_OF_PATIENT");
}
void MainWindow::procces_action4 ()
{
    open_table(USER_PREFIX+"SURVEY_TYPE");
}
void MainWindow::procces_action5 ()
{
    open_table(USER_PREFIX+"TRACED_SURVEY");
}
void MainWindow::procces_action6 ()
{
    open_table(USER_PREFIX+"UNIT");
}
void MainWindow::procces_action8 ()
{
    open_table(USER_PREFIX+"OPERATION");
}
void MainWindow::procces_action9 ()
{
    open_table(USER_PREFIX+"EQUIPMENT");
}
void MainWindow::procces_action10()
{
    open_table(USER_PREFIX+"LEAVE");
}
void MainWindow::procces_action11()
{
    open_table(USER_PREFIX+"ILLNESS_IN_HISTORY");
}
void MainWindow::procces_action12()
{
    open_table(USER_PREFIX+"MEDICINE");
}
void MainWindow::procces_action13()
{
    open_table(USER_PREFIX+"CUSTOM");
}
void MainWindow::procces_action14()
{
    open_table(USER_PREFIX+"CONDITION");
}
void MainWindow::procces_action15()
{
    open_table(USER_PREFIX+"SUPPLIER");
}
void MainWindow::procces_action16()
{
    open_table(USER_PREFIX+"ILLNESS");
}
void MainWindow::procces_action17()
{
    open_table(USER_PREFIX+"GIVEN_MEDICINE");
}

// procedures
void MainWindow::procces_action18()
{
    bool ok;
    int id = QInputDialog::getInt(this, "Введення даних", "id Медичного закладу:", 0, -2147483647, 2147483647, 1, &ok);
    if(ok)
    {
        id = p->total_patients(id);
        QMessageBox::information(this, "Результат", "Кількість прийнятих пацієнтів: " + QString::number(id));
    }
}

void MainWindow::procces_action19()
{
    bool ok;
    int id = QInputDialog::getInt(this, "Введення даних", "id Медичного закладу:", 0, -2147483647, 2147483647, 1, &ok);
    if(ok)
    {
        id = p->total_costs(id);
        QMessageBox::information(this, "Результат", "Витрати: " + QString::number(id));
    }
}

void MainWindow::procces_action20()
{
    bool ok;
    int id = QInputDialog::getInt(this, "Введення даних", "Зміна зарплати:", 0, -2147483647, 2147483647, 1, &ok);
    if(ok)
    {
        p->increase_salary(id);
    }
}

void MainWindow::procces_action21()
{
    p->remove_empty_medicine();
}

void MainWindow::procces_action22()
{
    p->remove_old_contracts();
}

/*
QList<ill> illness(int);
*/
