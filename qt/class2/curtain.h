#ifndef CURTAIN_H
#define CURTAIN_H


#include <QDialog>
#include "curtainwidget.h"

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
private slots:
    void updateCurtain(int value);

};

#endif // CURTAIN_H
