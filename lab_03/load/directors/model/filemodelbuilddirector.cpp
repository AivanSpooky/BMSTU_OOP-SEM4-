#include "filemodelbuilddirector.h"
#include "exceptions.h"
#include "modelbuilder.h"

FileModelBuildDirector::FileModelBuildDirector() {}

std::shared_ptr<CarcassModel> FileModelBuildDirector::create(std::shared_ptr<BaseModelBuilder> builder, std::string &fileName)
{
    builder->_reader->open(fileName);

    builder->build();

    std::vector<Vertex> vertexes = builder->_reader->readVertexes();
    int vertexNum = vertexes.size();

    std::vector<Link> links = builder->_reader->readLinks(vertexNum);
    int linksNum = links.size();

    for (int i = 0; i < vertexNum; i++)
        builder->buildVertex(vertexes[i]);

    for (int i = 0; i < linksNum; i++)
        builder->buildLink(links[i]);

    builder->_reader->close();

    return builder->get();
}
