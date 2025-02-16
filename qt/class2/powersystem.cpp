#include "powersystem.h"
#include "ui_powersystem.h"

PowerSystem::PowerSystem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PowerSystem)
{
    ui->setupUi(this);
}

PowerSystem::~PowerSystem()
{
    delete ui;
}
