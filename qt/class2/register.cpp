#include "register.h"
#include "ui_register.h"
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QTextStream>
#include<QCloseEvent>
#include<QRegularExpression>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

bool Register::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::database("my_connection", false);
    if (db.isOpen()) {
        return true;
    }

    db = QSqlDatabase::addDatabase("QODBC", "my_connection");
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
    QString phoneNumber = ui->phoneEdit->text();
    QString password = ui->regPasswordEdit->text();
    QString licensePlate = ui->CarIdEdit->text();

    QRegularExpression phoneRegex("\\d{11}$");
    if(!phoneRegex.match(phoneNumber).hasMatch()){
        showError("手机号码必须要为11位数字！");
        return;
    }

    if(!isPhoneNumberUnique(phoneNumber)){
        return;
    }

    QRegularExpression licenseRegex("^[京津沪渝冀豫云辽黑湘皖鲁新苏浙赣鄂桂甘晋蒙陕吉闽贵粤青藏川宁琼][A-HJ-NP-Z][A-HJ-NP-Z0-9]{4,5}[A-HJ-NP-Z0-9港澳]$");
    if(!licenseRegex.match(licensePlate).hasMatch()){
        showError("车牌号格式不正确！");
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
        saveUserToDatabase(phoneNumber,password,licensePlate);
    }
    accept();
}

bool Register::isPhoneNumberUnique(const QString &phone)
{
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT phone_number FROM users WHERE phone_number = :phone");
    checkQuery.bindValue(":phone",phone);

    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "查询失败", "检查手机号唯一性时出错：" + checkQuery.lastError().text());
        return false;
    }

    if (checkQuery.next()) {
        QMessageBox::warning(this, "错误", "该手机号已注册！");
        return false;
    }
    return true;
}

void Register::saveUserToDatabase(const QString &phoneNumber, const QString &password,const QString &licensePlate)
{
    QSqlQuery query(QSqlDatabase::database("my_connection"));
    query.prepare("INSERT INTO users (phone_number, password,license_plate) VALUES (:phone_number, :password,:license_plate)");
    query.bindValue(":phone_number", phoneNumber);
    query.bindValue(":password", password);
    query.bindValue(":license_plate", licensePlate);


    if(!query.exec()){
        QMessageBox::critical(this,"注册失败","无法保存用户数据："+query.lastError().text());
    }else{
        QMessageBox::information(this,"注册成功","用户已成功注册！");
    }
    QSqlDatabase::database("my_connection", false).close();
}


void Register::showError(const QString &message)
{
    QMessageBox::critical(this,"注册错误",message);
    ui->regPasswordEdit->clear();
    ui->confirmPasswordEdit->clear();
    ui->regPasswordEdit->setFocus();
    ui->phoneEdit->clear();
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
