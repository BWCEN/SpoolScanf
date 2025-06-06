#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidget>
#include <QThreadPool>
#include <QMutex>
#include <QAtomicInt>
#include <QProgressBar>
#include <QVector>

#include "scantask.h"
#include "dialogsetting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Dialogsetting diaglogSetting;
    QTreeWidgetItem *itemRoot; // 树形控件的条目，用于表示目标 IP
    QTreeWidgetItem *itemLeaf; // 树形控件的条目，用于表示目标端口
    QThreadPool *threadpool; // 声明一个线程池
    int totalPorts; // 要扫描的端口总数
    int scannedPorts; // 已扫描的端口数
    QProgressBar *progressBar; // 进度条
    QMutex mutex; // 声明互斥锁
    QAtomicInt running; // 添加运行标志
    QVector<QTreeWidgetItem*> items; // 用于存储扫描结果
    bool isStopped; // 添加一个状态标志，用于记录是否停止扫描
    QVector<ScanTask*> unfinishedTasks; // 用于存储未完成的任务
    bool filtering = false;
    int threadCount = 0;
    QString strIP;
    int startPort;
    int endPort;
    int threadNum;

private slots:
    void on_actionScan_triggered();

    void on_pushButton_Scan_clicked();
    void on_pushButton_Stop_clicked();
    void on_pushButton_Quit_clicked();
    void recv_result(int port, bool isOpen); // 自定义槽函数，用于接收线程发送的消息
    void recv_finished_threadnum();
    void on_pushButton_Filter_clicked(); // 新增槽函数，用于处理筛选按钮的点击事件
    void openDialogSetting(); // 新增槽函数，用于打开设置对话框

};

#endif // MAINWINDOW_H
