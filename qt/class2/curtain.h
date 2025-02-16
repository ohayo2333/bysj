#ifndef CURTAIN_H
#define CURTAIN_H

#include <QDialog>

namespace Ui {
class Curtain;
}

class Curtain : public QDialog
{
    Q_OBJECT

public:
    explicit Curtain(QWidget *parent = 0);
    ~Curtain();

private:
    Ui::Curtain *ui;
};

#endif // CURTAIN_H
