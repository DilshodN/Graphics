#ifndef CUBE_H
#define CUBE_H

#include "simpleobject3d.h"

class Cube final: public SimpleObject3D{
    void SetVetrices() override;
    void Draw() override;
public:
    explicit Cube(GLfloat edgelen);
    void SetColor(const QColor& color) override;
};

#endif // CUBE_H
