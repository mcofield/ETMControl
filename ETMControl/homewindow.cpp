#include "homewindow.h"
#include "ui_homewindow.h"
#include <QMessageBox>
#include <QLabel>
#include <QWidget>
#include <QTime>

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);

    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);
}

HomeWindow::~HomeWindow(){
    delete ui;
}

void HomeWindow::delay( int millisecondsToWait ){
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
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

void HomeWindow::spoofData(){
    clearData();
    addPoint(0.0,1.0);
    plot();
    ui->plot->yAxis->setRange(0,15);
    int xLim = 5;
    while(this->isActiveWindow()){
        addPoint(qv_x.last()+0.1,1.0+((rand()-50)/1000));
        plot();
        ui->plot->xAxis->setRange(0,qv_x.last()+0.1);
//        if(qv_x.last()==xLim){
//            ui->plot->xAxis->setRange(0,qv_x.last());
//            xLim = qv_x.last();
//        }
        delay(100);
    }
}

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
    }
    else if(ui->radioButton_tableHome->isChecked()){
        ui->label_tableStatus->setText("<font color=green>Home</font>");
    }
    else if(ui->radioButton_tableSpace->isChecked()){
        ui->label_tableStatus->setText("<font color=orange>Space-side</font>");
    }
    else{
        QMessageBox::warning(this,"Command Error","No table action selected.");
    }
}

void HomeWindow::on_pushButton_clampCommand_clicked(){
    if(ui->radioButton_clampRelease->isChecked()){
        ui->label_clampStatus->setText("<font color=orange>Unsecured</font>");
    }
    else if(ui->radioButton_clampSecure->isChecked()){
        ui->label_clampStatus->setText("<font color=green>Secured</font>");
    }
    else{
        QMessageBox::warning(this,"Command Error","No clamp action selected.");
    }
}

void HomeWindow::on_pushButton_doorSpaceCommand_clicked(){
    if(ui->radioButton_doorSpaceClose->isChecked()){
        ui->label_doorSpaceStatus->setText("<font color=green>Closed</font>");
    }
    else if(ui->radioButton_doorSpaceOpen->isChecked()){
        ui->label_doorSpaceStatus->setText("<font color=orange>Open</font>");
    }
    else{
        QMessageBox::warning(this,"Command Error","No space-side door action selected.");
    }
}

void HomeWindow::on_pushButton_doorHabCommand_clicked(){
    if(ui->radioButton_doorHabClose->isChecked()){
        ui->label_doorHabStatus->setText("<font color=green>Closed</font>");
    }
    else if(ui->radioButton_doorHabOpen->isChecked()){
        ui->label_doorHabStatus->setText("<font color=orange>Open</font>");
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
    }
    else if(ui->radioButton_envPressurize->isChecked()){
        ui->label_envStatus->setText("<font color=green>Pressurized</font>");
    }
    else{
        QMessageBox::warning(this,"Command Error","No environmental action selected.");
    }
}

void HomeWindow::on_pushButton_spoof_clicked()
{
    spoofData();
}
