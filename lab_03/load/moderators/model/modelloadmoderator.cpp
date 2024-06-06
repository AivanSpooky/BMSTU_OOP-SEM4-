#include "modelloadmoderator.h"

ModelLoadModerator::ModelLoadModerator(std::shared_ptr<BaseModelBuildDirector> director)
    : _director(director), _impl(DEFAULT)
{
}

std::shared_ptr<Object> ModelLoadModerator::load(std::string &fileName)
{
    CarcassModelReaderFactory CMreaderFactory;
    auto reader = CMreaderFactory.createReader(fileName);

    ModelBuilderFactory MBFactory(reader);
    auto builder = MBFactory.createBuilder(_impl);

    return _director->create(builder, fileName);
}

void ModelLoadModerator::change_impl(ModelStructureType impl)
{
    _impl = impl;
}
