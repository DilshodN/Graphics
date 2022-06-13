#include <QOpenGLBuffer>
#include "Edge.hpp"

Edge::Edge(QVector3D base_point, float n_x, float n_z)
        : indeces_({{0, 3, 1, 2}}) {
    vertices_ = {base_point + QVector3D{0, 0, -n_z}, base_point + QVector3D{n_x, 0, -n_z},
                 base_point + QVector3D{n_x, 0, 0}, base_point};
    normals_ = std::vector(4, QVector3D{0, 1, 0});
}

void Edge::set_size(float n_x, float n_z) {
    auto base_point = vertices_[3];
    vertices_ = {base_point + QVector3D{0, 0, -n_z}, base_point + QVector3D{0, n_x, -n_z},
                 base_point + QVector3D{0, n_x, 0}, base_point};

}

const std::vector<QVector3D> &Edge::get_vertices() const {
    return vertices_;
}

const std::vector<std::vector<int>> &Edge::get_indices() const {
    return indeces_;
}

const std::vector<QVector3D> &Edge::get_normals() const {
    return normals_;
}
