/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_HomeWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_builder;
    QCustomPlot *plot;
    QPushButton *pushButton_add;
    QPushButton *pushButton_clear;
    QDoubleSpinBox *bx_x;
    QDoubleSpinBox *bx_y;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_spoof;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_3;
    QLabel *label_tableStatus;
    QPushButton *pushButton_tableCommand;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioButton_tableSpace;
    QRadioButton *radioButton_tableHab;
    QRadioButton *radioButton_tableHome;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_4;
    QLabel *label_clampStatus;
    QPushButton *pushButton_clampCommand;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radioButton_clampRelease;
    QRadioButton *radioButton_clampSecure;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_15;
    QLabel *label_doorSpaceStatus;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_16;
    QLabel *label_doorHabStatus;
    QVBoxLayout *verticalLayout_10;
    QPushButton *pushButton_doorSpaceCommand;
    QPushButton *pushButton_doorHabCommand;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_doorSpaceOpen;
    QRadioButton *radioButton_doorSpaceClose;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_doorHabOpen;
    QRadioButton *radioButton_doorHabClose;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QLabel *label_lockSpaceStatus;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_14;
    QLabel *label_lockHabStatus;
    QVBoxLayout *verticalLayout_9;
    QPushButton *pushButton_lockSpaceCommand;
    QPushButton *pushButton_lockHabCommand;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_lockSpaceUnlock;
    QRadioButton *radioButton_lockSpaceLock;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton_lockHabUnlock;
    QRadioButton *radioButton_lockHabLock;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_7;
    QLabel *label_envStatus;
    QPushButton *pushButton_envCommand;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_envDepressurize;
    QRadioButton *radioButton_envPressurize;
    QLabel *label_model;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HomeWindow)
    {
        if (HomeWindow->objectName().isEmpty())
            HomeWindow->setObjectName(QStringLiteral("HomeWindow"));
        HomeWindow->resize(941, 662);
        centralwidget = new QWidget(HomeWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_builder = new QPushButton(centralwidget);
        pushButton_builder->setObjectName(QStringLiteral("pushButton_builder"));
        pushButton_builder->setGeometry(QRect(40, 560, 91, 21));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setGeometry(QRect(20, 330, 401, 211));
        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setGeometry(QRect(10, 300, 75, 23));
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(110, 300, 75, 23));
        bx_x = new QDoubleSpinBox(centralwidget);
        bx_x->setObjectName(QStringLiteral("bx_x"));
        bx_x->setGeometry(QRect(250, 300, 62, 22));
        bx_y = new QDoubleSpinBox(centralwidget);
        bx_y->setObjectName(QStringLiteral("bx_y"));
        bx_y->setGeometry(QRect(340, 300, 62, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 300, 47, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 300, 47, 13));
        pushButton_spoof = new QPushButton(centralwidget);
        pushButton_spoof->setObjectName(QStringLiteral("pushButton_spoof"));
        pushButton_spoof->setGeometry(QRect(150, 560, 75, 23));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(490, 0, 441, 621));
        verticalLayout_11 = new QVBoxLayout(layoutWidget);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_15->addWidget(label_3);

        label_tableStatus = new QLabel(layoutWidget);
        label_tableStatus->setObjectName(QStringLiteral("label_tableStatus"));

        horizontalLayout_15->addWidget(label_tableStatus);

        pushButton_tableCommand = new QPushButton(layoutWidget);
        pushButton_tableCommand->setObjectName(QStringLiteral("pushButton_tableCommand"));

        horizontalLayout_15->addWidget(pushButton_tableCommand);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        radioButton_tableSpace = new QRadioButton(layoutWidget);
        radioButton_tableSpace->setObjectName(QStringLiteral("radioButton_tableSpace"));

        horizontalLayout_7->addWidget(radioButton_tableSpace);

        radioButton_tableHab = new QRadioButton(layoutWidget);
        radioButton_tableHab->setObjectName(QStringLiteral("radioButton_tableHab"));

        horizontalLayout_7->addWidget(radioButton_tableHab);

        radioButton_tableHome = new QRadioButton(layoutWidget);
        radioButton_tableHome->setObjectName(QStringLiteral("radioButton_tableHome"));

        horizontalLayout_7->addWidget(radioButton_tableHome);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_11->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_14->addWidget(label_4);

        label_clampStatus = new QLabel(layoutWidget);
        label_clampStatus->setObjectName(QStringLiteral("label_clampStatus"));

        horizontalLayout_14->addWidget(label_clampStatus);

        pushButton_clampCommand = new QPushButton(layoutWidget);
        pushButton_clampCommand->setObjectName(QStringLiteral("pushButton_clampCommand"));

        horizontalLayout_14->addWidget(pushButton_clampCommand);


        verticalLayout_4->addLayout(horizontalLayout_14);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QStringLiteral("border:none"));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 10, 301, 30));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        radioButton_clampRelease = new QRadioButton(layoutWidget1);
        radioButton_clampRelease->setObjectName(QStringLiteral("radioButton_clampRelease"));

        horizontalLayout_6->addWidget(radioButton_clampRelease);

        radioButton_clampSecure = new QRadioButton(layoutWidget1);
        radioButton_clampSecure->setObjectName(QStringLiteral("radioButton_clampSecure"));

        horizontalLayout_6->addWidget(radioButton_clampSecure);


        verticalLayout_4->addWidget(groupBox_2);


        verticalLayout_11->addLayout(verticalLayout_4);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_12->addWidget(label_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_9->addWidget(label_15);

        label_doorSpaceStatus = new QLabel(layoutWidget);
        label_doorSpaceStatus->setObjectName(QStringLiteral("label_doorSpaceStatus"));

        horizontalLayout_9->addWidget(label_doorSpaceStatus);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_8->addWidget(label_16);

        label_doorHabStatus = new QLabel(layoutWidget);
        label_doorHabStatus->setObjectName(QStringLiteral("label_doorHabStatus"));

        horizontalLayout_8->addWidget(label_doorHabStatus);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_12->addLayout(verticalLayout_2);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        pushButton_doorSpaceCommand = new QPushButton(layoutWidget);
        pushButton_doorSpaceCommand->setObjectName(QStringLiteral("pushButton_doorSpaceCommand"));

        verticalLayout_10->addWidget(pushButton_doorSpaceCommand);

        pushButton_doorHabCommand = new QPushButton(layoutWidget);
        pushButton_doorHabCommand->setObjectName(QStringLiteral("pushButton_doorHabCommand"));

        verticalLayout_10->addWidget(pushButton_doorHabCommand);


        horizontalLayout_12->addLayout(verticalLayout_10);


        verticalLayout_8->addLayout(horizontalLayout_12);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral("border:none"));
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 357, 19));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_doorSpaceOpen = new QRadioButton(layoutWidget2);
        radioButton_doorSpaceOpen->setObjectName(QStringLiteral("radioButton_doorSpaceOpen"));

        horizontalLayout->addWidget(radioButton_doorSpaceOpen);

        radioButton_doorSpaceClose = new QRadioButton(layoutWidget2);
        radioButton_doorSpaceClose->setObjectName(QStringLiteral("radioButton_doorSpaceClose"));

        horizontalLayout->addWidget(radioButton_doorSpaceClose);


        verticalLayout_6->addWidget(groupBox);

        groupBox_5 = new QGroupBox(layoutWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setStyleSheet(QStringLiteral("border:none"));
        layoutWidget3 = new QWidget(groupBox_5);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, -2, 357, 21));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_doorHabOpen = new QRadioButton(layoutWidget3);
        radioButton_doorHabOpen->setObjectName(QStringLiteral("radioButton_doorHabOpen"));

        horizontalLayout_2->addWidget(radioButton_doorHabOpen);

        radioButton_doorHabClose = new QRadioButton(layoutWidget3);
        radioButton_doorHabClose->setObjectName(QStringLiteral("radioButton_doorHabClose"));

        horizontalLayout_2->addWidget(radioButton_doorHabClose);


        verticalLayout_6->addWidget(groupBox_5);


        verticalLayout_8->addLayout(verticalLayout_6);


        verticalLayout_11->addLayout(verticalLayout_8);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_13->addWidget(label_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_11->addWidget(label_13);

        label_lockSpaceStatus = new QLabel(layoutWidget);
        label_lockSpaceStatus->setObjectName(QStringLiteral("label_lockSpaceStatus"));

        horizontalLayout_11->addWidget(label_lockSpaceStatus);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_10->addWidget(label_14);

        label_lockHabStatus = new QLabel(layoutWidget);
        label_lockHabStatus->setObjectName(QStringLiteral("label_lockHabStatus"));

        horizontalLayout_10->addWidget(label_lockHabStatus);


        verticalLayout->addLayout(horizontalLayout_10);


        horizontalLayout_13->addLayout(verticalLayout);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        pushButton_lockSpaceCommand = new QPushButton(layoutWidget);
        pushButton_lockSpaceCommand->setObjectName(QStringLiteral("pushButton_lockSpaceCommand"));

        verticalLayout_9->addWidget(pushButton_lockSpaceCommand);

        pushButton_lockHabCommand = new QPushButton(layoutWidget);
        pushButton_lockHabCommand->setObjectName(QStringLiteral("pushButton_lockHabCommand"));

        verticalLayout_9->addWidget(pushButton_lockHabCommand);


        horizontalLayout_13->addLayout(verticalLayout_9);


        verticalLayout_5->addLayout(horizontalLayout_13);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setStyleSheet(QStringLiteral("border:none"));
        layoutWidget4 = new QWidget(groupBox_3);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(0, 0, 357, 19));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        radioButton_lockSpaceUnlock = new QRadioButton(layoutWidget4);
        radioButton_lockSpaceUnlock->setObjectName(QStringLiteral("radioButton_lockSpaceUnlock"));

        horizontalLayout_5->addWidget(radioButton_lockSpaceUnlock);

        radioButton_lockSpaceLock = new QRadioButton(layoutWidget4);
        radioButton_lockSpaceLock->setObjectName(QStringLiteral("radioButton_lockSpaceLock"));

        horizontalLayout_5->addWidget(radioButton_lockSpaceLock);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setStyleSheet(QStringLiteral("border:none"));
        layoutWidget5 = new QWidget(groupBox_4);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(0, 0, 357, 19));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        radioButton_lockHabUnlock = new QRadioButton(layoutWidget5);
        radioButton_lockHabUnlock->setObjectName(QStringLiteral("radioButton_lockHabUnlock"));

        horizontalLayout_4->addWidget(radioButton_lockHabUnlock);

        radioButton_lockHabLock = new QRadioButton(layoutWidget5);
        radioButton_lockHabLock->setObjectName(QStringLiteral("radioButton_lockHabLock"));

        horizontalLayout_4->addWidget(radioButton_lockHabLock);


        verticalLayout_5->addWidget(groupBox_4);


        verticalLayout_11->addLayout(verticalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_16->addWidget(label_7);

        label_envStatus = new QLabel(layoutWidget);
        label_envStatus->setObjectName(QStringLiteral("label_envStatus"));

        horizontalLayout_16->addWidget(label_envStatus);

        pushButton_envCommand = new QPushButton(layoutWidget);
        pushButton_envCommand->setObjectName(QStringLiteral("pushButton_envCommand"));

        horizontalLayout_16->addWidget(pushButton_envCommand);


        verticalLayout_7->addLayout(horizontalLayout_16);

        groupBox_7 = new QGroupBox(layoutWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setStyleSheet(QStringLiteral("border:none"));
        layoutWidget6 = new QWidget(groupBox_7);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(0, 0, 271, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton_envDepressurize = new QRadioButton(layoutWidget6);
        radioButton_envDepressurize->setObjectName(QStringLiteral("radioButton_envDepressurize"));

        horizontalLayout_3->addWidget(radioButton_envDepressurize);

        radioButton_envPressurize = new QRadioButton(layoutWidget6);
        radioButton_envPressurize->setObjectName(QStringLiteral("radioButton_envPressurize"));

        horizontalLayout_3->addWidget(radioButton_envPressurize);


        verticalLayout_7->addWidget(groupBox_7);


        verticalLayout_11->addLayout(verticalLayout_7);

        label_model = new QLabel(centralwidget);
        label_model->setObjectName(QStringLiteral("label_model"));
        label_model->setGeometry(QRect(20, 20, 421, 241));
        HomeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HomeWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 941, 21));
        HomeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(HomeWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        HomeWindow->setStatusBar(statusbar);

        retranslateUi(HomeWindow);

        QMetaObject::connectSlotsByName(HomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HomeWindow)
    {
        HomeWindow->setWindowTitle(QApplication::translate("HomeWindow", "MainWindow", nullptr));
        pushButton_builder->setText(QApplication::translate("HomeWindow", "Mission Builder", nullptr));
        pushButton_add->setText(QApplication::translate("HomeWindow", "Add", nullptr));
        pushButton_clear->setText(QApplication::translate("HomeWindow", "Clear", nullptr));
        label->setText(QApplication::translate("HomeWindow", "X", nullptr));
        label_2->setText(QApplication::translate("HomeWindow", "Y", nullptr));
        pushButton_spoof->setText(QApplication::translate("HomeWindow", "Spoof", nullptr));
        label_3->setText(QApplication::translate("HomeWindow", "Science Payload Table", nullptr));
        label_tableStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Home</font>", nullptr));
        pushButton_tableCommand->setText(QApplication::translate("HomeWindow", "Send Command", nullptr));
        radioButton_tableSpace->setText(QApplication::translate("HomeWindow", "Send Space-Side", nullptr));
        radioButton_tableHab->setText(QApplication::translate("HomeWindow", "Send Hab-Side", nullptr));
        radioButton_tableHome->setText(QApplication::translate("HomeWindow", "Send Home", nullptr));
        label_4->setText(QApplication::translate("HomeWindow", "Science Payload Clamp", nullptr));
        label_clampStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Secured</font>", nullptr));
        pushButton_clampCommand->setText(QApplication::translate("HomeWindow", "Send Command", nullptr));
        groupBox_2->setTitle(QString());
        radioButton_clampRelease->setText(QApplication::translate("HomeWindow", "Release Experiment", nullptr));
        radioButton_clampSecure->setText(QApplication::translate("HomeWindow", "Secure Experiment", nullptr));
        label_6->setText(QApplication::translate("HomeWindow", "Airlock Door", nullptr));
        label_15->setText(QApplication::translate("HomeWindow", "Space-Side:", nullptr));
        label_doorSpaceStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Closed</font>", nullptr));
        label_16->setText(QApplication::translate("HomeWindow", "Hab-Side:", nullptr));
        label_doorHabStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Closed</font>", nullptr));
        pushButton_doorSpaceCommand->setText(QApplication::translate("HomeWindow", "Send Command", nullptr));
        pushButton_doorHabCommand->setText(QApplication::translate("HomeWindow", "Send Command", nullptr));
        groupBox->setTitle(QString());
        radioButton_doorSpaceOpen->setText(QApplication::translate("HomeWindow", "Open Space-Side", nullptr));
        radioButton_doorSpaceClose->setText(QApplication::translate("HomeWindow", "Close Space-Side", nullptr));
        groupBox_5->setTitle(QString());
        radioButton_doorHabOpen->setText(QApplication::translate("HomeWindow", "Open Hab-Side", nullptr));
        radioButton_doorHabClose->setText(QApplication::translate("HomeWindow", "Close Hab-Side", nullptr));
        label_5->setText(QApplication::translate("HomeWindow", "Airlock Door Locks", nullptr));
        label_13->setText(QApplication::translate("HomeWindow", "Space-Side:", nullptr));
        label_lockSpaceStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Locked</font>", nullptr));
        label_14->setText(QApplication::translate("HomeWindow", "Hab-Side:", nullptr));
        label_lockHabStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Locked</font>", nullptr));
        pushButton_lockSpaceCommand->setText(QApplication::translate("HomeWindow", "Send Command", nullptr));
        pushButton_lockHabCommand->setText(QApplication::translate("HomeWindow", "Send Command", nullptr));
        groupBox_3->setTitle(QString());
        radioButton_lockSpaceUnlock->setText(QApplication::translate("HomeWindow", "Unlock Space-Side", nullptr));
        radioButton_lockSpaceLock->setText(QApplication::translate("HomeWindow", "Lock Space-Side", nullptr));
        groupBox_4->setTitle(QString());
        radioButton_lockHabUnlock->setText(QApplication::translate("HomeWindow", "Unlock Hab-Side", nullptr));
        radioButton_lockHabLock->setText(QApplication::translate("HomeWindow", "Lock Hab-Side", nullptr));
        label_7->setText(QApplication::translate("HomeWindow", "Environment", nullptr));
        label_envStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Pressurized</font>", nullptr));
        pushButton_envCommand->setText(QApplication::translate("HomeWindow", "Send Command", nullptr));
        groupBox_7->setTitle(QString());
        radioButton_envDepressurize->setText(QApplication::translate("HomeWindow", "Depressurize", nullptr));
        radioButton_envPressurize->setText(QApplication::translate("HomeWindow", "Pressurize", nullptr));
        label_model->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
