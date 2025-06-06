/********************************************************************************
** Form generated from reading UI file 'dialogsetting.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETTING_H
#define UI_DIALOGSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialogsetting
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox_startPort;
    QLabel *label_strIP;
    QLabel *label_endPort;
    QSpinBox *spinBox_Port;
    QLabel *label_startPort;
    QLineEdit *lineEdit_IP;
    QLabel *label_thread;
    QSpinBox *spinBox_threadNum;

    void setupUi(QDialog *Dialogsetting)
    {
        if (Dialogsetting->objectName().isEmpty())
            Dialogsetting->setObjectName("Dialogsetting");
        Dialogsetting->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialogsetting);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox_startPort = new QSpinBox(Dialogsetting);
        spinBox_startPort->setObjectName("spinBox_startPort");
        spinBox_startPort->setGeometry(QRect(90, 120, 101, 25));
        spinBox_startPort->setMinimum(1);
        spinBox_startPort->setMaximum(65535);
        label_strIP = new QLabel(Dialogsetting);
        label_strIP->setObjectName("label_strIP");
        label_strIP->setGeometry(QRect(20, 50, 69, 19));
        label_endPort = new QLabel(Dialogsetting);
        label_endPort->setObjectName("label_endPort");
        label_endPort->setGeometry(QRect(220, 120, 69, 19));
        spinBox_Port = new QSpinBox(Dialogsetting);
        spinBox_Port->setObjectName("spinBox_Port");
        spinBox_Port->setGeometry(QRect(290, 120, 101, 25));
        spinBox_Port->setMinimum(1);
        spinBox_Port->setMaximum(65535);
        label_startPort = new QLabel(Dialogsetting);
        label_startPort->setObjectName("label_startPort");
        label_startPort->setGeometry(QRect(20, 120, 69, 19));
        lineEdit_IP = new QLineEdit(Dialogsetting);
        lineEdit_IP->setObjectName("lineEdit_IP");
        lineEdit_IP->setGeometry(QRect(90, 50, 201, 25));
        label_thread = new QLabel(Dialogsetting);
        label_thread->setObjectName("label_thread");
        label_thread->setGeometry(QRect(20, 170, 69, 19));
        spinBox_threadNum = new QSpinBox(Dialogsetting);
        spinBox_threadNum->setObjectName("spinBox_threadNum");
        spinBox_threadNum->setGeometry(QRect(90, 170, 101, 25));

        retranslateUi(Dialogsetting);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialogsetting, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialogsetting, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialogsetting);
    } // setupUi

    void retranslateUi(QDialog *Dialogsetting)
    {
        Dialogsetting->setWindowTitle(QCoreApplication::translate("Dialogsetting", "Dialog", nullptr));
        label_strIP->setText(QCoreApplication::translate("Dialogsetting", "\347\233\256\346\240\207IP", nullptr));
        label_endPort->setText(QCoreApplication::translate("Dialogsetting", "\347\273\210\346\255\242\347\253\257\345\217\243", nullptr));
        label_startPort->setText(QCoreApplication::translate("Dialogsetting", "\350\265\267\345\247\213\347\253\257\345\217\243", nullptr));
        label_thread->setText(QCoreApplication::translate("Dialogsetting", "\347\272\277\347\250\213\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialogsetting: public Ui_Dialogsetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETTING_H
