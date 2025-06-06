#include "dialogsetting.h"
#include "ui_dialogsetting.h"

Dialogsetting::Dialogsetting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogsetting)
{
    ui->setupUi(this);
}

Dialogsetting::~Dialogsetting()
{
    delete ui;
}

void Dialogsetting::getScanParams(QString *strIP, int *startPort, int *endPort, int *threadNum)
{
    *strIP = ui->lineEdit_IP->text(); // 获取 IP 地址
    *startPort = ui->spinBox_startPort->value(); // 获取起始端口
    *endPort = ui->spinBox_Port->value(); // 获取终止端口
    *threadNum = ui->spinBox_threadNum->value(); // 获取线程数
}

void Dialogsetting::on_buttonBox_accepted()
{
    accept(); // 接受对话框
}

