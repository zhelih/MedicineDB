#include "editdialog.h"
#include "ui_editdialog.h"
#include "editmodel.h"
#include "mysqlmodel.h"
#include "calendardelegate.h"

#include <QDialog>
#include <QtSql/QtSql>
#include <QMessageBox>
#include <QDateEdit>

EditDialog::EditDialog(mySqlTableModel* m, int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    editmodel = new EditModel(m, row, this);
    ui->tableView->setModel(editmodel);
    ui->tableView->horizontalHeader()->reset();
    //QHeaderView::Resi
    //ui->tableView->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    emit ui->tableView->repaint();

    model_sql = m;
    QDateEdit* edit = new QDateEdit(parent);
    edit->setCalendarPopup(true);

    for(int i = 0; i < editmodel->rowCount(); ++i)
        if(editmodel->data(editmodel->index(i,1),Qt::DisplayRole).type() == QVariant::Date)
        {
            QDateEdit* edit = new QDateEdit(parent);
            edit->setCalendarPopup(true);
            edit->setAutoFillBackground(true);
            if(row == -1)
                edit->setDate(QDate::currentDate());
            else
                edit->setDate(editmodel->data(editmodel->index(i,1),Qt::DisplayRole).toDate());
            //ui->tableView->setIndexWidget(editmodel->index(i,1), edit);
            ui->tableView->setItemDelegateForRow(i, new CalendarDelegate());
            ui->tableView->update(editmodel->index(i,1));
        }
            //ui->tableView->indexAt(QPoint(i,1));
            //ui->tableView->it
            //ui->tableView->setItemDelegateForRow(i, cal);
    row_ = row;
}

EditDialog::~EditDialog()
{
    delete editmodel;
    delete ui;
}

void EditDialog::accept()
{
    QSqlRecord r = editmodel->record();
    if(r.isEmpty())
        return;
    bool ok = false;
    if(row_ == -1)
        ok = model_sql->insertRecord(-1, r);
    else
        ok = model_sql->setRecord(row_, r);
    qDebug() << "inserting record " << r << endl;

    if(!ok)
    {
        QMessageBox::critical(this, "Помилка при вставці", model_sql->lastError().text());
        emit model_sql->revertAll();
        emit editmodel->revert();
    }
    else
    {
        if(!model_sql->submitAll())
        {
            QMessageBox::critical(this, "Помилка при з'єднанні с базою", model_sql->lastError().text());
            emit model_sql->revertAll();
            emit editmodel->revert();

        }
        else
            QDialog::accept();
    }
}
