#ifndef MODELBUILDERFACTORY_H
#define MODELBUILDERFACTORY_H

#include <memory>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <functional>
#include "exceptions.h"
#include "basemodelbuilder.h"
#include "basecarcassmodelreader.h"
#include "modelbuilder.h"
#include "matrixmodelbuilder.h"

class ModelBuilderFactory
{
public:
    ModelBuilderFactory(std::shared_ptr<BaseCarcassModelReader> &reader);

    std::shared_ptr<BaseModelBuilder> createBuilder(ModelStructureType impl);

private:
    using BuilderCreator = std::function<std::shared_ptr<BaseModelBuilder>()>;

    std::unordered_map<ModelStructureType, BuilderCreator> builderCreators;
};

#endif // MODELBUILDERFACTORY_H
