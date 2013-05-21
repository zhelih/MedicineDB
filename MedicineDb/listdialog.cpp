#include "listdialog.h"
#include "ui_listdialog.h"
#include "procedurecall.h"

ListDialog::ListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListDialog)
{
    ui->setupUi(this);
}

void ListDialog::setData(QList<ill> l)
{
    QList<ill>::Iterator i;
    int j;
    j=0;
    ui->tableWidget->setRowCount(l.size());
    for(i=l.begin(); i!=l.end(); ++i,++j)
    {
        //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(j,0,new QTableWidgetItem((*i).illness));
        ui->tableWidget->setItem(j,1,new QTableWidgetItem((*i).adm.toString()));
        ui->tableWidget->setItem(j,2,new QTableWidgetItem((*i).leave.toString()));
     }
}

ListDialog::~ListDialog()
{
    delete ui;
}
