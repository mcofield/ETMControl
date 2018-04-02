#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::on_pushButton_builder_clicked(){
//    MissionBuilder builder;
//    builder.setModal(true);
//    builder.exec();
    builder = new MissionBuilder(this);
    builder->show();
}
