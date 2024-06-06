#ifndef BASELOADMODERATOR_H
#define BASELOADMODERATOR_H

#include <memory>
#include "basemodelstructure.h"
#include "object.h"

class BaseLoadModerator
{
public:
    BaseLoadModerator() = default;
    ~BaseLoadModerator() = default;

    virtual std::shared_ptr<Object> load(std::string &fileName) = 0;
    virtual void change_impl(ModelStructureType impl) = 0;
};

#endif // BASELOADMODERATOR_H
