#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include <missionbuilder.h>

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
    void spoofData();

private slots:
    void on_pushButton_builder_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_tableCommand_clicked();

    void on_pushButton_clampCommand_clicked();

    void on_pushButton_doorSpaceCommand_clicked();

    void on_pushButton_doorHabCommand_clicked();

    void on_pushButton_lockSpaceCommand_clicked();

    void on_pushButton_lockHabCommand_clicked();

    void on_pushButton_envCommand_clicked();

//    void on_pushButton_spoof_clicked();

private:
    Ui::HomeWindow *ui;
    MissionBuilder *builder;

    QVector<double> qv_x, qv_y;
};

#endif // HOMEWINDOW_H
