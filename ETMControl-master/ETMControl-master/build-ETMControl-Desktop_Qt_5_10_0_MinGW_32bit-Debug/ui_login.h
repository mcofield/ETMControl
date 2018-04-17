/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QAction *action_closeProgram;
    QAction *action_switchUser;
    QAction *action_userManual;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_login;
    QPushButton *pushButton_2;
    QLabel *label_logo;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuExit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(579, 370);
        action_closeProgram = new QAction(Login);
        action_closeProgram->setObjectName(QStringLiteral("action_closeProgram"));
        action_switchUser = new QAction(Login);
        action_switchUser->setObjectName(QStringLiteral("action_switchUser"));
        action_userManual = new QAction(Login);
        action_userManual->setObjectName(QStringLiteral("action_userManual"));
        centralWidget = new QWidget(Login);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(220, 40, 321, 201));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 321, 191));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_username = new QLabel(layoutWidget);
        label_username->setObjectName(QStringLiteral("label_username"));

        horizontalLayout->addWidget(label_username);

        lineEdit_username = new QLineEdit(layoutWidget);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));

        horizontalLayout->addWidget(lineEdit_username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_password = new QLabel(layoutWidget);
        label_password->setObjectName(QStringLiteral("label_password"));

        horizontalLayout_2->addWidget(label_password);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_login = new QPushButton(layoutWidget);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));

        horizontalLayout_3->addWidget(pushButton_login);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_logo = new QLabel(centralWidget);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setGeometry(QRect(10, 60, 121, 111));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 0, 111, 31));
        Login->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Login);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 579, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuExit = new QMenu(menuBar);
        menuExit->setObjectName(QStringLiteral("menuExit"));
        Login->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Login);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Login->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Login);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Login->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuExit->menuAction());
        menuFile->addAction(action_switchUser);
        menuHelp->addAction(action_userManual);
        menuExit->addAction(action_closeProgram);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", nullptr));
        action_closeProgram->setText(QApplication::translate("Login", "Close Program", nullptr));
        action_switchUser->setText(QApplication::translate("Login", "Switch User", nullptr));
        action_userManual->setText(QApplication::translate("Login", "User Manual", nullptr));
        groupBox->setTitle(QApplication::translate("Login", "Sign In", nullptr));
        label_username->setText(QApplication::translate("Login", "Username:", nullptr));
        label_password->setText(QApplication::translate("Login", "Password:", nullptr));
        pushButton_login->setText(QApplication::translate("Login", "Login", nullptr));
        pushButton_2->setText(QApplication::translate("Login", "Shut Down", nullptr));
        label_logo->setText(QString());
        label->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; color:#ff0000;\">ETM Login</span></p></body></html>", nullptr));
        menuFile->setTitle(QApplication::translate("Login", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("Login", "Help", nullptr));
        menuExit->setTitle(QApplication::translate("Login", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
