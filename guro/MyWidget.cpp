#include "MyWidget.hpp"
#include <iostream>
#include <QLabel>
#include <QPainter>

template <typename T, typename = std::enable_if_t<std::is_pointer<T>::value>>
using main = T;

auto slider(int min_value, int max_value, int tick_value) {
    auto *const slider = main<QSlider*>(new QSlider(Qt::Orientation::Horizontal));
    slider->setRange(min_value, max_value);
    slider->setSingleStep(tick_value);
    slider->setTickPosition(QSlider::TicksRight);
    slider->setValue(max_value);
    return slider;
}



MyWidget::MyWidget() {
    auto *const my_window = main<SquareWindow*>(new SquareWindow);

    m_window = my_window;

    auto *const container = main<QGridLayout *>(new QGridLayout);
    auto *const mainLayout = main<QVBoxLayout *>(new QVBoxLayout);
    auto *const w = main<QWidget *>(new QWidget);

//    QPainter painter{my_window};
//    painter.setPen(Qt::yellow);
//    painter.setFont(QFont("Arial", 16));
//    painter.drawText(rect(), Qt::AlignLeft, "FPS: " + QString::number(my_window->FPS()));

    mainLayout->addWidget(my_window);

    w->setLayout(mainLayout);
    w->setFixedSize(512, 512);

    w->show();
}

void MyWidget::createToolBar(){
    auto *const container = main<QGridLayout *>(new QGridLayout);
    auto *const mainLayout = main<QVBoxLayout *>(new QVBoxLayout);
    auto *const w = main<QWidget *>(new QWidget);

    auto *const tSlider = slider(2, 100, 1);
    auto *const sun_Slider_x = slider(-100, 100, 5);
    auto *const sun_Slider_y = slider(-100, 100, 5);
    auto *const sun_Slider_z = slider(-100, 100, 5);
    auto *const num_of_cube = slider(2, 200, 1);

    QPushButton *change_color_cube_button = new QPushButton(tr("&CubeColor"));
    change_color_cube_button->setFocusPolicy(Qt::NoFocus);

    QPushButton *change_color_light_button = new QPushButton(tr("&LightColor"));
    change_color_light_button->setFocusPolicy(Qt::NoFocus);

    QPushButton *shader_change = new QPushButton(tr("&Shader"));
    shader_change->setFocusPolicy(Qt::NoFocus);

    container->addWidget(tSlider);
    container->addWidget(sun_Slider_x);
    container->addWidget(sun_Slider_y);
    container->addWidget(sun_Slider_z);
    container->addWidget(change_color_cube_button);
    container->addWidget(change_color_light_button);
    container->addWidget(shader_change);
    container->addWidget(num_of_cube);

    w->setLayout(container);
    w->setFixedSize(512, 256);
    w->show();

    connect(tSlider, &QSlider::valueChanged, m_window, &SquareWindow::changeN);
    connect(sun_Slider_x, &QSlider::valueChanged, m_window, &SquareWindow::change_light_x_param);
    connect(sun_Slider_y, &QSlider::valueChanged, m_window, &SquareWindow::change_light_y_param);
    connect(sun_Slider_z, &QSlider::valueChanged, m_window, &SquareWindow::change_light_z_param);
    connect(change_color_cube_button, &QPushButton::clicked, m_window, &SquareWindow::change_cube_color);
    connect(change_color_light_button, &QPushButton::clicked, m_window, &SquareWindow::change_light_color);
    connect(shader_change, &QPushButton::clicked, m_window, &SquareWindow::change_shader);
    connect(num_of_cube, &QSlider::valueChanged, m_window, &SquareWindow::change_num_of_cubes);
}

void MyWidget::createAxes() {
    auto *const container = main<QGridLayout *>(new QGridLayout);
    auto *const w = main<QWidget *>(new QWidget);

    auto *const xAxSlider = slider(1, 100, 1);
    auto *const yAxSlider = slider(1, 100, 1);
    auto *const zAxSlider = slider(1, 100, 1);

    container->addWidget(xAxSlider);
    container->addWidget(yAxSlider);
    container->addWidget(zAxSlider);

    w->setLayout(container);
    w->setFixedSize(512, 128);
    w->show();

    connect(xAxSlider, &QSlider::valueChanged, m_window, &SquareWindow::changexAx);
    connect(yAxSlider, &QSlider::valueChanged, m_window, &SquareWindow::changeyAx);
    connect(zAxSlider, &QSlider::valueChanged, m_window, &SquareWindow::changezAx);
}
