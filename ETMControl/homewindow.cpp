#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);

    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}

void HomeWindow::clearData()
{
    qv_x.clear();
    qv_y.clear();
}

void HomeWindow::plot()
{
    ui->plot->graph(0)->setData(qv_x,qv_y);
    ui->plot->replot();
    ui->plot->update();
}

void HomeWindow::on_pushButton_builder_clicked(){
//    MissionBuilder builder;
//    builder.setModal(true);
//    builder.exec();
    builder = new MissionBuilder(this);
    builder->show();
}

void HomeWindow::on_pushButton_add_clicked()
{
    addPoint(ui->bx_x->value(), ui->bx_y->value());
    plot();
}

void HomeWindow::on_pushButton_clear_clicked()
{
    clearData();
    plot();
}
