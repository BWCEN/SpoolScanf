/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionScan_Params;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QTreeWidget *treeWidget;
    QPushButton *pushButton_Scan;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Quit;
    QProgressBar *progressBar;
    QPushButton *pushButton_Filter;
    QLabel *label_3;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionScan_Params = new QAction(MainWindow);
        actionScan_Params->setObjectName("actionScan_Params");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 69, 19));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 30, 69, 19));
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(40, 90, 721, 361));
        pushButton_Scan = new QPushButton(centralwidget);
        pushButton_Scan->setObjectName("pushButton_Scan");
        pushButton_Scan->setGeometry(QRect(40, 490, 93, 28));
        pushButton_Stop = new QPushButton(centralwidget);
        pushButton_Stop->setObjectName("pushButton_Stop");
        pushButton_Stop->setGeometry(QRect(360, 490, 93, 28));
        pushButton_Quit = new QPushButton(centralwidget);
        pushButton_Quit->setObjectName("pushButton_Quit");
        pushButton_Quit->setGeometry(QRect(650, 490, 111, 31));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(510, 110, 120, 23));
        progressBar->setValue(24);
        pushButton_Filter = new QPushButton(centralwidget);
        pushButton_Filter->setObjectName("pushButton_Filter");
        pushButton_Filter->setGeometry(QRect(670, 110, 93, 28));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 30, 69, 19));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionScan_Params);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionScan_Params->setText(QCoreApplication::translate("MainWindow", "setting", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\233\256\346\240\207IP", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\273\210\346\255\242\347\253\257\345\217\243", nullptr));
        pushButton_Scan->setText(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        pushButton_Stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_Quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        pushButton_Filter->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\350\265\267\345\247\213\347\253\257\345\217\243", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "Scan Params", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
