#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <homewindow.h>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::Login *ui;
    HomeWindow *home;
};

#endif // LOGIN_H
