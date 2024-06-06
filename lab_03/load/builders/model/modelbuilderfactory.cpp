#include "modelbuilderfactory.h"

ModelBuilderFactory::ModelBuilderFactory(std::shared_ptr<BaseCarcassModelReader> &reader)
{
    builderCreators[DEFAULT] = [&reader]() -> std::shared_ptr<BaseModelBuilder> {
        return std::make_shared<ModelBuilder>(reader);
    };
    builderCreators[MATRIX] = [&reader]() -> std::shared_ptr<BaseModelBuilder> {
        return std::make_shared<MatrixModelBuilder>(reader);
    };
}

std::shared_ptr<BaseModelBuilder> ModelBuilderFactory::createBuilder(ModelStructureType impl)
{
    auto it = builderCreators.find(impl);
    if (it != builderCreators.end())
        return it->second();
    else {
        std::string msg = "Unsupported model structure implementation";
        throw SourceException(msg);
    }
}
