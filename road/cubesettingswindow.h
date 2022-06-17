#ifndef CUBESETTINGSWINDOW_H
#define CUBESETTINGSWINDOW_H

#include <QMainWindow>
#include "Params.h"



namespace Ui {
class CubeSettingsWindow;
}

class CubeSettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CubeSettingsWindow(Params& p, QWidget *parent = nullptr);
    ~CubeSettingsWindow();

private slots:

    void on_camera_x_valueChanged(double arg1);
    void on_camera_y_valueChanged(double arg1);
    void on_camera_z_valueChanged(double arg1);

    void on_enable_directed_stateChanged(int arg1);
    void on_dir_color_button_clicked();
    void on_dir_light_x_valueChanged(double arg1);
    void on_dir_light_y_valueChanged(double arg1);
    void on_dir_light_z_valueChanged(double arg1);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::CubeSettingsWindow *ui;
    Params& p;

};

#endif // CUBESETTINGSWINDOW_H
