#pragma once
#include "SquareWindow.hpp"
#include <QColorDialog>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>
#include <type_traits>
#include <QPushButton>

class MyWidget : public QWidget {
Q_OBJECT

public:
    SquareWindow* m_window;
    MyWidget();
    void createToolBar();
    void createAxes();
};