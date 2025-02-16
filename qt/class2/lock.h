#ifndef LOCK_H
#define LOCK_H

#include <QDialog>

namespace Ui {
class Lock;
}

class Lock : public QDialog
{
    Q_OBJECT

public:
    explicit Lock(QWidget *parent = 0);
    ~Lock();

private:
    Ui::Lock *ui;
};

#endif // LOCK_H
