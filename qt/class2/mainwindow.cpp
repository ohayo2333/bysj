#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_airConditionerBtn_clicked()
{
    AirConditioner *dialog = new AirConditioner(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::on_curtainBtn_clicked()
{
    Curtain *dialog = new Curtain(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::on_lightBtn_clicked()
{
    Light *dialog = new Light(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::on_environmentBtn_clicked()
{
    Environment *dialog = new Environment(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::on_lockBtn_clicked()
{
    Lock *dialog = new Lock(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::on_powerSystemBtn_clicked()
{
    PowerSystem *dialog = new PowerSystem(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::on_gpsBtn_clicked()
{
    GPS *dialog = new GPS(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::on_securityBtn_clicked()
{
    Security *dialog = new Security(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}


void MainWindow::on_dashboardBtn_clicked()
{
    Dashboard *dialog = new Dashboard(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}
