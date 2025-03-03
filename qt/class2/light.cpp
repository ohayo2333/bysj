#include "light.h"
#include "ui_light.h"


Light::Light(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Light),
    timer(new QTimer(this))

{
    ui->setupUi(this);

    ui->labeltext->setText("灯已关");
    ui->labeltime->setText("--:--:--");

    connect(timer, &QTimer::timeout, this, &Light::updateTime);

}

Light::~Light()
{
    delete ui;
}

void Light::on_pushButton_clicked()
{
    if (lightOn) {
            // 关灯
            lightOn = false;
            ui->image->setStyleSheet("image: url(:/pic/lightoff.png);");
            ui->labeltext->setText("灯已关");
            ui->pushButton->setText("开灯");
            timer->stop();  // 停止计时
            ui->labeltime->setText("--:--:--");
        } else {
            // 开灯
            lightOn = true;
            ui->image->setStyleSheet("image: url(:/pic/lightopen.png);");
            ui->labeltext->setText("灯已开");
            ui->pushButton->setText("关灯");

            // 记录开启时间
            startTime = QDateTime::currentDateTime();
            timer->start(1000);  // 每秒更新一次计时
        }
}

void Light::updateTime()
{
    qint64 elapsed = startTime.secsTo(QDateTime::currentDateTime());
        QTime elapsedTime(0, 0);
        elapsedTime = elapsedTime.addSecs(elapsed);
        ui->labeltime->setText(elapsedTime.toString("hh:mm:ss"));
}
