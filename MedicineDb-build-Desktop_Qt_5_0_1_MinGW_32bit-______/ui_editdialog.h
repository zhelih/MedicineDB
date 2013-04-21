/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName(QStringLiteral("EditDialog"));
        EditDialog->setWindowModality(Qt::ApplicationModal);
        EditDialog->resize(250, 500);
        gridLayout = new QGridLayout(EditDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(EditDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setAutoFillBackground(false);
        tableView->setInputMethodHints(Qt::ImhNone);

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(EditDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(EditDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QApplication::translate("EditDialog", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\320\275\320\275\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
