#include "lock.h"
#include "ui_lock.h"

Lock::Lock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lock)
{
    ui->setupUi(this);
}

Lock::~Lock()
{
    delete ui;
}
