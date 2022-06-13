#include "cubesettingswindow.h"
#include "ui_cubesettingswindow.h"

#include <QColorDialog>

CubeSettingsWindow::CubeSettingsWindow(Params &p, QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::CubeSettingsWindow),
        p(p) {
    ui->setupUi(this);
    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window, "white");

    p.dir_light_col = {1, 1, 1};
    p.dir_light_dir = {0, -0.5, 0};
    ui->dir_color_label->setAutoFillBackground(true);
    ui->dir_color_label->setPalette(sample_palette);
}

CubeSettingsWindow::~CubeSettingsWindow() {
    delete ui;
}


void CubeSettingsWindow::on_spin_div_n_valueChanged(int arg1) {
    //p.plane.set_latitude_bins(arg1);
}

void CubeSettingsWindow::on_spin_div_m_valueChanged(int arg1) {
    //p.plane.set_longitude_bins(arg1);
}

void CubeSettingsWindow::on_camera_x_valueChanged(double arg1) {
    p.camera_pos.setX(arg1);
}

void CubeSettingsWindow::on_camera_y_valueChanged(double arg1) {
    p.camera_pos.setY(arg1);
}

void CubeSettingsWindow::on_camera_z_valueChanged(double arg1) {
    p.camera_pos.setZ(arg1);
}

void CubeSettingsWindow::on_enable_directed_stateChanged(int arg1) {
    static QColor color = ui->dir_color_label->palette().color(QPalette::Window);
    if (arg1) {
        p.dir_light_col = QVector3D{static_cast<float>(color.redF()), static_cast<float >(color.greenF()),
                                    static_cast<float>(color.blueF())};
    } else {
        p.dir_light_col = QVector3D(0, 0, 0);
    }
}

void CubeSettingsWindow::on_dir_color_button_clicked() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    p.dir_light_col = QVector3D{static_cast<float>(color.redF()), static_cast<float >(color.greenF()),
                                static_cast<float>(color.blueF())};

    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window, color);
    ui->dir_color_label->setAutoFillBackground(true);
    ui->dir_color_label->setPalette(sample_palette);
}

void CubeSettingsWindow::on_dir_light_x_valueChanged(double arg1) {
    p.dir_light_dir.setX(arg1);
}

void CubeSettingsWindow::on_dir_light_y_valueChanged(double arg1) {
    p.dir_light_dir.setY(arg1);
}

void CubeSettingsWindow::on_dir_light_z_valueChanged(double arg1) {
    p.dir_light_dir.setZ(arg1);
}

void CubeSettingsWindow::on_comboBox_currentIndexChanged(int index) {
    if (index == 1) {
        p.texture_road1_->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
        p.texture_road2_->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
        p.texture_road3_->setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
    } else if (index == 0) {
        p.texture_road1_->setMinMagFilters(QOpenGLTexture::Nearest, QOpenGLTexture::Nearest);
        p.texture_road2_->setMinMagFilters(QOpenGLTexture::Nearest, QOpenGLTexture::Nearest);
        p.texture_road3_->setMinMagFilters(QOpenGLTexture::Nearest, QOpenGLTexture::Nearest);
    } else {
        p.texture_road1_->setMinMagFilters(QOpenGLTexture::LinearMipMapLinear, QOpenGLTexture::LinearMipMapLinear);
        p.texture_road2_->setMinMagFilters(QOpenGLTexture::LinearMipMapLinear, QOpenGLTexture::LinearMipMapLinear);
        p.texture_road3_->setMinMagFilters(QOpenGLTexture::LinearMipMapLinear, QOpenGLTexture::LinearMipMapLinear);
    }
}

