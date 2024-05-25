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
    explicit BaseModelBuilder(std::shared_ptr<FileCarcassModelReader> &reader);
    virtual ~BaseModelBuilder() = default;

    virtual void build() override = 0;
    virtual void buildVertex(const Vertex &vertex) = 0;
    virtual void buildLink(const Link &link) = 0;
    virtual bool isBuild() const override = 0;

    virtual std::shared_ptr<CarcassModel> get() = 0;

    std::shared_ptr<FileCarcassModelReader> _reader;
protected:
    std::shared_ptr<ModelStructure> _model;

};

#endif // BASEMODELBUILDER_H
