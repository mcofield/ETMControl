#include "missionbuilder.h"
#include "ui_missionbuilder.h"
#include <QStringList>
#include <QMessageBox>
#include <QComboBox>

MissionBuilder::MissionBuilder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MissionBuilder)
{
    ui->setupUi(this);
    subsystems << "V-Slot" << "Table Clamp" << "Door Locks" << "Door Actuators" << "Environment";
    vSlot << "Send table home" << "Send table habitat-side" << "Send table space-side";
    clamp << "Clamp experiment" << "Release experiment";
    lock << "Extend habitat-side locks" << "Retract habitat-side locks" << "Extend space-side locks" << "Retract space-side locks";
    door << "Open habitat-side door" << "Close habitat-side door" << "Open space-side door" << "Close space-side door";
    env << "Pressurize" << "Depressurize";
    ui->comboBox_subsystem->addItems(subsystems);
}

MissionBuilder::~MissionBuilder()
{
    delete ui;
}


void MissionBuilder::on_pushButton_add_clicked()
{
    if(ui->comboBox_action->currentIndex()==0){
        QMessageBox::information(this,"test","0");
    }
    if(ui->comboBox_action->currentIndex()==1){
        QMessageBox::information(this,"test","1");
    }
    if(ui->comboBox_action->currentIndex()==2){
        QMessageBox::information(this,"test","2");
    }
    if(ui->comboBox_action->currentIndex()==3){
        QMessageBox::information(this,"test","3");
    }
}

void MissionBuilder::on_comboBox_subsystem_currentIndexChanged(int index)
{
    ui->comboBox_action->clear();
    if(ui->comboBox_subsystem->currentIndex()==0){
        ui->comboBox_action->addItems(this->vSlot);
    }
    else if(ui->comboBox_subsystem->currentIndex()==1){
        ui->comboBox_action->addItems(this->clamp);
    }
    else if(ui->comboBox_subsystem->currentIndex()==2){
        ui->comboBox_action->addItems(this->lock);
    }
    else if(ui->comboBox_subsystem->currentIndex()==3){
        ui->comboBox_action->addItems(this->door);
    }
    else if(ui->comboBox_subsystem->currentIndex()==4){
        ui->comboBox_action->addItems(this->env);
    }
}
