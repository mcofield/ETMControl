#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QPixmap>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap pix(":/img/lockheedmartin.png");
    ui->label_logo->setPixmap(pix);
    int logoWidth = ui->label_logo->width();
    int logoHeight = ui->label_logo->height();
    ui->label_logo->setPixmap(pix.scaled(logoWidth,logoHeight,Qt::KeepAspectRatio));
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if(username == "test" && password == "test"){
        hide();
        home = new HomeWindow(this);
        home->show();
    }
    else{
        QMessageBox::warning(this,"Login","Wrong username or password.");
    }
}
