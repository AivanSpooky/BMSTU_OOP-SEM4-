#include "modelloadmoderator.h"

ModelLoadModerator::ModelLoadModerator(std::shared_ptr<BaseModelBuildDirector> director)
    : _director(director)
{
}

std::shared_ptr<Object> ModelLoadModerator::load(std::string &fileName)
{
    CarcassModelReaderFactory CMreaderFactory;
    auto reader = CMreaderFactory.createReader(fileName);
    auto builder = std::make_shared<ModelBuilder>(reader);
    return _director->create(builder, fileName);
}
