#include "forgotpassworddialog.h"
#include "ui_forgotpassworddialog.h"
#include <QRegularExpression>
#include<QMessageBox>
#include<QSqlQuery>

forgotpasswordDialog::forgotpasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forgotpasswordDialog)
{
    ui->setupUi(this);
}

forgotpasswordDialog::~forgotpasswordDialog()
{
    delete ui;
}

void forgotpasswordDialog::on_Submitbtn_clicked()
{
    QString phoneNumber  = ui->phoneEdit->text().trimmed();
    QString newPassword = ui->newPasswordEdit->text().trimmed();

    if(phoneNumber.isEmpty()|| newPassword.isEmpty()){
        QMessageBox::warning(this,"错误","手机号和密码不能为空！");
        return;
    }

    QRegularExpression phoneRegex("^\\d{11}$");
        if (!phoneRegex.match(phoneNumber).hasMatch()) {
            QMessageBox::warning(this, "错误", "请输入有效的11位手机号码！");
            return;
        }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT phone_number  FROM users WHERE phone_number = :phone_number ");
    checkQuery.bindValue(":phone_number",phoneNumber);

    if(!checkQuery.exec()){
        QMessageBox::critical(this,"错误","数据库查询失败！");
        return;
    }

    if(!checkQuery.next()){
        QMessageBox::information(this,"提示","账号不存在，请先注册");
        emit requestRegister();
        this->close();
        return;
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE users SET password = :password WHERE phone_number  = :phone_number ");
    updateQuery.bindValue(":password",newPassword);
    updateQuery.bindValue(":phone_number",phoneNumber);

    if(updateQuery.exec()){
        QMessageBox::information(this,"成功","密码重置成功！");
        this->close();
    }else{
        QMessageBox::critical(this,"错误","密码更新失败~");
    }
}
