#ifndef MATRIXMODELSTRUCTURE_H
#define MATRIXMODELSTRUCTURE_H

#include <vector>
#include "vertex.h"
#include "basemodelstructure.h"
#include "matrix.h"

class MatrixModelStructure : public BaseModelStructure
{
public:
    MatrixModelStructure() = default;
    MatrixModelStructure(const std::vector<Vertex> &vertexes, const Matrix<int> &adjMatrix);

    ~MatrixModelStructure() override = default;

    const std::vector<Vertex> &getVertexes() const override;
    const std::vector<Link> &getLinks() const override;
    const Vertex getCenter() const override;

    void addVertex(const Vertex &vertex) override;
    void addLink(const Link &link) override;
    void updateCenter() override;

    void moveVertexesToOrigin(const Vertex &center) override;
    void moveVertexesToCenter(const Vertex &center) override;
    void transformVertexes(Transformer &mtr) override;
    void transform(Transformer &mtr, const Vertex &center) override;

private:
    Vertex _center;
    std::vector<Vertex> _vertexes;
    Matrix<int> _adjMatrix;

    void updateAdjMatrix();
};

#endif // MATRIXMODELSTRUCTURE_H
