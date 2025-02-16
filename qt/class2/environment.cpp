#include "environment.h"
#include "ui_environment.h"

Environment::Environment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Environment)
{
    ui->setupUi(this);
}

Environment::~Environment()
{
    delete ui;
}
