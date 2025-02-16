#ifndef AIRCONDITIONER_H
#define AIRCONDITIONER_H

#include <QDialog>

namespace Ui {
class AirConditioner;
}

class AirConditioner : public QDialog
{
    Q_OBJECT

public:
    explicit AirConditioner(QWidget *parent = 0);
    ~AirConditioner();

private:
    Ui::AirConditioner *ui;
};

#endif // AIRCONDITIONER_H
