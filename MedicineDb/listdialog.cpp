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
    ui->tableWidget->clearContents();
    // remove all rows, no auto
    for(j=0; j < ui->tableWidget->rowCount(); ++j)
        ui->tableWidget->removeRow(j);
    j=0;
    for(i=l.begin(); i!=l.end(); ++i,++j)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->item(j,0)->setText((*i).illness);
        ui->tableWidget->item(j,1)->setData(Qt::DisplayRole, (*i).adm);
        ui->tableWidget->item(j,2)->setData(Qt::DisplayRole, (*i).leave);
     }
}

ListDialog::~ListDialog()
{
    delete ui;
}
