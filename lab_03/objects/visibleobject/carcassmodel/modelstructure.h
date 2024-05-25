#ifndef MODELSTRUCTURE_H
#define MODELSTRUCTURE_H

#include <vector>

#include "vertex.h"
#include "basemodelstructure.h"
#include "link.h"

class ModelStructure : public BaseModelStructure
{
public:
    ModelStructure() = default;
    ModelStructure(std::vector<Vertex> &vertexes, std::vector<Link> &links);
    ModelStructure(std::vector<Vertex> &vertexes, std::vector<Link> &links, Vertex &center);

    ~ModelStructure() override = default;

    const std::vector<Vertex> &getVertexes() const override;
    const std::vector<Link> &getLinks() const override;
    const Vertex getCenter() const override;

    void addVertex(const Vertex &vertex) override;
    void addLink(const Link &link) override;
    void updateCenter() override;

    void moveVertexesToOrigin(const Vertex &center) override;
    void moveVertexesToCenter(const Vertex &center) override;
    void transformVertexes(const Matrix<double> &mtr) override;
    void transform(const Matrix<double> &mtr, const Vertex &center) override;

private:
    Vertex _center;

    std::vector<Vertex> _vertexes;
    std::vector<Link> _links;
};


#endif //MODELSTRUCTURE_H
