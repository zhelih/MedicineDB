#ifndef LISTDIALOG_H
#define LISTDIALOG_H

#include <QDialog>
#include <QList>
#include "procedurecall.h"

namespace Ui {
class ListDialog;
}

class ListDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ListDialog(QWidget *parent = 0);
    ~ListDialog();
    void setData(QList<ill>);
    
private:
    Ui::ListDialog *ui;
};

#endif // LISTDIALOG_H
