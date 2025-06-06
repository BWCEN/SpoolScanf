#ifndef SCANTASK_H
#define SCANTASK_H

#include <QObject>
#include <QRunnable>
#include <QTcpSocket>
#include <QAtomicInt>

class ScanTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    ScanTask(QString ip, int port, int order, QAtomicInt *running);
    ~ScanTask();
protected:
    void run();
private:
    QString m_strIP;
    int m_intPort;
    int m_order; // 顺序标识符
    QAtomicInt *m_running;
signals:
    void send_scan_signal(int port, bool isOpen, int order);
    void finished(); // 添加 finished 信号
};

#endif // SCANTASK_H
