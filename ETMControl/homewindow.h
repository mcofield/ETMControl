#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include "communication.h"
#include <QMainWindow>
#include <QTime>
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <fstream>

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = 0);
    ~HomeWindow();

    void addPoint(double x, double y);
    void clearData();
    void plot();
    bool experimentStatus();
    void airlockStatus();

    std::ofstream fileTX;
    std::ofstream fileRX;

    char* date;
    char TX[80];
    char RX[80];
    QVector<double> qv_x,qv_y;
    unsigned long startupTime = std::chrono::system_clock::now().time_since_epoch() /
            std::chrono::milliseconds(1);
    double timeOfChange = startupTime-startupTime;
    int pressureState = -1;
    double pressure = 101.325;
    int testing = 1;

    int tableCapStatus = 0;
    int clampCapStatus = 0;
    int clampForceStatus = 0;
    int doorSPC = 0;
    int doorHAB = 0;
    int tablePos = 0;

    QStringList subsystems;
    QStringList vSlot;
    QStringList clamp;
    QStringList lock;
    QStringList door;
    QStringList env;


private slots:

    void on_pushButton_tableCommand_clicked();

    void on_pushButton_clampCommand_clicked();

    void on_pushButton_doorSPCCommand_clicked();

    void on_pushButton_doorHABCommand_clicked();

    void on_pushButton_envCommand_clicked();

    void on_pushButton_stop_clicked();

    //%%%%%%%%%%% Mission Builder %%%%%%%%%%%%%

    void on_pushButton_add_clicked();

    void on_comboBox_subsystem_currentIndexChanged(int index);

    void on_pushButton_test_2_clicked();

    void on_pushButton_FSU_clicked();

private:
    Ui::HomeWindow *ui;
    void parsePacket(CommPacket *packet);


};

#endif // HOMEWINDOW_H
