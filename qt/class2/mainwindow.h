#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"airconditioner.h"
#include"curtain.h"
#include"light.h"
#include"environment.h"
#include"lock.h"
#include"powersystem.h"
#include"gps.h"
#include"security.h"
#include"dashboard.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_airConditionerBtn_clicked();

    void on_curtainBtn_clicked();

    void on_lightBtn_clicked();

    void on_environmentBtn_clicked();

    void on_lockBtn_clicked();

    void on_powerSystemBtn_clicked();

    void on_gpsBtn_clicked();

    void on_securityBtn_clicked();

    void on_dashboardBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
