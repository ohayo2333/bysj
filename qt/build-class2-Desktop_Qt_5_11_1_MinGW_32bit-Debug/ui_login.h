/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *usernameEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *passwordEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loginBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *regBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exitBtn;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(800, 600);
        login->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(login);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(160, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(160, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 144, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 143, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(28);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(9);
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color: #1a1a1a;"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        usernameEdit = new QLineEdit(login);
        usernameEdit->setObjectName(QStringLiteral("usernameEdit"));
        usernameEdit->setStyleSheet(QLatin1String("padding: 8px;\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 4px;\n"
"    min-width: 250px;"));

        horizontalLayout->addWidget(usernameEdit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: #1a1a1a;"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        passwordEdit = new QLineEdit(login);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setStyleSheet(QLatin1String("padding: 8px;\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 4px;\n"
"    min-width: 250px;"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        loginBtn = new QPushButton(login);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(loginBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        regBtn = new QPushButton(login);
        regBtn->setObjectName(QStringLiteral("regBtn"));
        regBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(regBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        exitBtn = new QPushButton(login);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(exitBtn);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        loginBtn->raise();
        label_2->raise();
        label_3->raise();
        usernameEdit->raise();
        passwordEdit->raise();
        regBtn->raise();
        exitBtn->raise();

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", nullptr));
        label->setText(QApplication::translate("login", "\346\254\242\350\277\216\347\231\273\345\275\225\357\274\201", nullptr));
        label_2->setText(QApplication::translate("login", "\350\264\246\345\217\267\357\274\232", nullptr));
        usernameEdit->setText(QString());
        label_3->setText(QApplication::translate("login", "\345\257\206\347\240\201\357\274\232", nullptr));
        loginBtn->setText(QApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        regBtn->setText(QApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        exitBtn->setText(QApplication::translate("login", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
