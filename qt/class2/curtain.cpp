#include "curtain.h"
#include "ui_curtain.h"

Curtain::Curtain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Curtain)
{
    ui->setupUi(this);
}

Curtain::~Curtain()
{
    delete ui;
}
