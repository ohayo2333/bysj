#include "airconditioner.h"
#include "ui_airconditioner.h"

AirConditioner::AirConditioner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AirConditioner)
{
    ui->setupUi(this);
}

AirConditioner::~AirConditioner()
{
    delete ui;
}
