/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableView *tableView;
    QTableView *tableView_2;
    QGroupBox *groupBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(662, 401);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 20, 211, 311));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView_2 = new QTableView(centralWidget);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(240, 20, 311, 311));
        tableView_2->setSelectionMode(QAbstractItemView::MultiSelection);
        tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(560, 150, 91, 81));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 20, 75, 23));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 50, 75, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(560, 40, 91, 81));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 75, 23));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 50, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 662, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);
        QObject::connect(tableView, SIGNAL(doubleClicked(QModelIndex)), MainWindow, SLOT(open_table(QModelIndex)));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(sql_submit()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(sql_revert()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(sql_insert()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), MainWindow, SLOT(sql_delete()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Medicine database admin client", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Edit Tools", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Insert", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Delete", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Mirror", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Submit", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Revert", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
