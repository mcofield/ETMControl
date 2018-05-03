/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_HomeWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_home;
    QLabel *label_animation;
    QCustomPlot *plot;
    QWidget *layoutWidget;
    QVBoxLayout *StatusAndSelection;
    QHBoxLayout *TableStatus;
    QLabel *label;
    QLabel *label_tableStatus;
    QHBoxLayout *TableButtons;
    QRadioButton *radioButton_tableSPC;
    QRadioButton *radioButton_tableHOME;
    QRadioButton *radioButton_tableHAB;
    QHBoxLayout *ClampStatus;
    QLabel *label_2;
    QLabel *label_clampStatus;
    QHBoxLayout *ClampButtons;
    QRadioButton *radioButton_clampEngage;
    QRadioButton *radioButton_clampRelease;
    QHBoxLayout *SPCDoorStatus;
    QLabel *label_4;
    QLabel *label_doorSPCStatus;
    QHBoxLayout *SPCDoorButtons;
    QRadioButton *radioButton_doorSPCOpen;
    QRadioButton *radioButton_doorSPCClose;
    QHBoxLayout *HabDoorStatus;
    QLabel *label_6;
    QLabel *label_doorHABStatus;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_doorHABOpen;
    QRadioButton *radioButton_doorHABClose;
    QHBoxLayout *EnvStatus;
    QLabel *label_3;
    QLabel *label_envStatus;
    QHBoxLayout *EnvButtons;
    QRadioButton *radioButton_envDepressurize;
    QRadioButton *radioButton_envPressurize;
    QPushButton *pushButton_test;
    QPushButton *pushButton_stop;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_tableCommand;
    QPushButton *pushButton_clampCommand;
    QPushButton *pushButton_doorSPCCommand;
    QPushButton *pushButton_doorHABCommand;
    QPushButton *pushButton_envCommand;
    QPushButton *pushButton_test_2;
    QWidget *tab_missionBuilder;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QComboBox *comboBox_subsystem;
    QLabel *label_7;
    QComboBox *comboBox_action;
    QPushButton *pushButton_add;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HomeWindow)
    {
        if (HomeWindow->objectName().isEmpty())
            HomeWindow->setObjectName(QStringLiteral("HomeWindow"));
        HomeWindow->resize(800, 480);
        centralwidget = new QWidget(HomeWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 780, 480));
        tab_home = new QWidget();
        tab_home->setObjectName(QStringLiteral("tab_home"));
        label_animation = new QLabel(tab_home);
        label_animation->setObjectName(QStringLiteral("label_animation"));
        label_animation->setGeometry(QRect(0, 10, 331, 171));
        plot = new QCustomPlot(tab_home);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setGeometry(QRect(0, 190, 351, 191));
        layoutWidget = new QWidget(tab_home);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(351, 21, 328, 316));
        StatusAndSelection = new QVBoxLayout(layoutWidget);
        StatusAndSelection->setObjectName(QStringLiteral("StatusAndSelection"));
        StatusAndSelection->setContentsMargins(0, 0, 0, 0);
        TableStatus = new QHBoxLayout();
        TableStatus->setObjectName(QStringLiteral("TableStatus"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        TableStatus->addWidget(label);

        label_tableStatus = new QLabel(layoutWidget);
        label_tableStatus->setObjectName(QStringLiteral("label_tableStatus"));

        TableStatus->addWidget(label_tableStatus);


        StatusAndSelection->addLayout(TableStatus);

        TableButtons = new QHBoxLayout();
        TableButtons->setObjectName(QStringLiteral("TableButtons"));
        radioButton_tableSPC = new QRadioButton(layoutWidget);
        radioButton_tableSPC->setObjectName(QStringLiteral("radioButton_tableSPC"));

        TableButtons->addWidget(radioButton_tableSPC);

        radioButton_tableHOME = new QRadioButton(layoutWidget);
        radioButton_tableHOME->setObjectName(QStringLiteral("radioButton_tableHOME"));

        TableButtons->addWidget(radioButton_tableHOME);

        radioButton_tableHAB = new QRadioButton(layoutWidget);
        radioButton_tableHAB->setObjectName(QStringLiteral("radioButton_tableHAB"));

        TableButtons->addWidget(radioButton_tableHAB);


        StatusAndSelection->addLayout(TableButtons);

        ClampStatus = new QHBoxLayout();
        ClampStatus->setObjectName(QStringLiteral("ClampStatus"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        ClampStatus->addWidget(label_2);

        label_clampStatus = new QLabel(layoutWidget);
        label_clampStatus->setObjectName(QStringLiteral("label_clampStatus"));

        ClampStatus->addWidget(label_clampStatus);


        StatusAndSelection->addLayout(ClampStatus);

        ClampButtons = new QHBoxLayout();
        ClampButtons->setObjectName(QStringLiteral("ClampButtons"));
        radioButton_clampEngage = new QRadioButton(layoutWidget);
        radioButton_clampEngage->setObjectName(QStringLiteral("radioButton_clampEngage"));

        ClampButtons->addWidget(radioButton_clampEngage);

        radioButton_clampRelease = new QRadioButton(layoutWidget);
        radioButton_clampRelease->setObjectName(QStringLiteral("radioButton_clampRelease"));

        ClampButtons->addWidget(radioButton_clampRelease);


        StatusAndSelection->addLayout(ClampButtons);

        SPCDoorStatus = new QHBoxLayout();
        SPCDoorStatus->setObjectName(QStringLiteral("SPCDoorStatus"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        SPCDoorStatus->addWidget(label_4);

        label_doorSPCStatus = new QLabel(layoutWidget);
        label_doorSPCStatus->setObjectName(QStringLiteral("label_doorSPCStatus"));

        SPCDoorStatus->addWidget(label_doorSPCStatus);


        StatusAndSelection->addLayout(SPCDoorStatus);

        SPCDoorButtons = new QHBoxLayout();
        SPCDoorButtons->setObjectName(QStringLiteral("SPCDoorButtons"));
        radioButton_doorSPCOpen = new QRadioButton(layoutWidget);
        radioButton_doorSPCOpen->setObjectName(QStringLiteral("radioButton_doorSPCOpen"));

        SPCDoorButtons->addWidget(radioButton_doorSPCOpen);

        radioButton_doorSPCClose = new QRadioButton(layoutWidget);
        radioButton_doorSPCClose->setObjectName(QStringLiteral("radioButton_doorSPCClose"));

        SPCDoorButtons->addWidget(radioButton_doorSPCClose);


        StatusAndSelection->addLayout(SPCDoorButtons);

        HabDoorStatus = new QHBoxLayout();
        HabDoorStatus->setObjectName(QStringLiteral("HabDoorStatus"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        HabDoorStatus->addWidget(label_6);

        label_doorHABStatus = new QLabel(layoutWidget);
        label_doorHABStatus->setObjectName(QStringLiteral("label_doorHABStatus"));

        HabDoorStatus->addWidget(label_doorHABStatus);


        StatusAndSelection->addLayout(HabDoorStatus);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_doorHABOpen = new QRadioButton(layoutWidget);
        radioButton_doorHABOpen->setObjectName(QStringLiteral("radioButton_doorHABOpen"));

        horizontalLayout->addWidget(radioButton_doorHABOpen);

        radioButton_doorHABClose = new QRadioButton(layoutWidget);
        radioButton_doorHABClose->setObjectName(QStringLiteral("radioButton_doorHABClose"));

        horizontalLayout->addWidget(radioButton_doorHABClose);


        StatusAndSelection->addLayout(horizontalLayout);

        EnvStatus = new QHBoxLayout();
        EnvStatus->setObjectName(QStringLiteral("EnvStatus"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        EnvStatus->addWidget(label_3);

        label_envStatus = new QLabel(layoutWidget);
        label_envStatus->setObjectName(QStringLiteral("label_envStatus"));

        EnvStatus->addWidget(label_envStatus);


        StatusAndSelection->addLayout(EnvStatus);

        EnvButtons = new QHBoxLayout();
        EnvButtons->setObjectName(QStringLiteral("EnvButtons"));
        radioButton_envDepressurize = new QRadioButton(layoutWidget);
        radioButton_envDepressurize->setObjectName(QStringLiteral("radioButton_envDepressurize"));

        EnvButtons->addWidget(radioButton_envDepressurize);

        radioButton_envPressurize = new QRadioButton(layoutWidget);
        radioButton_envPressurize->setObjectName(QStringLiteral("radioButton_envPressurize"));

        EnvButtons->addWidget(radioButton_envPressurize);


        StatusAndSelection->addLayout(EnvButtons);

        pushButton_test = new QPushButton(tab_home);
        pushButton_test->setObjectName(QStringLiteral("pushButton_test"));
        pushButton_test->setGeometry(QRect(550, 460, 91, 29));
        pushButton_stop = new QPushButton(tab_home);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(660, 460, 91, 29));
        layoutWidget1 = new QWidget(tab_home);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(680, 20, 95, 351));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_tableCommand = new QPushButton(layoutWidget1);
        pushButton_tableCommand->setObjectName(QStringLiteral("pushButton_tableCommand"));

        verticalLayout_2->addWidget(pushButton_tableCommand);

        pushButton_clampCommand = new QPushButton(layoutWidget1);
        pushButton_clampCommand->setObjectName(QStringLiteral("pushButton_clampCommand"));

        verticalLayout_2->addWidget(pushButton_clampCommand);

        pushButton_doorSPCCommand = new QPushButton(layoutWidget1);
        pushButton_doorSPCCommand->setObjectName(QStringLiteral("pushButton_doorSPCCommand"));

        verticalLayout_2->addWidget(pushButton_doorSPCCommand);

        pushButton_doorHABCommand = new QPushButton(layoutWidget1);
        pushButton_doorHABCommand->setObjectName(QStringLiteral("pushButton_doorHABCommand"));

        verticalLayout_2->addWidget(pushButton_doorHABCommand);

        pushButton_envCommand = new QPushButton(layoutWidget1);
        pushButton_envCommand->setObjectName(QStringLiteral("pushButton_envCommand"));

        verticalLayout_2->addWidget(pushButton_envCommand);

        pushButton_test_2 = new QPushButton(tab_home);
        pushButton_test_2->setObjectName(QStringLiteral("pushButton_test_2"));
        pushButton_test_2->setGeometry(QRect(420, 350, 161, 29));
        tabWidget->addTab(tab_home, QString());
        tab_missionBuilder = new QWidget();
        tab_missionBuilder->setObjectName(QStringLiteral("tab_missionBuilder"));
        layoutWidget_2 = new QWidget(tab_missionBuilder);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 100, 281, 155));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        comboBox_subsystem = new QComboBox(layoutWidget_2);
        comboBox_subsystem->setObjectName(QStringLiteral("comboBox_subsystem"));

        verticalLayout->addWidget(comboBox_subsystem);

        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        comboBox_action = new QComboBox(layoutWidget_2);
        comboBox_action->setObjectName(QStringLiteral("comboBox_action"));

        verticalLayout->addWidget(comboBox_action);

        pushButton_add = new QPushButton(layoutWidget_2);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        verticalLayout->addWidget(pushButton_add);

        tabWidget->addTab(tab_missionBuilder, QString());
        HomeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HomeWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        HomeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(HomeWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        HomeWindow->setStatusBar(statusbar);

        retranslateUi(HomeWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HomeWindow)
    {
        HomeWindow->setWindowTitle(QApplication::translate("HomeWindow", "MainWindow", Q_NULLPTR));
        label_animation->setText(QApplication::translate("HomeWindow", "Animation", Q_NULLPTR));
        label->setText(QApplication::translate("HomeWindow", "Science Payload Table Position:", Q_NULLPTR));
        label_tableStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Home<font>", Q_NULLPTR));
        radioButton_tableSPC->setText(QApplication::translate("HomeWindow", "Send Space", Q_NULLPTR));
        radioButton_tableHOME->setText(QApplication::translate("HomeWindow", "Send Home", Q_NULLPTR));
        radioButton_tableHAB->setText(QApplication::translate("HomeWindow", "Send Hab", Q_NULLPTR));
        label_2->setText(QApplication::translate("HomeWindow", "Science Payload Table Clamp:", Q_NULLPTR));
        label_clampStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Engaged<font>", Q_NULLPTR));
        radioButton_clampEngage->setText(QApplication::translate("HomeWindow", "Clamp Experiment", Q_NULLPTR));
        radioButton_clampRelease->setText(QApplication::translate("HomeWindow", "Release Experiment", Q_NULLPTR));
        label_4->setText(QApplication::translate("HomeWindow", "Space Door Position:", Q_NULLPTR));
        label_doorSPCStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Closed<font>", Q_NULLPTR));
        radioButton_doorSPCOpen->setText(QApplication::translate("HomeWindow", "Open Door", Q_NULLPTR));
        radioButton_doorSPCClose->setText(QApplication::translate("HomeWindow", "Close Door", Q_NULLPTR));
        label_6->setText(QApplication::translate("HomeWindow", "Hab Door Position:", Q_NULLPTR));
        label_doorHABStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Closed<font>", Q_NULLPTR));
        radioButton_doorHABOpen->setText(QApplication::translate("HomeWindow", "Open Door", Q_NULLPTR));
        radioButton_doorHABClose->setText(QApplication::translate("HomeWindow", "Close Door", Q_NULLPTR));
        label_3->setText(QApplication::translate("HomeWindow", "Airlock Pressure:", Q_NULLPTR));
        label_envStatus->setText(QApplication::translate("HomeWindow", "<font color=green>Pressurized<font>", Q_NULLPTR));
        radioButton_envDepressurize->setText(QApplication::translate("HomeWindow", "Depressurize", Q_NULLPTR));
        radioButton_envPressurize->setText(QApplication::translate("HomeWindow", "Pressurize", Q_NULLPTR));
        pushButton_test->setText(QApplication::translate("HomeWindow", "Test", Q_NULLPTR));
        pushButton_stop->setText(QApplication::translate("HomeWindow", "Stop", Q_NULLPTR));
        pushButton_tableCommand->setText(QApplication::translate("HomeWindow", "Send", Q_NULLPTR));
        pushButton_clampCommand->setText(QApplication::translate("HomeWindow", "Send", Q_NULLPTR));
        pushButton_doorSPCCommand->setText(QApplication::translate("HomeWindow", "Send", Q_NULLPTR));
        pushButton_doorHABCommand->setText(QApplication::translate("HomeWindow", "Send", Q_NULLPTR));
        pushButton_envCommand->setText(QApplication::translate("HomeWindow", "Send", Q_NULLPTR));
        pushButton_test_2->setText(QApplication::translate("HomeWindow", "Simulate Timestep", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_home), QApplication::translate("HomeWindow", "Home", Q_NULLPTR));
        label_5->setText(QApplication::translate("HomeWindow", "<center>Sub-System:</center>", Q_NULLPTR));
        label_7->setText(QApplication::translate("HomeWindow", "<center>Action:</center>", Q_NULLPTR));
        pushButton_add->setText(QApplication::translate("HomeWindow", "Add To List", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_missionBuilder), QApplication::translate("HomeWindow", "Mission Builder", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
