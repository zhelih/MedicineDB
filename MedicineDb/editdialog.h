#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QtSql/QtSql>

#include "ui_editdialog.h"
#include "editmodel.h"
#include "mysqlmodel.h"
#include "mysqlmodel.h"
#include "calendardelegate.h"

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(mySqlTableModel*, int, QWidget *parent = 0);
    ~EditDialog();

private:
    Ui::EditDialog *ui;
    EditModel* editmodel;
    mySqlTableModel* model_sql;
    int row_;
    CalendarDelegate *cal;
public slots:
    virtual void accept();
};

#endif // EDITDIALOG_H
