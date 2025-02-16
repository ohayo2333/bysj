#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QDialog>

namespace Ui {
class Environment;
}

class Environment : public QDialog
{
    Q_OBJECT

public:
    explicit Environment(QWidget *parent = 0);
    ~Environment();

private:
    Ui::Environment *ui;
};

#endif // ENVIRONMENT_H
