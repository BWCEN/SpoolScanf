#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isStopped(false)
    , unfinishedTasks() // 初始化未完成任务队列
{
    ui->setupUi(this);

    // 给 QTreeWidget 初始化表头
    QStringList head;
    head << "扫描结果";
    ui->treeWidget->setHeaderLabels(head);

    // 初始化线程池
    threadpool = new QThreadPool;
    threadpool->setMaxThreadCount(threadNum); // 默认线程池中最大的线程数
    // 初始化进度条
    ui->progressBar->setRange(0, 100); // 设置进度条的范围为0到100
    ui->progressBar->setValue(0); // 初始化进度值为0

    // 连接筛选按钮的信号
    connect(ui->pushButton_Filter, &QPushButton::clicked, this, &MainWindow::on_pushButton_Filter_clicked);
    connect(ui->actionScan_Params, SIGNAL(triggered()), this, SLOT(on_actionScan_triggered()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDialogSetting()
{
    Dialogsetting dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        dialog.getScanParams(&strIP, &startPort, &endPort, &threadNum);
        threadpool->setMaxThreadCount(threadNum); // 更新线程池的最大线程数
    }

}

void MainWindow::on_pushButton_Scan_clicked()
{
    diaglogSetting.getScanParams(&strIP, &startPort, &endPort, &threadNum);
    threadpool->setMaxThreadCount(threadNum); // 更新线程池的最大线程数

    ui->pushButton_Scan->setEnabled(false); // 开始后禁用扫描按钮
    isStopped = false; // 重置停止状态
    ui->pushButton_Stop->setText("Stop"); // 更新按钮文本为 "Stop"

    if (strIP.isEmpty()) {
        QMessageBox::information(this, "Error", "请输入 IP", QMessageBox::Ok);
        return;
    }
    if (startPort == 0) {
        QMessageBox::information(this, "Error", "请输入起始 port", QMessageBox::Ok);
        return;
    }
    if (endPort == 0) {
        QMessageBox::information(this, "Error", "请输入结束 port", QMessageBox::Ok);
        return;
    }
    if (endPort < startPort) {
        QMessageBox::information(this, "Error", "开始端口不能大于结束端口", QMessageBox::Ok);
        return;
    }

    ui->treeWidget->clear();
    itemRoot = new QTreeWidgetItem(ui->treeWidget, QStringList(strIP));
    totalPorts = endPort - startPort + 1; // 端口总数
    scannedPorts = 0;
    ui->progressBar->reset(); // 重置进度条

    running.storeRelaxed(1); // 设置运行标志为1

    for (int i = startPort; i <= endPort; i++) { // 扫描从 startPort 到 endPort 的端口
        ScanTask *myThread = new ScanTask(strIP, i, i, &running);

        // 线程池分配一个线程运行该任务。执行完后会自动delete myThread
        threadpool->start(myThread);

        // 连接 myThread 的信号 send_scan_signal 和槽函数 recv_result
        connect(myThread, &ScanTask::send_scan_signal, this, &MainWindow::recv_result);
        // 当收到线程类的 finished 信号后，在接收的槽函数进行统计。一个信号可以对应多个槽函数
        connect(myThread, &ScanTask::finished, this, &MainWindow::recv_finished_threadnum);

        QThread::msleep(10);
    }
}

void MainWindow::recv_result(int port, bool isOpen)
{
    QMutexLocker locker(&mutex); // 使用互斥锁
    scannedPorts++; // 更新已扫描端口数

    int progressValue = static_cast<int>((scannedPorts / static_cast<double>(totalPorts)) * 100); // 计算当前进度百分比
    ui->progressBar->setValue(progressValue); // 更新进度条

    QString strPort = QString::number(port);
    QString count = QString::number(itemRoot->childCount());
    if (isOpen)
        itemLeaf = new QTreeWidgetItem(itemRoot, QStringList(strPort + " opened "));
    else
        itemLeaf = new QTreeWidgetItem(itemRoot, QStringList(strPort + " closed "));
    ui->treeWidget->expandAll();

    if (scannedPorts >= totalPorts) {
        ui->pushButton_Scan->setEnabled(true); // 扫描完成后启用扫描按钮
    }
}

void MainWindow::recv_finished_threadnum()
{
    threadCount++;
    if (threadCount == totalPorts) {
        ui->pushButton_Scan->setEnabled(true); // 扫描完成后启用扫描按钮
        ui->pushButton_Stop->setEnabled(false); // 禁用停止按钮
        QMessageBox::information(this, "info", "扫描结束");
        isStopped = false; // 重置停止状态
    }
}

void MainWindow::on_pushButton_Stop_clicked()
{
    if (!isStopped) {
        running.storeRelaxed(0); // 设置运行标志为0，通知线程停止
        isStopped = true; // 更新停止状态
        ui->pushButton_Stop->setText("Continue"); // 更新按钮文本为 "Continue"
        ui->pushButton_Scan->setEnabled(false); // 禁用扫描按钮

        // 保存未完成的任务
        unfinishedTasks.clear();
        for (int i = scannedPorts; i < totalPorts; i++) {
            ScanTask *task = new ScanTask(strIP, i + 1, i, &running);
            connect(task, &ScanTask::send_scan_signal, this, &MainWindow::recv_result);
            unfinishedTasks.append(task);
        }
    } else {
        running.storeRelaxed(1); // 设置运行标志为1，通知线程继续
        isStopped = false; // 更新停止状态
        ui->pushButton_Stop->setText("Stop"); // 更新按钮文本为 "Stop"
        ui->pushButton_Scan->setEnabled(false); // 禁用扫描按钮

        // 重新启动未完成的任务
        for (ScanTask *task : unfinishedTasks) {
            threadpool->start(task);
        }
        unfinishedTasks.clear(); // 清空未完成任务队列
    }
}

void MainWindow::on_pushButton_Quit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_Filter_clicked()
{
    if (filtering) {
        return; // 如果已经在进行筛选，则忽略此次点击
    }
    filtering = true;

    qDebug() << "Filter button clicked";
    // 保存原始的itemRoot，以便在筛选时使用

    // 保存所有开放端口的文本信息
    QStringList openPorts;
    for (int i = 0; i < itemRoot->childCount(); i++) {
        QTreeWidgetItem *child = itemRoot->child(i);
        if (child->text(0).contains("opened")) {
            openPorts << child->text(0);
        }
    }

    // 打印开放端口
    qDebug() << "Open Ports:";
    for (const QString &portInfo : openPorts) {
        qDebug() << portInfo;
    }

    // 清除树形控件并创建新的根项
    ui->treeWidget->clear(); // 清除旧的树形控件内容
  //  itemRoot = new QTreeWidgetItem(ui->treeWidget, QStringList(ui->lineEdit_IP->text()));

    // 根据保存的文本信息创建新的子项
    for (const QString &portInfo : openPorts) {
        new QTreeWidgetItem(itemRoot, QStringList(portInfo));
    }

    ui->treeWidget->expandAll(); // 展开所有项

    qDebug() << "Filtering completed";
    filtering = false;
}

void MainWindow::on_actionScan_triggered()
{
    diaglogSetting.show();
}
