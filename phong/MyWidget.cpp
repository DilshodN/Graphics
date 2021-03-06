#include "MyWidget.hpp"

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
    auto *const new_window = main<QWindow*>(new QWindow);

    auto *const container = main<QGridLayout *>(new QGridLayout);
    auto *const container2 = main<QGridLayout *>(new QGridLayout);
    auto *const container3 = main<QGridLayout *>(new QGridLayout);
    auto *const mainLayout = main<QVBoxLayout *>(new QVBoxLayout);
    auto *const w = main<QWidget *>(new QWidget);
    auto *const w2 = main<QWidget*>(new QWidget);
    auto *const w3 = main<QWidget*>(new QWidget);

    auto *const tSlider = slider(2, 100, 1);
    auto *const sun_Slider_x = slider(-100, 100, 5);
    auto *const sun_Slider_y = slider(-100, 100, 5);
    auto *const sun_Slider_z = slider(-100, 100, 5);

    QPushButton *change_color_cube_button = new QPushButton(tr("&CubeColor"));
    change_color_cube_button->setFocusPolicy(Qt::NoFocus);

    QPushButton *change_color_light_button = new QPushButton(tr("&LightColor"));
    change_color_light_button->setFocusPolicy(Qt::NoFocus);

//    container->setColumnMinimumWidth(10, 100);

    container->addWidget(my_window);
    container->addWidget(tSlider);


    container->addWidget(sun_Slider_x);
    container->addWidget(sun_Slider_y);
    container->addWidget(sun_Slider_z);

    container->addWidget(change_color_cube_button);
    container->addWidget(change_color_light_button);

    w->setLayout(container);
    mainLayout->addWidget(w);

//    w2->setLayout(container2);
//    w2->setFixedSize(100, 500);
//    mainLayout->addWidget(w2);

//    w3->setLayout(container3);
//    w3->setFixedSize(200, 100);
//    mainLayout->addWidget(w3, Qt::AlignTop);

    setLayout(mainLayout);

    connect(tSlider, &QSlider::valueChanged, my_window, &SquareWindow::changeN);
    connect(sun_Slider_x, &QSlider::valueChanged, my_window, &SquareWindow::change_light_x_param);
    connect(sun_Slider_y, &QSlider::valueChanged, my_window, &SquareWindow::change_light_y_param);
    connect(sun_Slider_z, &QSlider::valueChanged, my_window, &SquareWindow::change_light_z_param);
    connect(change_color_cube_button, &QPushButton::clicked, my_window, &SquareWindow::change_cube_color);
    connect(change_color_light_button, &QPushButton::clicked, my_window, &SquareWindow::change_light_color);
}