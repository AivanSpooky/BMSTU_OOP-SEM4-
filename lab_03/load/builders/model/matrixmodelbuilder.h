#ifndef MATRIXMODELBUILDER_H
#define MATRIXMODELBUILDER_H

#include "basemodelbuilder.h"

class MatrixModelBuilder : public BaseModelBuilder
{
public:
    MatrixModelBuilder() = default;
    explicit MatrixModelBuilder(std::shared_ptr<BaseCarcassModelReader> reader);
    ~MatrixModelBuilder() = default;

    void build() override;
    void buildVertex(const Vertex &vertex) override;
    void buildLink(const Link &link) override;
    void buildVertexes() override;
    void buildLinks() override;
    bool isBuild() const override;

    void openFile(std::string& fileName) override;
    void closeFile() override;

    std::shared_ptr<CarcassModel> get() override;
private:
    int _vertexNum;
};

#endif // MATRIXMODELBUILDER_H
