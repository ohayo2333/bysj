#ifndef POWERSYSTEM_H
#define POWERSYSTEM_H

#include <QDialog>

namespace Ui {
class PowerSystem;
}

class PowerSystem : public QDialog
{
    Q_OBJECT

public:
    explicit PowerSystem(QWidget *parent = 0);
    ~PowerSystem();

private:
    Ui::PowerSystem *ui;
};

#endif // POWERSYSTEM_H
