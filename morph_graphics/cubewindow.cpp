#include "cubewindow.h"
#include <QScreen>
#include <QtMath>
#include <vector>


void CubeWindow::makeCube(const float side_size, const int n_points) {
    Q_ASSERT(n_points > 1);
    auto side_half = side_size / 2.0f;
    auto step = side_size / static_cast<float>(n_points - 1);

    std::vector<QVector3D> vertices;
    vertices.reserve(6 * pow(n_points, 2));

    for (auto z = -side_half; z <= side_half; z += side_size) {
        for (auto j = 0; j < n_points; j++) {
            for (auto i = 0; i < n_points; i++) {
                vertices.emplace_back(
                        QVector3D(-side_half + i * step, -side_half + j * step, z));
            }
        }
    }

    for (auto x = -side_half; x <= side_half; x += side_size) {
        for (auto k = 0; k < n_points; k++) {
            for (auto j = 0; j < n_points; j++) {
                vertices.emplace_back(
                        QVector3D(x, -side_half + j * step, side_half - k * step));
            }
        }
    }

    for (auto y = -side_half; y <= side_half; y += side_size) {
        for (auto i = 0; i < n_points; i++) {
            for (auto k = 0; k < n_points; k++) {
                vertices.emplace_back(
                        QVector3D(-side_half + i * step, y, side_half - k * step));
            }
        }
    }

    std::vector<GLuint> indices;
    indices.reserve(36 * pow(n_points - 1, 2));
    for (int i = 0; i < 6 * pow(n_points, 2); i += n_points * n_points) {
        for (int j = 0; j < (n_points - 1) * (n_points - 1); j += n_points) {
            for (int k = 0; k < (n_points - 1); k++) {
                indices.emplace_back(i + j + k + n_points);
                indices.emplace_back(i + j + k + 0);
                indices.emplace_back(i + j + k + n_points);
                indices.emplace_back(i + j + k + n_points + 1);
                indices.emplace_back(i + j + k + 0);
                indices.emplace_back(i + j + k + 1);
            }
        }
    }

    vertexBuffer.create();
    vertexBuffer.bind();
    vertexBuffer.allocate(vertices.data(),
                          static_cast<int>(vertices.size() * sizeof(QVector3D)));

    indexBuffer.create();
    indexBuffer.bind();
    indexBuffer.allocate(indices.data(),
                         static_cast<int>(indices.size() * sizeof(GLuint)));
}


void CubeWindow::init() {
    program_ = std::make_unique<QOpenGLShaderProgram>(this);

    program_->addShaderFromSourceFile(QOpenGLShader::Vertex, "../shaders/vertex.vsh");
    program_->addShaderFromSourceFile(QOpenGLShader::Fragment,"../shaders/fragment.fsh");

    program_->link();
    posAttr_ = program_->attributeLocation("posAttr");
    Q_ASSERT(posAttr_ != -1);
    matrixUniform_ = program_->uniformLocation("matrix");
    Q_ASSERT(matrixUniform_ != -1);
    colorUniform_ = program_->uniformLocation("color");
    Q_ASSERT(colorUniform_ != -1);
    morphUniform_ = program_->uniformLocation("morph");
    Q_ASSERT(morphUniform_ != -1);


}

void CubeWindow::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    const auto retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    program_->bind();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    makeCube(1.0f, num_of_points);

    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -3);
    matrix.rotate(40.0 * frame_ / screen()->refreshRate(), rotationAxis);

    program_->setUniformValue(matrixUniform_, matrix);
    program_->setUniformValue(colorUniform_, color);
    program_->setUniformValue(morphUniform_, morph_parameter);

    program_->enableAttributeArray(posAttr_);

    program_->setAttributeBuffer(posAttr_, GL_FLOAT, 0, 3, sizeof(QVector3D));

    glDrawElements(GL_LINES, indexBuffer.size(), GL_UNSIGNED_INT, nullptr);

    program_->disableAttributeArray(posAttr_);

    program_->release();

    ++frame_;
}

void CubeWindow::mousePressEvent(QMouseEvent *e) {
    mousePressPosition = QVector2D(e->localPos());
}

void CubeWindow::mouseReleaseEvent(QMouseEvent *e) {
    const auto diff = QVector2D(e->localPos()) - mousePressPosition;

    rotationAxis = QVector3D(diff.y(), diff.x(), 0.0).normalized();
}

void CubeWindow::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Space) {
        const auto chosen_color = QColorDialog::getColor();
        color =
                QVector4D(chosen_color.red() / 255.0f, chosen_color.green() / 255.0f,
                          chosen_color.blue() / 255.0f, 0.2f);
    } else if (e->key() == Qt::Key_Plus) {
        num_of_points++;
    } else if (e->key() == Qt::Key_Minus) {
        if (num_of_points > 2) {
            num_of_points--;
        }
    } else {
        GLWindow::keyPressEvent(e);
    }
}