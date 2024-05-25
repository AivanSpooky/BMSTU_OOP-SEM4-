#include "modelloadmoderator.h"

ModelLoadModerator::ModelLoadModerator(std::shared_ptr<BaseModelBuildDirector> director)
    : _director(director)
{
}

std::shared_ptr<Object> ModelLoadModerator::load(std::string &fileName)
{
    auto builder = std::make_shared<ModelBuilder>(std::make_shared<FileCarcassModelReader>());
    return _director->create(builder, fileName);
}
