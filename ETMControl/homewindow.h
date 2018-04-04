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

private slots:
    void on_pushButton_builder_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::HomeWindow *ui;
    MissionBuilder *builder;

    QVector<double> qv_x, qv_y;
};

#endif // HOMEWINDOW_H
