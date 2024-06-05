#include "filemodelbuilddirector.h"
#include "exceptions.h"
#include "modelbuilder.h"

FileModelBuildDirector::FileModelBuildDirector() {}

std::shared_ptr<CarcassModel> FileModelBuildDirector::create(std::shared_ptr<BaseModelBuilder> builder, std::string &fileName)
{
    builder->openFile(fileName);

    builder->build();
    builder->buildVertexes();
    builder->buildLinks();

    builder->closeFile();

    return builder->get();
}
