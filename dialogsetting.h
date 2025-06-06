#ifndef DIALOGSETTING_H
#define DIALOGSETTING_H

#include <QDialog>

namespace Ui {
class Dialogsetting;
}

class Dialogsetting : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogsetting(QWidget *parent = nullptr);
    ~Dialogsetting();

    void getScanParams(QString *strIP,int *startPort,int *endPort, int *threadNum);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialogsetting *ui;
};

#endif // DIALOGSETTING_H
