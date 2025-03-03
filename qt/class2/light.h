#ifndef LIGHT_H
#define LIGHT_H

#include <QDialog>
#include <QTimer>
#include <QDateTime>

namespace Ui {
class Light;
}

class Light : public QDialog
{
    Q_OBJECT

public:
    explicit Light(QWidget *parent = 0);
    ~Light();

private slots:
    void on_pushButton_clicked();
    void updateTime();

private:
    Ui::Light *ui;
    bool lightOn = false;
    QTimer *timer;
    QDateTime startTime;
};

#endif // LIGHT_H
