#include "logindialog.h"
#include "ui_logindialog.h"

#include <QDialog>
#include <QtSql/QtSql>
#include <QMessageBox>

Dialog::Dialog(QSqlDatabase* db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ptr_db = db;
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::get_login()
{
    return ui->lineEdit->text();
}

QString Dialog::get_password()
{
    return ui->lineEdit_2->text();
}

void Dialog::accept()
{
    ptr_db->setHostName(ui->lineEdit_3->text());
    ptr_db->setPort(ui->lineEdit_4->text().toInt());
    ptr_db->setDatabaseName(ui->lineEdit_5->text());
    ptr_db->setUserName(ui->lineEdit->text());//blabla
    ptr_db->setPassword(ui->lineEdit_2->text());

    if(!ptr_db->open())
    {
        QMessageBox::information(this, "Error", QString("Error: %1").arg(ptr_db->lastError().text()));
    }
    else
        QDialog::accept();
}
