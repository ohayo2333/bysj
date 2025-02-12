#include "forgotpassworddialog.h"
#include "ui_forgotpassworddialog.h"
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
    QString username = ui->usernameEdit->text().trimmed();
    QString newPassword = ui->newPasswordEdit->text().trimmed();

    if(username.isEmpty()|| newPassword.isEmpty()){
        QMessageBox::warning(this,"错误","账号密码不能为空！");
        return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM users WHERE username = :username");
    checkQuery.bindValue(":username",username);

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
    updateQuery.prepare("UPDATE users SET password = :password WHERE username = :username");
    updateQuery.bindValue(":password",newPassword);
    updateQuery.bindValue(":username",username);

    if(updateQuery.exec()){
        QMessageBox::information(this,"成功","密码重置成功！");
        this->close();
    }else{
        QMessageBox::critical(this,"错误","密码更新失败~");
    }
}
