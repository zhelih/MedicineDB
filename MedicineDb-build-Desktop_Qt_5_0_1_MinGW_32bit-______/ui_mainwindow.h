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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_1;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
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
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(662, 401);
        action_1 = new QAction(MainWindow);
        action_1->setObjectName(QStringLiteral("action_1"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
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
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addSeparator();
        menu->addAction(action_1);
        menu->addAction(action_2);
        menu_2->addAction(action_3);
        menu_2->addAction(action_4);

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\273\321\226\321\224\320\275\321\202 \320\260\320\264\320\274\321\226\320\275\321\226\321\201\321\202\321\200\320\260\321\206\321\226\321\227 \320\261\320\264 \320\234\320\265\320\264\320\270\321\206\320\270\320\275\320\260", 0));
        action_1->setText(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\321\2171", 0));
        action_2->setText(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\321\2172", 0));
        action_3->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\262\321\226\320\264\320\275\320\270\320\2721", 0));
        action_4->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\262\321\226\320\264\320\275\320\270\320\2722", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\320\275\320\275\321\217", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\320\270", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\232\320\265\321\210\321\203\320\262\320\260\320\275\320\275\321\217", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\321\226\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\320\270", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\222\321\226\320\264\320\272\320\260\321\202", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\223\320\276\320\273\320\276\320\262\320\275\321\226 \321\202\320\260\320\261\320\273\320\270\321\206\321\226", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\224\320\276\320\262\321\226\320\264\320\275\320\270\320\272\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
