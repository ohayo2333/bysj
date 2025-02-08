#include "register.h"
#include "ui_register.h"
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QTextStream>
#include<QCloseEvent>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

bool Register::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");  // 数据库主机名
    db.setPort(3306);
    db.setDatabaseName("test1");  // 数据库名称
    db.setUserName("root");        // 数据库用户名
    db.setPassword("123456");    // 数据库密码

    if(!db.open()){
        QMessageBox::critical(this,"数据库连接失败！",db.lastError().text());
        return false;
    }
    return true;
}

void Register::validateRegistration()
{
    QString username = ui->regUserEdit->text();
    QString password = ui->regPasswordEdit->text();

    if(username.isEmpty()){
        showError("用户名不能为空！");
        return;
    }
    if(password.length()<6){
        showError("密码长度不能少于6位！");
        return;
    }
    if(password!=ui->confirmPasswordEdit->text()) {
        QMessageBox::warning(this,"错误","两次输入的密码不一致!");
        return;
    }

    if(connectToDatabase()){
        saveUserToDatabase(username,password);
    }
    accept();
}

void Register::saveUserToDatabase(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if(!query.exec()){
        QMessageBox::critical(this,"注册失败","无法保存用户数据："+query.lastError().text());
    }else{
        QMessageBox::information(this,"注册成功","用户已成功注册！");
    }
}

void Register::showError(const QString &message)
{
    QMessageBox::critical(this,"注册错误",message);
    ui->regPasswordEdit->clear();
    ui->confirmPasswordEdit->clear();
    ui->regPasswordEdit->setFocus();
}
Register::~Register()
{
    delete ui;
}



void Register::on_regConfirmBtn_clicked()
{
    validateRegistration();
}

void Register::on_backBtn_clicked()
{
    this->close();
}

void Register::on_exitBtn_clicked()
{
    QApplication::quit();
}
