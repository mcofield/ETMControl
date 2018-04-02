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

private slots:
    void on_pushButton_builder_clicked();

private:
    Ui::HomeWindow *ui;
    MissionBuilder *builder;
};

#endif // HOMEWINDOW_H
