#include "editdialog.h"
#include "ui_editdialog.h"
#include "editmodel.h"
#include "mysqlmodel.h"

#include <QDialog>
#include <QtSql/QtSql>
#include <QMessageBox>

EditDialog::EditDialog(mySqlTableModel* m, int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    editmodel = new EditModel(m, row);
    ui->tableView->setModel(editmodel);
    model_sql = m;
    row_ = row;
}

EditDialog::~EditDialog()
{
    delete editmodel;
    delete ui;
}

void EditDialog::accept()
{
    if(row_ == -1)
        model_sql->insertRecord(-1, editmodel->record());
    else
        model_sql->setRecord(row_, editmodel->record());

    if(model_sql->lastError().type() != QSqlError::NoError)
    {
        QMessageBox::critical(this, "Помилка при вставці", model_sql->lastError().text());
        emit model_sql->revertAll();
    }
    else
    {
        model_sql->submitAll();
        if(model_sql->lastError().type() != QSqlError::NoError)
        {
            QMessageBox::critical(this, "Помилка при з'єднанні с базою", model_sql->lastError().text());
            emit model_sql->revertAll();
        }
        else
            QDialog::accept();
    }
}
