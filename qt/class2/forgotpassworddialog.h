#ifndef FORGOTPASSWORDDIALOG_H
#define FORGOTPASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class forgotpasswordDialog;
}

class forgotpasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit forgotpasswordDialog(QWidget *parent = 0);
    ~forgotpasswordDialog();

signals:
    void requestRegister();

private slots:
    void on_Submitbtn_clicked();

private:
    Ui::forgotpasswordDialog *ui;
};

#endif // FORGOTPASSWORDDIALOG_H
