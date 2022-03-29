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


    auto *const container = main<QGridLayout *>(new QGridLayout);

    auto *const mainLayout = main<QVBoxLayout *>(new QVBoxLayout);
    auto *const w = main<QWidget *>(new QWidget);

    auto *const tSlider = slider(0, 1000, 50);
    auto *const sun_Slider_x = slider(-100, 100, 5);
    auto *const sun_Slider_y = slider(-100, 100, 5);
    auto *const sun_Slider_z = slider(-100, 100, 5);

//    container->setColumnMinimumWidth(10, 100);

    container->addWidget(my_window);
    container->addWidget(tSlider);

    container->addWidget(sun_Slider_x);
    container->addWidget(sun_Slider_y);
    container->addWidget(sun_Slider_z);

    w->setLayout(container);
    mainLayout->addWidget(w);
    setLayout(mainLayout);
    connect(tSlider, &QSlider::valueChanged, my_window, &SquareWindow::change_morph_param);
    connect(sun_Slider_x, &QSlider::valueChanged, my_window, &SquareWindow::change_light_x_param);
    connect(sun_Slider_y, &QSlider::valueChanged, my_window, &SquareWindow::change_light_y_param);
    connect(sun_Slider_z, &QSlider::valueChanged, my_window, &SquareWindow::change_light_z_param);
}