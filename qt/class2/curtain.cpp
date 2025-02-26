#include "curtain.h"
#include "ui_curtain.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QPropertyAnimation>

class CurtainWidget : public QWidget {
    Q_OBJECT


public:
    explicit CurtainWidget(QWidget *parent = nullptr)
        : QWidget(parent), openness(0) {}

    void setOpenness(int value) {
        openness = qBound(0, value, 100);  // 限制值在 0 到 100 之间
        update(); // 触发重绘
    }

    int getOpenness() const {
        return openness;
    }

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // 绘制背景
        painter.fillRect(rect(), QColor(220, 220, 220));

        // 计算窗帘高度（模拟升降效果）
        int curtainHeight = height() * (100 - openness) / 100;

        // 绘制窗帘布
        painter.fillRect(0, 0, width(), curtainHeight, QColor(70, 130, 180));  // 深蓝色窗帘

        // 绘制装饰横杆
        painter.setPen(QPen(Qt::darkGray, 4));
        painter.drawLine(0, curtainHeight, width(), curtainHeight);
    }

private:
    int openness;  // 用来保存窗帘的开合程度
};

Curtain::Curtain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Curtain)
{
    ui->setupUi(this);

    CurtainWidget *curtain = new CurtainWidget;
        QVBoxLayout *layout = new QVBoxLayout(ui->curtainArea);
        layout->addWidget(curtain);


        ui->horizontalSlider->setRange(0, 100);
        ui->horizontalSlider->setValue(0);

        ui->horizontalSlider->setStyleSheet(R"(
               QSlider::groove:horizontal {
                   height: 10px;
                   background: #E0E0E0;
                   border-radius: 5px;
               }
               QSlider::sub-page:horizontal {
                   background: #4682B4;
                   border-radius: 5px;
               }
               QSlider::handle:horizontal {
                   width: 20px;
                   margin: -5px 0;
                   background: white;
                   border: 1px solid #999;
                   border-radius: 10px;
               }
           )");

        connect(ui->horizontalSlider, &QSlider::valueChanged, [=](int value){
                QString state;
                if (value == 0) state = "完全关闭";
                else if (value < 30) state = "微开";
                else if (value < 70) state = "半开";
                else state = "全开";

                ui->statusLabel->setText(QString("状态: %1 (%2%)").arg(state).arg(value));
                curtain->setOpenness(value);  // 设置窗帘开合度
            });
}

void Curtain::smoothSetOpenness(int value) {
    QPropertyAnimation *anim = new QPropertyAnimation(this, "openness");
    anim->setDuration(500);
    anim->setEasingCurve(QEasingCurve::InOutQuad);
    anim->setStartValue(ui->horizontalSlider->value());
    anim->setEndValue(value);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

Curtain::~Curtain()
{
    delete ui;
}


