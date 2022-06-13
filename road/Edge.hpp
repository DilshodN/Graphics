#ifndef EDGE_H
#define EDGE_H

#include <vector>
#include <QVector3D>

class Edge final {
    std::vector<QVector3D> vertices_;
    std::vector<std::vector<int>> indeces_;
    std::vector<QVector3D> normals_;

public:
    Edge() = default;
    Edge(QVector3D base_point, float n_x, float n_z);

    void set_size(float n_x, float n_z);

    const std::vector<QVector3D> &get_vertices() const;

    const std::vector<QVector3D> &get_normals() const;

    const std::vector<std::vector<int>> &get_indices() const;
};

#endif // EDGE_H
