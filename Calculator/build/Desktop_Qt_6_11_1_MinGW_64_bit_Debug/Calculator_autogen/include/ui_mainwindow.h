/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *displayLabel;
    QPushButton *modbtn;
    QPushButton *clrbtn;
    QPushButton *cbtn;
    QPushButton *cebtn;
    QPushButton *sqrbtn;
    QPushButton *invbtn;
    QPushButton *divbtn;
    QPushButton *rootbtn;
    QPushButton *btn5;
    QPushButton *btn4;
    QPushButton *subbtn;
    QPushButton *btn6;
    QPushButton *btn2;
    QPushButton *btn1;
    QPushButton *addbtn;
    QPushButton *btn3;
    QPushButton *btn0;
    QPushButton *negatebtn;
    QPushButton *equbtn;
    QPushButton *dotbtn;
    QPushButton *btn7;
    QPushButton *mulbtn;
    QPushButton *btn9;
    QPushButton *btn8;
    QMenuBar *menubar;
    QMenu *menucalculator;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(390, 683);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        displayLabel = new QLineEdit(centralwidget);
        displayLabel->setObjectName("displayLabel");
        displayLabel->setGeometry(QRect(0, 50, 391, 91));
        displayLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        displayLabel->setReadOnly(true);
        modbtn = new QPushButton(centralwidget);
        modbtn->setObjectName("modbtn");
        modbtn->setGeometry(QRect(20, 220, 81, 61));
        QFont font;
        font.setPointSize(12);
        modbtn->setFont(font);
        clrbtn = new QPushButton(centralwidget);
        clrbtn->setObjectName("clrbtn");
        clrbtn->setGeometry(QRect(290, 220, 81, 61));
        clrbtn->setFont(font);
        cbtn = new QPushButton(centralwidget);
        cbtn->setObjectName("cbtn");
        cbtn->setGeometry(QRect(200, 220, 81, 61));
        cbtn->setFont(font);
        cebtn = new QPushButton(centralwidget);
        cebtn->setObjectName("cebtn");
        cebtn->setGeometry(QRect(110, 220, 81, 61));
        cebtn->setFont(font);
        sqrbtn = new QPushButton(centralwidget);
        sqrbtn->setObjectName("sqrbtn");
        sqrbtn->setGeometry(QRect(110, 290, 81, 61));
        sqrbtn->setFont(font);
        invbtn = new QPushButton(centralwidget);
        invbtn->setObjectName("invbtn");
        invbtn->setGeometry(QRect(20, 290, 81, 61));
        invbtn->setFont(font);
        divbtn = new QPushButton(centralwidget);
        divbtn->setObjectName("divbtn");
        divbtn->setGeometry(QRect(290, 290, 81, 61));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        divbtn->setFont(font1);
        rootbtn = new QPushButton(centralwidget);
        rootbtn->setObjectName("rootbtn");
        rootbtn->setGeometry(QRect(200, 290, 81, 61));
        rootbtn->setFont(font);
        btn5 = new QPushButton(centralwidget);
        btn5->setObjectName("btn5");
        btn5->setGeometry(QRect(110, 430, 81, 61));
        btn5->setFont(font);
        btn4 = new QPushButton(centralwidget);
        btn4->setObjectName("btn4");
        btn4->setGeometry(QRect(20, 430, 81, 61));
        btn4->setFont(font);
        subbtn = new QPushButton(centralwidget);
        subbtn->setObjectName("subbtn");
        subbtn->setGeometry(QRect(290, 430, 81, 61));
        subbtn->setFont(font1);
        btn6 = new QPushButton(centralwidget);
        btn6->setObjectName("btn6");
        btn6->setGeometry(QRect(200, 430, 81, 61));
        btn6->setFont(font);
        btn2 = new QPushButton(centralwidget);
        btn2->setObjectName("btn2");
        btn2->setGeometry(QRect(110, 500, 81, 61));
        btn2->setFont(font);
        btn1 = new QPushButton(centralwidget);
        btn1->setObjectName("btn1");
        btn1->setGeometry(QRect(20, 500, 81, 61));
        btn1->setFont(font);
        addbtn = new QPushButton(centralwidget);
        addbtn->setObjectName("addbtn");
        addbtn->setGeometry(QRect(290, 500, 81, 61));
        addbtn->setFont(font);
        btn3 = new QPushButton(centralwidget);
        btn3->setObjectName("btn3");
        btn3->setGeometry(QRect(200, 500, 81, 61));
        btn3->setFont(font);
        btn0 = new QPushButton(centralwidget);
        btn0->setObjectName("btn0");
        btn0->setGeometry(QRect(110, 570, 81, 61));
        btn0->setFont(font);
        negatebtn = new QPushButton(centralwidget);
        negatebtn->setObjectName("negatebtn");
        negatebtn->setGeometry(QRect(20, 570, 81, 61));
        negatebtn->setFont(font);
        equbtn = new QPushButton(centralwidget);
        equbtn->setObjectName("equbtn");
        equbtn->setGeometry(QRect(290, 570, 81, 61));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        equbtn->setFont(font2);
        dotbtn = new QPushButton(centralwidget);
        dotbtn->setObjectName("dotbtn");
        dotbtn->setGeometry(QRect(200, 570, 81, 61));
        dotbtn->setFont(font1);
        btn7 = new QPushButton(centralwidget);
        btn7->setObjectName("btn7");
        btn7->setGeometry(QRect(20, 360, 81, 61));
        btn7->setFont(font);
        mulbtn = new QPushButton(centralwidget);
        mulbtn->setObjectName("mulbtn");
        mulbtn->setGeometry(QRect(290, 360, 81, 61));
        mulbtn->setFont(font2);
        btn9 = new QPushButton(centralwidget);
        btn9->setObjectName("btn9");
        btn9->setGeometry(QRect(200, 360, 81, 61));
        btn9->setFont(font);
        btn8 = new QPushButton(centralwidget);
        btn8->setObjectName("btn8");
        btn8->setGeometry(QRect(110, 360, 81, 61));
        btn8->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 390, 25));
        menucalculator = new QMenu(menubar);
        menucalculator->setObjectName("menucalculator");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menucalculator->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        modbtn->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        clrbtn->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        cbtn->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        cebtn->setText(QCoreApplication::translate("MainWindow", "CE", nullptr));
        sqrbtn->setText(QCoreApplication::translate("MainWindow", "x\302\262", nullptr));
        invbtn->setText(QCoreApplication::translate("MainWindow", "1/x", nullptr));
        divbtn->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        rootbtn->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        btn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        subbtn->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        addbtn->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        negatebtn->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        equbtn->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        dotbtn->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        btn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        mulbtn->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        btn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        menucalculator->setTitle(QCoreApplication::translate("MainWindow", "calculator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
