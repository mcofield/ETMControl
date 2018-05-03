#include "homewindow.h"
#include "communication.h"
#include "buffer.h"
#include "ui_homewindow.h"

#include <QMessageBox>
#include <QLabel>
#include <QWidget>
#include <QTime>
#include <QPixmap>
#include <QSerialPort>
#include <QQueue>
#include <QStringList>
#include <QComboBox>
//#include <sys/time.h>
#include <chrono>
#include <QtMath>
#include <stdlib.h>
#include <cstdlib>
#include <thread>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
#include <stdio.h>
#include <iostream>

QSerialPort serial;
QSerialPort serialLED;
Buffer buffer;

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);

//%%%%%%%%%%%%%%%%%%%%%%% Main Tab %%%%%%%%%%%%%%%%%%%%%%%%

//Sets up the transmission and received logging files
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    date = std::ctime(&end_time);
    strcpy(TX,"/home/pi/TXLogs/");
    strcat(TX,date);
    strcat(TX,".txt");
    strcpy(RX,"/home/pi/RXLogs/");
    strcat(RX,date);
    strcat(RX,".txt");
    fileTX.open(TX);
    fileRX.open(RX);

//Setup of the real-time graph
    ui->plot->addGraph();
//    ui->plot->QCPAxisRect::setRangeDrag(Qt::Horizontal);
    ui->plot->setInteraction(QCP::iRangeDrag,true);
    ui->plot->xAxis->setLabel("Time Since Startup (seconds)");
    ui->plot->yAxis->setLabel("Pressure (kPa)");
    ui->plot->xAxis->setRange(0,120);
    ui->plot->yAxis->setRange(0,120);

//Setup of the airlock status model
    QPixmap pix(":/img/modelStates/pressurizedEmpty.png");
    ui->label_animation->setPixmap(pix);
    int logoWidth = ui->label_animation->width();
    int logoHeight = ui->label_animation->height();
    ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));

//Opening and setting up serial communication with MSP432
    serial.setPortName("ttyACM1");
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);

    if(serial.isOpen()){
        qDebug()<<"Opened serial";
    }

//Opening and setting up serial communication with Arduino for LEDS
    serialLED.setPortName("ttyACM0");
    serialLED.setBaudRate(QSerialPort::Baud9600);
    serialLED.setDataBits(QSerialPort::Data8);
    serialLED.setParity(QSerialPort::NoParity);
    serialLED.setStopBits(QSerialPort::OneStop);
    serialLED.setFlowControl(QSerialPort::NoFlowControl);
    serialLED.open(QIODevice::ReadWrite);
    if(serialLED.isOpen()){
        qDebug()<<"Opened serialLED";
    }

//Set up connection between readRead() signal from serial port and reading, logging, and acting on received packet
    QObject::connect(&serial, &QSerialPort::readyRead,[&]
    {
        QByteArray data = serial.readAll();
        //mutex->lock()
        qDebug()<<"Got the Connect";
        qDebug()<< "Got this: "<< data;
        //fileRX.write(date);
        unsigned long curr = std::chrono::system_clock::now().time_since_epoch() /
                std::chrono::milliseconds(1);
        double timeStamp = (curr-startupTime)/1000;
        fileRX << timeStamp;
        fileRX << ": ";
        fileRX << +data.data();
        fileRX << '\n';
        for(int i = 0;i<data.size();i++){
            if(data[i]=='\n'){
                qDebug()<<"Passed Conditional 1";
                if(buffer.queue.size()==3){
                    qDebug()<<"Passed Conditional 2";
                    uint8_t temp = buffer.queue.dequeue();
                    uint8_t first = temp & 0b11000000;
                    uint8_t second = temp & 0b00111111;
                              CommPacket *currentPacket = new CommPacket(first,second,buffer.queue.dequeue(),buffer.queue.dequeue());
                    parsePacket(currentPacket);
                    delete currentPacket;
                }
                else{
                    data.clear();
                    //corrupt packet
                }
            }
            else{
                buffer.queue.enqueue(data[i]);
            }
        }
    });

//%%%%%%%%%%%%%%%%%%%%%%% Mission Builder Tab %%%%%%%%%%%%%%%%%%%%%%%%
    subsystems << "V-Slot" << "Table Clamp" << "Door Locks" << "Door Actuators" << "Environment";
    vSlot << "Send table home" << "Send table habitat-side" << "Send table space-side";
    clamp << "Clamp experiment" << "Release experiment";
    lock << "Extend habitat-side locks" << "Retract habitat-side locks" << "Extend space-side locks" << "Retract space-side locks";
    door << "Open habitat-side door" << "Close habitat-side door" << "Open space-side door" << "Close space-side door";
    env << "Pressurize" << "Depressurize";
    ui->comboBox_subsystem->addItems(subsystems);

}

HomeWindow::~HomeWindow(){
    delete ui;
    serialLED.write("0");
    serial.close();
    serialLED.close();
    fileTX.close();
    fileRX.close();
}

Buffer::Buffer(){
}

CommPacket::CommPacket (uint8_t typ,uint8_t com, uint8_t len, uint8_t dat){
    this->type = typ;
    this->command = com;
    this->length = len;
    this->data = dat;
}

void CommPacket::sendPacket(std::ofstream &file, unsigned long start){
//    unsigned char * ptr = &msg.type;
    QByteArray temp;
    QByteArray expo;
    expo.resize(1);
    expo[0] = type | command;
    temp.resize(4);
    temp[0] = type | command;
    temp[1] = length;
    temp[2] = data;
    temp[3] = '\n';
    serial.write(expo, 1);

    unsigned long current = std::chrono::system_clock::now().time_since_epoch() /
            std::chrono::milliseconds(1);
    double timestamp = current-start;
    file<<timestamp;
    file<<": ";
    file<<+type;
    file<<"/";
    file<<+command;
    file<<"/";
    file<<+length;
    file<<"/";
    file<<+data;
    file<<'\n';

}

void HomeWindow::parsePacket(CommPacket *packet){
    switch(packet->type){
    case 0b10000000:{ //commands
        //this shouldn't happen
        qDebug()<<"Something went wrong. Shouldn't be receiving commands.";
        break;
    }
    case 0b01000000:{ //data
        switch(packet->command){
        case 0b00100000:{ //0x20
            //table cap sensor data
            if(packet->data==0){
                tableCapStatus = 0;
            }
            else{
                tableCapStatus = 1;
            }
            experimentStatus();
            break;
        }
        case 0b00100001:{ //0x21
            //clamp cap sensor data
            if(packet->data==0){
                clampCapStatus = 0;
            }
            else{
                clampCapStatus = 1;
            }
            experimentStatus();
            break;
        }
        case 0b00100010:{ //0x22
            //table force sensor data
            qDebug()<<"Force sensor data: "<<packet->data;
            if(packet->data==0){ //CHANGE VALUE AFTER TESTING
                clampForceStatus = 0;
            }
            else{
                clampForceStatus = 1;
            }
            experimentStatus();
            break;
        }
        case 0b00100100:{ //0x23
            //Table Position
            switch(packet->data){
            case 0b00000100:{
                //space
                tablePos = -1;
                break;
            }
            case 0b00000010:{
                //home
                tablePos = 0;
                break;
            }
            case 0b00000001:{
                //hab
                tablePos = 1;
                break;
            }
            }
            break;
        }
        case 0b00101000:{ //0x24
            //Fake Pressure data
            unsigned long currentTime = std::chrono::system_clock::now().time_since_epoch() /
                    std::chrono::milliseconds(1);
            double diff = (currentTime - startupTime);
            double timeSinceChange = diff-timeOfChange;
            double noise = std::rand()/RAND_MAX;
            if(pressureState==-1){
                pressure = 101.325*(1+noise)*qExp(-0.1*(timeSinceChange/1000));
            }
            else{
                pressure = 101.325*(1+noise)*(1-qExp(-0.1*(timeSinceChange/1000)));
            }
            qv_x.append(diff/1000);
            qv_y.append(pressure);
            plot();
            if (qv_y.last()>=100){
                ui->label_envStatus->setText("<font color=green>Pressurized</font>");
            }
            else{
                ui->label_envStatus->setText("<font color=orange>Deressurized</font>");
            }
            break;
        }
        case 0b00110000:{ //0x25
            //HAB Hinge Hall effect sensor data
            if(packet->data==0){
                ui->label_doorHABStatus->setText("<font color=green>Closed</font>");
            }
            else{
                ui->label_doorHABStatus->setText("<font color=orange>Open</font>");
            }
            break;
        }
        case 0b00100110:{ //0x26
            //SPC Hinge Hall effect sensor data
            if(packet->data==0){
                ui->label_doorSPCStatus->setText("<font color=green>Closed</font>");
            }
            else{
                ui->label_doorSPCStatus->setText("<font color=orange>Open</font>");
            }
            break;
        }
        default:
            //this shouldn't happen
            qDebug()<<"Something went wrong. Unknown data type.";
            break;
        }

        break;
    }
    default:
        //shouldn't happen
        qDebug()<<"Something went wrong. Not command or data.";
        break;
    }
    airlockStatus();
}


void HomeWindow::addPoint(double x, double y){
    qv_x.append(x);
    qv_y.append(y);
}

void HomeWindow::clearData(){
    qv_x.clear();
    qv_y.clear();
}

void HomeWindow::plot(){
    ui->plot->graph(0)->setData(qv_x,qv_y);
    ui->plot->replot();
    ui->plot->update();
}

bool HomeWindow::experimentStatus(){
    if(clampCapStatus){
        ui->label_clampStatus->setText("<font color=green>Secured</font>");
        return true;
    }
    else{
        ui->label_clampStatus->setText("<font color=green>Released</font>");
        return false;
    }
}

void HomeWindow::airlockStatus(){
    if (pressureState == -1){
        if(doorSPC == 1){
            if(tablePos == -1){
                if(experimentStatus()){
                    QPixmap pix(":/img/modelStates/spaceExtendedMounted.png");
                    ui->label_animation->setPixmap(pix);
                    int logoWidth = ui->label_animation->width();
                    int logoHeight = ui->label_animation->height();
                    ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
                }
                else{
                    QPixmap pix(":/img/modelStates/spaceExtendedEmpty.png");
                    ui->label_animation->setPixmap(pix);
                    int logoWidth = ui->label_animation->width();
                    int logoHeight = ui->label_animation->height();
                    ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
                }
            }
            if(tablePos == 0){
                if(experimentStatus()){
                    QPixmap pix(":/img/modelStates/spaceOpenMounted.png");
                    ui->label_animation->setPixmap(pix);
                    int logoWidth = ui->label_animation->width();
                    int logoHeight = ui->label_animation->height();
                    ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
                }
                else{
                    QPixmap pix(":/img/modelStates/spaceOpenEmpty.png");
                    ui->label_animation->setPixmap(pix);
                    int logoWidth = ui->label_animation->width();
                    int logoHeight = ui->label_animation->height();
                    ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
                }
            }
        }
        else{
            if(experimentStatus()){
                QPixmap pix(":/img/modelStates/depressurizedMounted.png");
                ui->label_animation->setPixmap(pix);
                int logoWidth = ui->label_animation->width();
                int logoHeight = ui->label_animation->height();
                ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
            }
            else{
                QPixmap pix(":/img/modelStates/depressurizedEmpty.png");
                ui->label_animation->setPixmap(pix);
                int logoWidth = ui->label_animation->width();
                int logoHeight = ui->label_animation->height();
                ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
            }
        }
    }
    else{
        if(doorHAB == 1){
            if(tablePos == 1){
                if(experimentStatus()){
                    QPixmap pix(":/img/modelStates/habExtendedMounted.png");
                    ui->label_animation->setPixmap(pix);
                    int logoWidth = ui->label_animation->width();
                    int logoHeight = ui->label_animation->height();
                    ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
                }
                else{
                    QPixmap pix(":/img/modelStates/habExtendedEmpty.png");
                    ui->label_animation->setPixmap(pix);
                    int logoWidth = ui->label_animation->width();
                    int logoHeight = ui->label_animation->height();
                    ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
                }
            }
            if(tablePos == 0){
                if(experimentStatus()){
                    QPixmap pix(":/img/modelStates/habOpenMounted.png");
                    ui->label_animation->setPixmap(pix);
                    int logoWidth = ui->label_animation->width();
                    int logoHeight = ui->label_animation->height();
                    ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
                }
                else{
                    QPixmap pix(":/img/modelStates/habOpenEmpty.png");
                    ui->label_animation->setPixmap(pix);
                    int logoWidth = ui->label_animation->width();
                    int logoHeight = ui->label_animation->height();
                    ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
                }
            }
        }
        else{
            if(experimentStatus()){
                QPixmap pix(":/img/modelStates/pressurizedMounted.png");
                ui->label_animation->setPixmap(pix);
                int logoWidth = ui->label_animation->width();
                int logoHeight = ui->label_animation->height();
                ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
            }
            else{
                QPixmap pix(":/img/modelStates/pressurizedEmpty.png");
                ui->label_animation->setPixmap(pix);
                int logoWidth = ui->label_animation->width();
                int logoHeight = ui->label_animation->height();
                ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
            }
        }
    }
}

void HomeWindow::on_pushButton_tableCommand_clicked(){
    if(ui->radioButton_tableHAB->isChecked()){
        ui->label_tableStatus->setText("<font color=orange>Hab-side</font>");
        CommPacket packet((uint8_t)0b10000000,(uint8_t)0x13,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket(fileTX,startupTime);

//        qDebug()<< "sent dis: "<< packet;
        QPixmap pix(":/img/modelStates/habExtendedEmpty.png");
        ui->label_animation->setPixmap(pix);
        int logoWidth = ui->label_animation->width();
        int logoHeight = ui->label_animation->height();
        ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
    }
    else if(ui->radioButton_tableHOME->isChecked()){
        ui->label_tableStatus->setText("<font color=green>Home</font>");
        CommPacket packet((uint8_t)0b10000000,(uint8_t)0x14,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket(fileTX,startupTime);
        QPixmap pix(":/img/modelStates/pressurizedMounted.png");
        ui->label_animation->setPixmap(pix);
        int logoWidth = ui->label_animation->width();
        int logoHeight = ui->label_animation->height();
        ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
    }
    else if(ui->radioButton_tableSPC->isChecked()){
        ui->label_tableStatus->setText("<font color=orange>Space-side</font>");
        CommPacket packet((uint8_t)0b10000000,(uint8_t)0x15,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket(fileTX,startupTime);
        QPixmap pix(":/img/modelStates/spaceExtendedMounted.png");
        ui->label_animation->setPixmap(pix);
        int logoWidth = ui->label_animation->width();
        int logoHeight = ui->label_animation->height();
        ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
    }
    else{
        QMessageBox::warning(this,"Command Error","No table action selected.");
    }
}

void HomeWindow::on_pushButton_clampCommand_clicked(){
    if(ui->radioButton_clampRelease->isChecked()){
        ui->label_clampStatus->setText("<font color=orange>Unsecured</font>");
        CommPacket packet((uint8_t)0b10000000,(uint8_t)0x12,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket(fileTX,startupTime);
    }
    else if(ui->radioButton_clampEngage->isChecked()){
        ui->label_clampStatus->setText("<font color=green>Secured</font>");
        CommPacket packet((uint8_t)0b10000000,(uint8_t)0x11,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket(fileTX,startupTime);
    }
    else{
        QMessageBox::warning(this,"Command Error","No clamp action selected.");
    }
}

void HomeWindow::on_pushButton_doorSPCCommand_clicked(){
    if(ui->radioButton_doorSPCClose->isChecked()){
        ui->label_doorSPCStatus->setText("<font color=green>Closed</font>");
        CommPacket packet((uint8_t)0b10000000,(uint8_t)0x19,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket(fileTX,startupTime);
    }
    else if(ui->radioButton_doorSPCOpen->isChecked()){
        ui->label_doorSPCStatus->setText("<font color=orange>Open</font>");
        CommPacket packet((uint8_t)0b10000000,(uint8_t)0x17,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket(fileTX,startupTime);
        QPixmap pix(":/img/modelStates/spaceOpenMounted.png");
        ui->label_animation->setPixmap(pix);
        int logoWidth = ui->label_animation->width();
        int logoHeight = ui->label_animation->height();
        ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
    }
    else{
        QMessageBox::warning(this,"Command Error","No space-side door action selected.");
    }
}

void HomeWindow::on_pushButton_doorHABCommand_clicked(){
    if(ui->radioButton_doorHABClose->isChecked()){
        ui->label_doorHABStatus->setText("<font color=green>Closed</font>");
        CommPacket packet((uint8_t)0b10000000,(uint8_t)0x18,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket(fileTX,startupTime);
    }
    else if(ui->radioButton_doorHABOpen->isChecked()){
        ui->label_doorHABStatus->setText("<font color=orange>Open</font>");
        CommPacket packet((uint8_t)0b10000000,(uint8_t)0x16,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket(fileTX,startupTime);
        QPixmap pix(":/img/modelStates/habOpenEmpty.png");
        ui->label_animation->setPixmap(pix);
        int logoWidth = ui->label_animation->width();
        int logoHeight = ui->label_animation->height();
        ui->label_animation->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
    }
    else{
        QMessageBox::warning(this,"Command Error","No hab-side door action selected.");
    }
}

void HomeWindow::on_pushButton_envCommand_clicked(){
    if(ui->radioButton_envDepressurize->isChecked()){
        ui->label_envStatus->setText("<font color=orange>Depressurized</font>");
        CommPacket packet((uint8_t)0b10000000,(uint8_t)0x27,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket(fileTX,startupTime);
        pressureState = -1;
        unsigned long temp = std::chrono::system_clock::now().time_since_epoch() /
                std::chrono::milliseconds(1);
        timeOfChange = (temp-startupTime);
    }
    else if(ui->radioButton_envPressurize->isChecked()){
        ui->label_envStatus->setText("<font color=green>Pressurized</font>");
        CommPacket packet((uint8_t)0b10000000,(uint8_t)0x28,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket(fileTX,startupTime);
        pressureState = 1;
        unsigned long temp = std::chrono::system_clock::now().time_since_epoch() /
                std::chrono::milliseconds(1);
        timeOfChange = (temp-startupTime);
    }
    else{
        QMessageBox::warning(this,"Command Error","No environmental action selected.");
    }
}

//%%%%%%%%%%%%%%%%%%%%%%% Mission Builder Tab %%%%%%%%%%%%%%%%%%%%%%%%

void HomeWindow::on_pushButton_add_clicked()
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

void HomeWindow::on_comboBox_subsystem_currentIndexChanged(int index)
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

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% FOR TESTING ONLY %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


void HomeWindow::on_pushButton_stop_clicked()
{
    if(testing==1){
        testing=0;
    }
    else{
        testing=1;
    }
}

void HomeWindow::on_pushButton_test_2_clicked()
{
    unsigned long currentTime = std::chrono::system_clock::now().time_since_epoch() /
            std::chrono::milliseconds(1);
    double diff = (currentTime - startupTime);
    qDebug() << "current: " << diff/1000;
    qDebug() << "TOC: " << timeOfChange/1000;
    double timeSinceChange = diff-timeOfChange;
    qDebug() << "TSC: "<<timeSinceChange/1000;
    double noise = std::rand()/RAND_MAX;
    if(pressureState==-1){
        pressure = 101.325*(1+noise)*qExp(-0.1*(timeSinceChange/1000));
    }
    else{
        pressure = 101.325*(1+noise)*(1-qExp(-0.1*(timeSinceChange/1000)));
    }
    qDebug()<<"x: "<<pressure;
    qDebug()<<"y: "<<diff;

    qv_x.append(diff/1000);
    qv_y.append(pressure);
    if (qv_y.last()>=100){
        ui->label_envStatus->setText("<font color=green>Pressurized</font>");
        const char* testingPres = "2";
        serialLED.write(testingPres);
    }
    else{
        ui->label_envStatus->setText("<font color=orange>Deressurized</font>");
        const char* testingDep = "1";
        serialLED.write(testingDep);
//        serialLED.write("1");
    }
    plot();
}

void HomeWindow::on_pushButton_FSU_clicked()
{
    serialLED.write("5");
}
