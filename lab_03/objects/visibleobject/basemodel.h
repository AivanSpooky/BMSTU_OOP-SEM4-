#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "visibleobject.h"
#include "transformer.h"
#include "vertex.h"

class BaseModel: public VisibleObject
{
public:
    virtual ~BaseModel() = default;

    virtual Vertex getCenter() const = 0;
    virtual void transform(Transformer &mtr, const Vertex &center) = 0;
};

#endif // BASEMODEL_H
