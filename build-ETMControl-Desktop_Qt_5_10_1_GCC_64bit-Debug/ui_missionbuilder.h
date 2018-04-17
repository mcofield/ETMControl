/********************************************************************************
** Form generated from reading UI file 'missionbuilder.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MISSIONBUILDER_H
#define UI_MISSIONBUILDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MissionBuilder
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox_subsystem;
    QLabel *label_2;
    QComboBox *comboBox_action;
    QPushButton *pushButton_add;

    void setupUi(QDialog *MissionBuilder)
    {
        if (MissionBuilder->objectName().isEmpty())
            MissionBuilder->setObjectName(QStringLiteral("MissionBuilder"));
        MissionBuilder->resize(765, 514);
        widget = new QWidget(MissionBuilder);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 130, 281, 115));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboBox_subsystem = new QComboBox(widget);
        comboBox_subsystem->setObjectName(QStringLiteral("comboBox_subsystem"));

        verticalLayout->addWidget(comboBox_subsystem);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        comboBox_action = new QComboBox(widget);
        comboBox_action->setObjectName(QStringLiteral("comboBox_action"));

        verticalLayout->addWidget(comboBox_action);

        pushButton_add = new QPushButton(widget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        verticalLayout->addWidget(pushButton_add);


        retranslateUi(MissionBuilder);

        QMetaObject::connectSlotsByName(MissionBuilder);
    } // setupUi

    void retranslateUi(QDialog *MissionBuilder)
    {
        MissionBuilder->setWindowTitle(QApplication::translate("MissionBuilder", "Dialog", nullptr));
        label->setText(QApplication::translate("MissionBuilder", "<center>Sub-System:</center>", nullptr));
        label_2->setText(QApplication::translate("MissionBuilder", "<center>Action:</center>", nullptr));
        pushButton_add->setText(QApplication::translate("MissionBuilder", "Add To List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MissionBuilder: public Ui_MissionBuilder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISSIONBUILDER_H
