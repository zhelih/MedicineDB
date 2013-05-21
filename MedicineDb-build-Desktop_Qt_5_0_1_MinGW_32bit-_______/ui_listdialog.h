/********************************************************************************
** Form generated from reading UI file 'listdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTDIALOG_H
#define UI_LISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ListDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QDialog *ListDialog)
    {
        if (ListDialog->objectName().isEmpty())
            ListDialog->setObjectName(QStringLiteral("ListDialog"));
        ListDialog->setWindowModality(Qt::ApplicationModal);
        ListDialog->resize(400, 300);
        gridLayout = new QGridLayout(ListDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(ListDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        tableWidget = new QTableWidget(ListDialog);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        retranslateUi(ListDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), ListDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(ListDialog);
    } // setupUi

    void retranslateUi(QDialog *ListDialog)
    {
        ListDialog->setWindowTitle(QApplication::translate("ListDialog", "\320\245\320\262\320\276\321\200\320\276\320\261\320\270", 0));
        pushButton->setText(QApplication::translate("ListDialog", "OK", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ListDialog", "\320\245\320\262\320\276\321\200\320\276\320\261\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ListDialog", "\320\224\320\260\321\202\320\260 \320\267\320\262\320\265\321\200\320\275\320\265\320\275\320\275\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ListDialog", "\320\224\320\260\321\202\320\260 \320\262\320\270\320\277\320\270\321\201\320\272\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class ListDialog: public Ui_ListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTDIALOG_H
