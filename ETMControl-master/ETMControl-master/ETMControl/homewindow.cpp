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

QSerialPort serial;
Buffer buffer;

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);

    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);

    QPixmap pix(":/img/modelStates/allSafe.jpg");
    ui->label_model->setPixmap(pix);
    int logoWidth = ui->label_model->width();
    int logoHeight = ui->label_model->height();
    ui->label_model->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));

    serial.setPortName("ttyACM0");
    serial.setBaudRate(QSerialPort::Baud57600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);

    const QByteArray currentData;
    QObject::connect(&serial, &QSerialPort::readyRead,&buffer,&Buffer::receivePacket);


    //create tx/rx command log
}

HomeWindow::~HomeWindow(){
    delete ui;
    serial.close();
    //end tx/rx command log
}

CommPacket::CommPacket (uint8_t typ,uint8_t com, uint8_t len, uint8_t dat){
    this->type = typ;
    this->command = com;
    this->length = len;
    this->data = dat;
}

void CommPacket::sendPacket(){
//    unsigned char * ptr = &msg.type;
    QByteArray temp;
    temp.resize(3);
    temp[0] = type | command;
    temp[1] = length;
    temp[2] = data;
    serial.write(temp, 3);
//    const QByteArray second(this->command);
//    const QByteArray third(this->length);
//    const QByteArray fourth(this->data);
//    serial.write(first);
//    serial.write(second);
//    serial.write(third);
//    serial.write(fourth);
    //error handling?
    //save to tx log
}

CommPacket receivePacket(){
    //const QByteArray data = serial->readAll();
    //append to the buffer.queue here

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

//void HomeWindow::spoofData(){
//    clearData();
//    addPoint(0.0,1.0);
//    plot();
//    ui->plot->yAxis->setRange(0,15);
//    int xLim = 5;
//    while(this->isActiveWindow()){
//        addPoint(qv_x.last()+0.1,1.0+((rand()-50)/1000));
//        plot();
//        ui->plot->xAxis->setRange(0,qv_x.last()+0.1);
//*        if(qv_x.last()==xLim){
//*            ui->plot->xAxis->setRange(0,qv_x.last());
//*            xLim = qv_x.last();
//*        }
//        delay(100);
//    }
//}

void HomeWindow::on_pushButton_builder_clicked(){
//    MissionBuilder builder;
//    builder.setModal(true);
//    builder.exec();
    builder = new MissionBuilder(this);
    builder->show();
}

void HomeWindow::on_pushButton_add_clicked(){
    addPoint(ui->bx_x->value(), ui->bx_y->value());
    plot();
}

void HomeWindow::on_pushButton_clear_clicked(){
    clearData();
    plot();
}

void HomeWindow::on_pushButton_tableCommand_clicked(){
    if(ui->radioButton_tableHab->isChecked()){
        ui->label_tableStatus->setText("<font color=orange>Hab-side</font>");
        QPixmap pix(":/img/modelStates/fullExtensionHab.jpg");
        ui->label_model->setPixmap(pix);
        int logoWidth = ui->label_model->width();
        int logoHeight = ui->label_model->height();
        ui->label_model->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
        CommPacket packet((uint8_t)0b10,(uint8_t)0x13,(uint8_t)0x00,(uint8_t)0x00);
        packet.sendPacket();
//        sendPacket(buildPacket(0b10,0x13,0x00,0x00));
    }
    else if(ui->radioButton_tableHome->isChecked()){
        ui->label_tableStatus->setText("<font color=green>Home</font>");
//        sendPacket(buildPacket(0b10,0x14,0x00,0x00));
    }
    else if(ui->radioButton_tableSpace->isChecked()){
        ui->label_tableStatus->setText("<font color=orange>Space-side</font>");
//        sendPacket(buildPacket(0b10,0x15,0x00,0x00));
    }
    else{
        QMessageBox::warning(this,"Command Error","No table action selected.");
    }
}

void HomeWindow::on_pushButton_clampCommand_clicked(){
    if(ui->radioButton_clampRelease->isChecked()){
        ui->label_clampStatus->setText("<font color=orange>Unsecured</font>");
//        sendPacket(buildPacket(0b10,0x12,0x00,0x00));
    }
    else if(ui->radioButton_clampSecure->isChecked()){
        ui->label_clampStatus->setText("<font color=green>Secured</font>");
//        sendPacket(buildPacket(0b10,0x13,0x00,0x00));
    }
    else{
        QMessageBox::warning(this,"Command Error","No clamp action selected.");
    }
}

void HomeWindow::on_pushButton_doorSpaceCommand_clicked(){
    if(ui->radioButton_doorSpaceClose->isChecked()){
        ui->label_doorSpaceStatus->setText("<font color=green>Closed</font>");
//        sendPacket(buildPacket(0b10,0x19,0x00,0x00));
    }
    else if(ui->radioButton_doorSpaceOpen->isChecked()){
        ui->label_doorSpaceStatus->setText("<font color=orange>Open</font>");
//        sendPacket(buildPacket(0b10,0x17,0x00,0x00));
    }
    else{
        QMessageBox::warning(this,"Command Error","No space-side door action selected.");
    }
}

void HomeWindow::on_pushButton_doorHabCommand_clicked(){
    if(ui->radioButton_doorHabClose->isChecked()){
        ui->label_doorHabStatus->setText("<font color=green>Closed</font>");
//        sendPacket(buildPacket(0b10,0x18,0x00,0x00));
    }
    else if(ui->radioButton_doorHabOpen->isChecked()){
        ui->label_doorHabStatus->setText("<font color=orange>Open</font>");

        QPixmap pix(":/img/modelStates/habDoorOpen.jpg");
        ui->label_model->setPixmap(pix);
        int logoWidth = ui->label_model->width();
        int logoHeight = ui->label_model->height();
        ui->label_model->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));

//        sendPacket(buildPacket(0b10,0x16,0x00,0x00));
    }
    else{
        QMessageBox::warning(this,"Command Error","No hab-side door action selected.");
    }
}

void HomeWindow::on_pushButton_lockSpaceCommand_clicked(){
    if(ui->radioButton_lockSpaceLock->isChecked()){
        ui->label_lockSpaceStatus->setText("<font color=green>Locked</font>");
    }
    else if(ui->radioButton_lockSpaceUnlock->isChecked()){
        ui->label_lockSpaceStatus->setText("<font color=orange>Unlocked</font>");
    }
    else{
        QMessageBox::warning(this,"Command Error","No space-side lock action selected.");
    }
}

void HomeWindow::on_pushButton_lockHabCommand_clicked(){
    if(ui->radioButton_lockHabLock->isChecked()){
        ui->label_lockHabStatus->setText("<font color=green>Locked</font>");
    }
    else if(ui->radioButton_lockHabUnlock->isChecked()){
        ui->label_lockHabStatus->setText("<font color=orange>Unlocked</font>");
    }
    else{
        QMessageBox::warning(this,"Command Error","No hab-side lock action selected.");
    }
}

void HomeWindow::on_pushButton_envCommand_clicked(){
    if(ui->radioButton_envDepressurize->isChecked()){
        ui->label_envStatus->setText("<font color=orange>Depressurized</font>");
//        sendPacket(buildPacket(0b10,0x28,0x00,0x00));
    }
    else if(ui->radioButton_envPressurize->isChecked()){
        ui->label_envStatus->setText("<font color=green>Pressurized</font>");
//        sendPacket(buildPacket(0b10,0x29,0x00,0x00));
    }
    else{
        QMessageBox::warning(this,"Command Error","No environmental action selected.");
    }
}

