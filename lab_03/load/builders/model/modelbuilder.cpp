#include "modelbuilder.h"

ModelBuilder::ModelBuilder(std::shared_ptr<BaseCarcassModelReader> reader)
{
    _reader = reader;
    _vertexNum = 0;
}

void ModelBuilder::build()
{
    _model = std::make_shared<ModelStructure>();
}


void ModelBuilder::buildVertex(const Vertex &vertex)
{
    if (!isBuild()) { }

    _model->addVertex(vertex);
}


void ModelBuilder::buildLink(const Link &link)
{
    if (!isBuild()) { }

    _model->addLink(link);
}

void ModelBuilder::buildVertexes()
{
    std::vector<Vertex> vertexes = _reader->readVertexes();
    _vertexNum = vertexes.size();
    for (int i = 0; i < _vertexNum; i++)
        buildVertex(vertexes[i]);
}

void ModelBuilder::buildLinks()
{
    std::vector<Link> links = _reader->readLinks(_vertexNum);
    int linksNum = links.size();
    for (int i = 0; i < linksNum; i++)
        buildLink(links[i]);
}



bool ModelBuilder::isBuild() const
{
    return nullptr != _model;
}

std::shared_ptr<CarcassModel> ModelBuilder::get()
{
    return std::make_shared<CarcassModel>(CarcassModel(_model));
}

void ModelBuilder::openFile(std::string& fileName)
{
    _reader->open(fileName);
}

void ModelBuilder::closeFile()
{
    _reader->close();
}
