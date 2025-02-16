#ifndef GPS_H
#define GPS_H

#include <QDialog>

namespace Ui {
class GPS;
}

class GPS : public QDialog
{
    Q_OBJECT

public:
    explicit GPS(QWidget *parent = 0);
    ~GPS();

private:
    Ui::GPS *ui;
};

#endif // GPS_H
