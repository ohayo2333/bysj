#include "gps.h"
#include "ui_gps.h"

GPS::GPS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GPS)
{
    ui->setupUi(this);
}

GPS::~GPS()
{
    delete ui;
}
