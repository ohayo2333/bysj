#include "login.h"
#include"register.h"
#include "ui_login.h"
#include"ui_mainwindow.h"
#include"mainwindow.h"
#include"forgotpassworddialog.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QCloseEvent>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include <QApplication>
#include<QRegularExpression>
#include<QCryptographicHash>//哈希以后添加

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    if (!connectToDatabase()) {
            QMessageBox::critical(this, "数据库连接失败", "无法连接到数据库！");
            return;
        }

    loadSavedCredentials();
}

login::~login()
{
    delete ui;
}

void login::loadSavedCredentials()
{
    QSettings settings("MyCompany","Rvmonitor");
    QString phone = settings.value("Login/Username").toString();
    QString password = settings.value("Login/Password").toString();
    bool remember = settings.value("Login/RememberPassword",false).toBool();

    ui->usernameEdit->setText(phone);
    if(remember){
        ui->passwordEdit->setText(password);
        ui->rememberCheckBox->setChecked(true);
    }
}

void login::saveCredentials()
{
    QSettings settings("MyCompany", "RVMonitor");
    settings.setValue("Login/Username", ui->usernameEdit->text());
    settings.setValue("Login/Password", ui->passwordEdit->text());
    settings.setValue("Login/RememberPassword",true);
}

void login::clearCredentials()
{
    QSettings settings("MyCompany", "RVMonitor");
    settings.remove("Login/Username");
    settings.remove("Login/Password");
    settings.setValue("Login/RememberPassword", false);
}

bool login::connectToDatabase()
{
    if(QSqlDatabase::database().isOpen()){
        return true;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");  // 数据库主机名
    db.setPort(3306);
    db.setDatabaseName("test1");  // 数据库名称
    db.setUserName("root");        // 数据库用户名
    db.setPassword("123456");    // 数据库密码

    if(!db.open()){
        return false;
    }
    return true;
}

void login::on_loginBtn_clicked()
{
    QString phoneNumber = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    if(phoneNumber.isEmpty() || password.isEmpty()){
        QMessageBox::warning(this,"输入错误","手机号或密码不能为空！");
        return;
    }

    QRegularExpression phoneRegex("^\\d{11}$");
    if(!phoneRegex.match(phoneNumber).hasMatch()){
        QMessageBox::warning(this,"输入错误","手机号格式不正确！");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE phone_number = :phone_number");
    query.bindValue(":phone_number",phoneNumber);

    if(!query.exec()){
        QMessageBox::critical(this,"服务器错误","服务器出现问题！");
        return;
    }

    if(!query.next()){
        QMessageBox::information(this,"注册提示","账号未注册，请先注册");
        return;
    }

    QString storedPassword  = query.value(0).toString();

    if(storedPassword   == password ){
        if(ui->rememberCheckBox->isChecked()) {
                    saveCredentials();
                } else {
                    clearCredentials();
                }

        MainWindow *mainWindow = new MainWindow();
        mainWindow->setAttribute(Qt::WA_DeleteOnClose);
        mainWindow->show();
        this->close();
    }else{
        QMessageBox::warning(this, "登录失败", "账号或密码错误，请重新登录");
       // ui->usernameEdit->clear();
        ui->passwordEdit->clear();
        ui->passwordEdit->setFocus();
    }

}

void login::on_regBtn_clicked()
{
    Register *regDialog = new Register(this);
    regDialog->setWindowTitle("用户注册");
    regDialog->setModal(true);

    connect(regDialog, &Register::returnToLogin,  [this,regDialog](){
           regDialog->close();
           this->show();
       });
    this->hide();
    if(regDialog->exec() == QDialog::Accepted)
    {
        QMessageBox::information(this,"成功","注册成功，请登录！");
    }
        this->show();
}

void login::on_exitBtn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"退出","确认退出程序吗？",
                                  QMessageBox::Yes |QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }
}

void login::on_forgotpasswordBtn_clicked()
{
    forgotpasswordDialog dialog(this);
    connect(&dialog,&forgotpasswordDialog::requestRegister,
            this,&login::handleForgotPasswordToRegister);
    dialog.exec();
}

void login::handleForgotPasswordToRegister()
{
    on_regBtn_clicked();
}



