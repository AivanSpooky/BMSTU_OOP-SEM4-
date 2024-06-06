#ifndef CARCASSMODEL_H
#define CARCASSMODEL_H

#include <memory>
#include <utility>

#include "object.h"
#include "basemodel.h"
#include "vertex.h"
#include "link.h"
#include "modelstructure.h"
#include "matrixmodelstructure.h"
#include "drawcarcassmodeladapter.h"

class CarcassModel : public VisibleObject
{
    friend class DrawCarcassModelAdapter;

public:
    CarcassModel() : _modelStructure(nullptr) { } /*!!*/
    explicit CarcassModel(const std::shared_ptr<BaseModelStructure> &modelStructure) :
        _modelStructure(modelStructure) { }
    CarcassModel(const CarcassModel &model);

    ~CarcassModel() override = default;

    virtual Vertex getCenter() const override;
    virtual void transform(Transformer &mtr, const Vertex &center) override;

protected:
    std::shared_ptr<BaseModelStructure> _modelStructure;
};


#endif // CARCASSMODEL_H
