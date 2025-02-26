#ifndef CURTAIN_H
#define CURTAIN_H


#include <QDialog>
#include <QSlider>
#include <QLabel>
#include <QWidget>

namespace Ui {
class Curtain;
}

class Curtain : public QDialog
{
    Q_OBJECT

public:
    explicit Curtain(QWidget *parent = 0);
    ~Curtain();

private slots:
    void on_sliderValueChanged(int value);

private:
    void smoothSetOpenness(int value);
    Ui::Curtain *ui;


};

#endif // CURTAIN_H
