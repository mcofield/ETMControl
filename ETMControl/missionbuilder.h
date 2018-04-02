#ifndef MISSIONBUILDER_H
#define MISSIONBUILDER_H

#include <QDialog>

namespace Ui {
class MissionBuilder;
}

class MissionBuilder : public QDialog
{
    Q_OBJECT

public:
    explicit MissionBuilder(QWidget *parent = 0);
    ~MissionBuilder();
    
private slots:
    void on_pushButton_add_clicked();

    void on_comboBox_subsystem_currentIndexChanged(int index);

private:
    Ui::MissionBuilder *ui;
};

#endif // MISSIONBUILDER_H
