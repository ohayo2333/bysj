/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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

class Ui_Register
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *regUserEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *regPasswordEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *confirmPasswordEdit;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *backBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *regConfirmBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exitBtn;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(800, 600);
        gridLayout = new QGridLayout(Register);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_6 = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(203, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        font.setPointSize(33);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);

        regUserEdit = new QLineEdit(Register);
        regUserEdit->setObjectName(QStringLiteral("regUserEdit"));

        horizontalLayout_4->addWidget(regUserEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        regPasswordEdit = new QLineEdit(Register);
        regPasswordEdit->setObjectName(QStringLiteral("regPasswordEdit"));
        regPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(regPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(Register);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        confirmPasswordEdit = new QLineEdit(Register);
        confirmPasswordEdit->setObjectName(QStringLiteral("confirmPasswordEdit"));
        confirmPasswordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(confirmPasswordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        backBtn = new QPushButton(Register);
        backBtn->setObjectName(QStringLiteral("backBtn"));

        horizontalLayout->addWidget(backBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        regConfirmBtn = new QPushButton(Register);
        regConfirmBtn->setObjectName(QStringLiteral("regConfirmBtn"));

        horizontalLayout->addWidget(regConfirmBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        exitBtn = new QPushButton(Register);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        horizontalLayout->addWidget(exitBtn);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(203, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 119, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 2, 1, 1, 1);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", nullptr));
        label->setText(QApplication::translate("Register", "\346\254\242\350\277\216\346\263\250\345\206\214\357\274\201", nullptr));
        label_2->setText(QApplication::translate("Register", "  \350\264\246   \345\217\267\357\274\232", nullptr));
        regUserEdit->setText(QString());
        label_3->setText(QApplication::translate("Register", "  \345\257\206   \347\240\201\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Register", " \347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        backBtn->setText(QApplication::translate("Register", "\344\270\212\344\270\200\346\255\245", nullptr));
        regConfirmBtn->setText(QApplication::translate("Register", "\347\241\256\350\256\244", nullptr));
        exitBtn->setText(QApplication::translate("Register", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
