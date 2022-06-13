#ifndef CUBEWINDOW_H
#define CUBEWINDOW_H

#include "openglwindow.h"
#include <QOpenGLShaderProgram>
#include "Edge.hpp"
#include "Params.h"
#include <chrono>
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QPainter>
#include <memory>
#include "InputController.hpp"

class RoadWindow final : public OpenGLWindow {
public:
    using OpenGLWindow::OpenGLWindow;

    RoadWindow(Params &p);

    void initialize() override;

    void render() override;

   void keyPressEvent(QKeyEvent *event) override;

private:
    void draw_sphere(const Edge &edge);

    GLint m_posAttr = 0;

    GLint m_perspMatrix = 0;
    GLint m_transCamMatrix = 0;
    GLint m_rotMatrix = 0;

    GLint m_dirDir = 0;
    GLint m_dirCol = 0;

    QOpenGLShaderProgram *m_program = nullptr;
    int m_frame = 0;
    Params &p;
    std::chrono::high_resolution_clock::time_point time_now;
    int FPS = 0;
    QOpenGLPaintDevice *m_device = 0;


};

#endif // CUBEWINDOW_H
