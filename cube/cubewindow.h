#ifndef CUBEWINDOW_H
#define CUBEWINDOW_H

#include <OpenGL.h>
#include <QOpenGLShaderProgram>
#include <QColorDialog>
#include <QScreen>
#include <memory>
#include "openglwindow.h"

class CubeWindow: public OpenGLWindow{
public:
    using OpenGLWindow::OpenGLWindow;

    void initialize() override;
    void render() override;
private:
    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;
//    QColorDialog c_dialog;

    std::shared_ptr<QOpenGLShaderProgram> m_program;
    int m_frame = 0;
};

#endif // CUBEWINDOW_H
