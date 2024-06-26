#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "objects/object.h"

class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() = default;

    bool isVisible() override { return false; }
};

#endif //INVISIBLEOBJECT_H
