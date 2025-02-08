#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include<QString>
#include"ui_register.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_regConfirmBtn_clicked();

    void on_backBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::Register *ui;
    void validateRegistration();
    void showError(const QString &message);
    bool connectToDatabase();
    void saveUserToDatabase(const QString &username, const QString &password);

signals:
    void returnToLogin();
};

#endif // REGISTER_H
