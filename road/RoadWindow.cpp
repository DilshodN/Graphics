#include "RoadWindow.h"
#include <QScreen>
#include <cmath>

RoadWindow::RoadWindow(Params &p)
        : p(p) {
    time_now = std::chrono::high_resolution_clock::now();
}

void RoadWindow::initialize() {
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, "../vertexShader3.glsl");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, "../fragmentShader3.glsl");
    m_program->link();


    glClearColor(0.52, 0.8, 0.92, 1);

    m_posAttr = m_program->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);

    m_perspMatrix = m_program->uniformLocation("perspMatrix");
    Q_ASSERT(m_perspMatrix != -1);
    m_transCamMatrix = m_program->uniformLocation("transCamMatrix");
    Q_ASSERT(m_transCamMatrix != -1);

    m_dirDir = m_program->uniformLocation("directedDir");
    Q_ASSERT(m_dirDir != -1);
    m_dirCol = m_program->uniformLocation("directedCol");
    Q_ASSERT(m_dirCol != -1);


    p.texture_sand_ = new QOpenGLTexture{QImage("../Materials/sand.jpg")};
    p.texture_road1_ = new QOpenGLTexture{QImage("../Materials/road_1.jpg")};
    p.texture_road1_->setMinMagFilters(QOpenGLTexture::Nearest, QOpenGLTexture::Nearest);
    p.texture_road2_ = new QOpenGLTexture{QImage("../Materials/road_2.jpg")};
    p.texture_road2_->setMinMagFilters(QOpenGLTexture::Nearest, QOpenGLTexture::Nearest);
    p.texture_road3_ = new QOpenGLTexture{QImage("../Materials/road_3.jpg")};
    p.texture_road3_->setMinMagFilters(QOpenGLTexture::Nearest, QOpenGLTexture::Nearest);
}


void RoadWindow::render() {


    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    m_program->bind();

    m_program->setUniformValue(m_dirDir, p.dir_light_dir);
    m_program->setUniformValue(m_dirCol, p.dir_light_col);

    QMatrix4x4 p_matrix;
    p_matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    m_program->setUniformValue(m_perspMatrix, p_matrix);

    QMatrix4x4 trans_cam_matrix;
    trans_cam_matrix.translate(-p.camera_pos + QVector3D{0, 0, m_frame * 0.002f});
    m_program->setUniformValue(m_transCamMatrix, trans_cam_matrix);

    m_program->setUniformValue("textureRoad1", 0);
    glActiveTexture(GL_TEXTURE0 + 0);
    p.texture_road1_->bind();
    m_program->setUniformValue("textureRoad2", 1);
    glActiveTexture(GL_TEXTURE0 + 1);
    p.texture_road2_->bind();
    m_program->setUniformValue("textureRoad3", 2);
    glActiveTexture(GL_TEXTURE0 + 2);
    p.texture_road3_->bind();

    draw_sphere(p.plane);

    p.texture_road1_->release();
    p.texture_road2_->release();
    p.texture_road3_->release();

    m_program->release();

    ++m_frame;
    if (!m_device) {
        m_device = new QOpenGLPaintDevice;
    }
    m_device->setSize(size() * devicePixelRatio());
    m_device->setDevicePixelRatio(devicePixelRatio());


}

void RoadWindow::draw_sphere(const Edge &edge) {
    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, edge.get_vertices().data());
    glEnableVertexAttribArray(m_posAttr);

    for (const auto &line_indices: edge.get_indices()) {
        glDrawElements(GL_TRIANGLE_STRIP, line_indices.size(), GL_UNSIGNED_INT, line_indices.data());
    }

    glDisableVertexAttribArray(m_posAttr);
}

void RoadWindow::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key::Key_Up: {
            p.camera_pos.setY(p.camera_pos.y() + 0.05);
            break;
        }
        case Qt::Key::Key_Right: {
            p.camera_pos.setX(p.camera_pos.x() + 0.05);
            break;
        }

        case Qt::Key::Key_Down: {
            p.camera_pos.setY(p.camera_pos.y() - 0.05);
            break;
        }

        case Qt::Key::Key_Left:{
            p.camera_pos.setX(p.camera_pos.x() - 0.05);
        }
        default:
            break;
    }
}

