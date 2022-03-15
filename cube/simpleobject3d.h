#ifndef SIMPLEOBJECT3D_H
#define SIMPLEOBJECT3D_H

#include <QOpenGLFunctions>
#include <QColor>
#include <QOpenGLShaderProgram>
#include <memory>

class SimpleObject3D : public QOpenGLFunctions{
protected:
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> colors;

    virtual void SetVetrices() = 0;
    virtual void Draw() = 0;
public:
    SimpleObject3D() = default;

    void initialize();
    void render(std::shared_ptr<QOpenGLShaderProgram>& program);

    virtual void SetColor(const QColor& color);
};

#endif // SIMPLEOBJECT3D_H
