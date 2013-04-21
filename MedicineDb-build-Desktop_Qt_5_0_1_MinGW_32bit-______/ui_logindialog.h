/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QCheckBox *checkBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(360, 160);
        Dialog->setMinimumSize(QSize(360, 160));
        Dialog->setMaximumSize(QSize(360, 160));
        Dialog->setSizeGripEnabled(false);
        Dialog->setModal(false);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 120, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 46, 13));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 51, 16));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 60, 241, 20));
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 90, 121, 20));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 30, 71, 16));
        lineEdit_3 = new QLineEdit(Dialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 30, 61, 20));
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(Dialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(170, 30, 61, 20));
        lineEdit_4->setInputMethodHints(Qt::ImhPreferNumbers);
        lineEdit_4->setReadOnly(true);
        lineEdit_5 = new QLineEdit(Dialog);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(240, 30, 101, 20));
        lineEdit_5->setReadOnly(true);
        checkBox = new QCheckBox(Dialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(240, 90, 101, 17));
        checkBox->setChecked(true);
        checkBox->setTristate(false);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\320\224\321\226\320\260\320\273\320\276\320\263 \320\273\320\276\320\263\321\226\320\275\321\203", 0));
        label->setText(QApplication::translate("Dialog", "\320\233\320\276\320\263\321\226\320\275:", 0));
        label_2->setText(QApplication::translate("Dialog", "\320\237\320\260\321\200\320\276\320\273\321\214:", 0));
        lineEdit->setText(QApplication::translate("Dialog", "db2admin", 0));
        label_3->setText(QApplication::translate("Dialog", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\320\270\321\205:", 0));
        lineEdit_3->setText(QApplication::translate("Dialog", "127.0.0.1", 0));
        lineEdit_4->setText(QApplication::translate("Dialog", "50000", 0));
        lineEdit_5->setText(QApplication::translate("Dialog", "Medicine", 0));
        checkBox->setText(QApplication::translate("Dialog", "\320\240\320\265\320\266\320\270\320\274 \320\260\320\264\320\274\321\226\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
