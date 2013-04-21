#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QtSql>
#include <Qt>
#include <QTableView>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QtSql/QSqlError>

#include "translate_load.h"
#include "mysqlmodel.h"
#include "editdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    db2(0), inited(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

const char* table_names[] =
{
    "MEDICAL_INSTITUTION",
    "STAFF",
    "PATIENT",
    "CYCLE_OF_PATIENT",
    "MEDICAL_HISTORY",
    "APPLICATION_TIMETABLE",
    "SURVEY"
};

const int nr_table_names = sizeof(table_names)/sizeof(table_names[0]);

void MainWindow::set_database(QSqlDatabase* db_in) { db2 = db_in; }

void MainWindow::init()
{

/*    QStringList tables = db2->tables();
    QStandardItemModel* model = new QStandardItemModel(tables.length(),1,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(QString("Таблиці")));
    for(int i=0; i<tables.length();++i)
    {
        model->setItem(i,0,new QStandardItem(QString(tables[i])));
    }
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);

    model_sql = new QSqlTableModel(this, *db2);
    model_sql->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_2->setModel(model_sql);
*/
    t.reread();
    model_sql = new mySqlTableModel(this, *db2, &t);
    model_sql->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_sql->setTable(table_names[0]);
    ui->tableview_main->setModel(model_sql);
    ui->tableview_main->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    show_error();
    update_filter();
    ui->stackedWidget->setCurrentIndex(0);
    inited=true;
}

void MainWindow::show_error()
{
    if(model_sql->lastError().type() != QSqlError::NoError)
        emit statusBar()->showMessage(model_sql->lastError().text());
    else
        emit statusBar()->showMessage("OK");
}


void MainWindow::mode_maintables()
{
    emit ui->stackedWidget->setCurrentIndex(0);
    emit tab_changed(ui->tabs->currentIndex());
}
void MainWindow::mode_helpers()
{
    emit ui->stackedWidget->setCurrentIndex(1);
    model_sql->clear();
}

void MainWindow::myexit()
{
    //emit model_sql->revertAll();
    db2->close();
    emit close();
    emit QApplication::quit(); //unsafe
}

void MainWindow::tab_changed(int i)
{
    if(!inited) return;
    if(!(i < nr_table_names))
    {
        QMessageBox::critical(this, "Внутрішня помилка",
                              "Сталася непередбачувана внутрішня помилка програми.\n\
                               Зв\'яжіться з робробником для її усунення.\
                               \nКод помилки 1.");
        QApplication::exit(1);
        return;
    }
    QString table_name = table_names[i];
    model_sql->setTable(table_name);
    model_sql->select();
    ui->tableview_main->horizontalHeader()->reset();
    ui->tableview_main->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    show_error();
    emit ui->tableview_main->repaint();
    update_filter();
}

void MainWindow::update_filter()
{
    emit ui->comboBox->clear();
    ui->comboBox->addItem("<Пусто>");
    for(int i=0; i<model_sql->columnCount();++i)
        ui->comboBox->addItem(model_sql->headerData(i, Qt::Horizontal).toString());
}

void MainWindow::filter()
{
    QString filter = ui->lineEdit->text();
    int attr_index = ui->comboBox->currentIndex();
    if(filter != "" && attr_index > 0)
    {
        QVariant attr = model_sql->realHeaderData(attr_index - 1, Qt::Horizontal);
        //QString filter2 = (model_sql->columnType(attr_index - 1) == QVariant::String)?("'"+filter+"'"):filter;
        /* HACK */
        if (model_sql->columnType(attr_index - 1) == QVariant::UserType)
            QMessageBox::warning(this, "Warning", "Оторвите руки программисту");
        QString filter2 = ((attr.toString().toUpper()=="NAME")&&(model_sql->tableName()=="Unit"))?("Units(\'"+filter+"\')"):("\'"+filter+"\'");
        model_sql->setFilter(attr.toString() + "=" + filter2);
        if(model_sql->lastError().type() != QSqlError::NoError)
        {
            // Again HACK
            QString filter3 = " = LongName(\'"+filter2+"\')";
            model_sql->setFilter(attr.toString() + filter3);
        }
    }
    else
    {
        model_sql->setFilter("");
    }
    emit model_sql->select();
    show_error();
}

void MainWindow::about_devs()
{
    QMessageBox::about(this, "Про розробників", "Розроблено Лиховидом Євгеном та Связінською Наталією.\n(c) 2013, Всі права захищено законом.");
}

void MainWindow::about_qt()
{
    QMessageBox::aboutQt(this, "Про Qt");
}

void MainWindow::start_insert()
{
    EditDialog e(model_sql, -1, this);
    emit e.exec();
}

void MainWindow::start_edit()
{
    QModelIndexList l = ui->tableview_main->selectionModel()->selectedRows();
    if(l.length() == 0)
    {
        QMessageBox::warning(this, "Помилка", "Рядок не виділено, будь-ласка спробуйте ще раз.");
    }
    else
    {
        EditDialog e(model_sql, l.value(0).row(), this);
        emit e.exec();
    }
}

void MainWindow::set_mode(bool b)
{
    if(!b)
    {
        //disable edit mode
        emit ui->pushButton->setEnabled(false);
        emit ui->pushButton_2->setEnabled(false);
        emit ui->pushButton_3->setEnabled(false);
        emit ui->pushButton_5->setEnabled(false);
        emit ui->pushButton_6->setEnabled(false);
        emit ui->pushButton_7->setEnabled(false);
        emit ui->pushButton_8->setEnabled(false);
        emit ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        emit ui->tabs->tabBar()->setTabEnabled(2,false);
    }
}
