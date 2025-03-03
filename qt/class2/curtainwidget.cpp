#include "curtainwidget.h"
#include<QPainter>
#include<QLinearGradient>

CurtainWidget::CurtainWidget(QWidget *parent) : QWidget(parent)
{

}

CurtainWidget::~CurtainWidget()
{

}

void CurtainWidget::setOpenness(int value) {
    openness = qBound(0, value, 100);
    update();
}

void CurtainWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 绘制金属轨道
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(200, 200, 200));
    painter.drawRoundedRect(rect().adjusted(0, 5, 0, -25), 8, 8);

    // 计算窗帘的高度
    int curtainHeight = height() * openness / 100;

    // 创建渐变效果
    QLinearGradient grad(0, 0, 0, curtainHeight);
    grad.setColorAt(0, curtainColor);
    grad.setColorAt(1, curtainColor.lighter(120));

    painter.setBrush(grad);

    // 上下窗帘布
    painter.drawRect(0, 0, width(), curtainHeight);
}
