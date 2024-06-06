#ifndef BASEMODELBUILDER_H
#define BASEMODELBUILDER_H


#include "modelstructure.h"
#include "carcassmodel.h"
#include "filecarcassmodelreader.h"
#include "basebuilder.h"

class BaseModelBuilder : public BaseBuilder
{
public:
    BaseModelBuilder() = default;
    explicit BaseModelBuilder(std::shared_ptr<BaseCarcassModelReader> &reader);
    virtual ~BaseModelBuilder() = default;

    virtual void build() override = 0;
    virtual void buildVertex(const Vertex &vertex) = 0;
    virtual void buildLink(const Link &link) = 0;
    virtual void buildVertexes() = 0;
    virtual void buildLinks() = 0;
    virtual bool isBuild() const override = 0;
    virtual void openFile(std::string& fileName) = 0;
    virtual void closeFile() = 0;

    virtual std::shared_ptr<CarcassModel> get() = 0;

    std::shared_ptr<BaseCarcassModelReader> _reader;
protected:
    std::shared_ptr<BaseModelStructure> _model;

};

#endif // BASEMODELBUILDER_H
