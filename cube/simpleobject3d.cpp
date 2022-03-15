#include "simpleobject3d.h"

void SimpleObject3D::initialize(){
    SetVetrices();
}

void SimpleObject3D::render(std::shared_ptr<QOpenGLShaderProgram> &program){
    GLint m_posAttr = program->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);
    GLint m_colAttr = program->attributeLocation("colAttr");
    Q_ASSERT(m_colAttr != -1);

    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices.data());
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors.data());

    Draw();

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);
}
