#include "cubewindow.h"
#include <iostream>
void CubeWindow::initialize(){
    m_program = std::make_shared<QOpenGLShaderProgram>(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, "/Users/dilshod/QtProjects/cube/shaders/vertex_shader.vsh");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, "/Users/dilshod/QtProjects/cube/shaders/fragment_shader.fsh");
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);
    m_colAttr = m_program->attributeLocation("colAttr");
    Q_ASSERT(m_colAttr != -1);
    m_matrixUniform = m_program->uniformLocation("matrix");
    Q_ASSERT(m_matrixUniform != -1);
}

void CubeWindow::render(){
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale); // setting of window size

    glClear(GL_COLOR_BUFFER_BIT); // clear

    m_program->bind(); // Binds this shader program to the active QOpenGLContext and makes it the current shader program.

    QMatrix4x4 matrix;
    matrix.perspective(1000.0f, 4.0f / 3.0f, 1.f, 10.0f);
    matrix.translate(0, 0, -7);
    matrix.rotate(100.0f * m_frame / screen()->refreshRate(), 1, 1, 1);

    m_program->setUniformValue(m_matrixUniform, matrix);

    static const GLfloat vertices[] = {
        -1.f, 1.f, 1.f,
        1.f, 1.f, 1.f,
        -1.f, -1.f, 1.f,
        1.f, -1.f, 1.f,
        1.f, -1.f, -1.f,
        1.f, 1.f, 1.f,


        1.f, 1.f, -1.f,
        -1.f, 1.f, 1.f,
        -1.f, 1.f, -1.f,
        -1.f, -1.f, 1.f,
        -1.f, -1.f, -1.f,
        1.f, -1.f, -1.f,
        -1.f, 1.f, -1.f,
        1.f, 1.f, -1.f
    };

    static const GLfloat colors[] = {
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,

        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,

        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,

     };
//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    m_program->setUniformValue(m_matrixUniform, matrix);

    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 14);

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);

    m_program->release();
    ++m_frame;
}
