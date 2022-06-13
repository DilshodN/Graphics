#ifndef PARAMS_H
#define PARAMS_H

#include "Edge.hpp"
#include <QOpenGLTexture>

struct Params final {
    Edge plane;

    QVector3D camera_pos;

    QVector3D dir_light_dir;
    QVector3D dir_light_col;

    QOpenGLTexture *texture_sand_ = nullptr;
    QOpenGLTexture *texture_road1_ = nullptr;
    QOpenGLTexture *texture_road2_ = nullptr;
    QOpenGLTexture *texture_road3_ = nullptr;
};

#endif // PARAMS_H
