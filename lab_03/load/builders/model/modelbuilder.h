#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "basemodelbuilder.h"

class ModelBuilder : public BaseModelBuilder
{
public:
    ModelBuilder() = default;
    explicit ModelBuilder(std::shared_ptr<BaseCarcassModelReader> reader);
    ~ModelBuilder() = default;

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

#endif //BUILDER_MODEL_H
