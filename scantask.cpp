#include "scantask.h"

ScanTask::ScanTask(QString strIP, int intPort, int order, QAtomicInt *running)
    : m_strIP(strIP), m_intPort(intPort), m_order(order), m_running(running) {}

ScanTask::~ScanTask() {
    qDebug() << "Task deleted.";
}

void ScanTask::run() {
    QTcpSocket socket;
    socket.abort();
    socket.connectToHost(m_strIP, m_intPort);

    if (!m_running->loadRelaxed()) {
        return; // 如果停止信号为真，则退出任务
    }

    if (m_running->loadRelaxed() && socket.waitForConnected(1000)) {
        emit send_scan_signal(m_intPort, true, m_order);
        qDebug() << m_intPort << ": opened";
    } else {
        emit send_scan_signal(m_intPort, false, m_order);
        qDebug() << m_intPort << ": closed";
    }

    emit finished(); // 发射 finished 信号
}
