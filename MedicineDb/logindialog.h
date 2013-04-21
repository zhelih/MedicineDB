#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QtSql/QtSql>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QSqlDatabase* db, QWidget *parent = 0);
    ~Dialog();
    QString get_login();
    QString get_password();
    bool is_checked();

private:
    Ui::Dialog *ui;
    QSqlDatabase* ptr_db;

 public slots:
    virtual void accept();
};

#endif // LOGINDIALOG_H
