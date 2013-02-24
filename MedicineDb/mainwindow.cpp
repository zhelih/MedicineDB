#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QtSql>
#include <Qt>
#include <QTableView>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QtSql/QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    db2(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_database(QSqlDatabase* db_in) { db2 = db_in; }

void MainWindow::init()
{
    QStringList tables = db2->tables();
    QStandardItemModel* model = new QStandardItemModel(tables.length(),1,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(QString("Tables")));
    for(int i=0; i<tables.length();++i)
    {
        model->setItem(i,0,new QStandardItem(QString(tables[i])));
    }
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);

    model_sql = new QSqlTableModel(this, *db2);
    model_sql->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_2->setModel(model_sql);
}

void MainWindow::open_table(QModelIndex i)
{
    model_sql->setTable(i.data().toString());
    model_sql->select();
    ui->tableView_2->horizontalHeader()->reset();
    ui->tableView_2->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    emit ui->tableView_2->repaint();
}

void MainWindow::sql_submit()
{
    emit model_sql->submitAll();
    if(model_sql->lastError().type() != (QSqlError::NoError))
    {
        QMessageBox::information(this, "Error", model_sql->lastError().text());
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
    ui->tableView_2->horizontalHeader()->repaint();
}

void MainWindow::sql_delete()
{
    QModelIndexList indexes = ui->tableView_2->selectionModel()->selectedIndexes();
    for (int i = 0; i < indexes.count(); ++i)
    {
        QModelIndex index = indexes.at(i);
        model_sql->removeRow(index.row());
    }
}
