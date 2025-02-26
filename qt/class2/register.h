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
    bool isPhoneNumberUnique(const QString &phone);
    void saveUserToDatabase(const QString &phoneNumber, const QString &password,const QString &licensePlate);

signals:
    void returnToLogin();
};

#endif // REGISTER_H
