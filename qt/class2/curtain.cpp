#include "curtain.h"
#include "ui_curtain.h"

Curtain::Curtain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Curtain)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &Curtain::updateCurtain);
}

Curtain::~Curtain()
{
    delete ui;
}

void Curtain::updateCurtain(int value)
{
     ui->statusLabel->setText(QString("开合度: %1%").arg(value));
     ui->curtainArea->setOpenness(value);
}
