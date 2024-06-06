#include "matrixmodelbuilder.h"

MatrixModelBuilder::MatrixModelBuilder(std::shared_ptr<BaseCarcassModelReader> reader)
{
    _reader = reader;
    _vertexNum = 0;
}

void MatrixModelBuilder::build()
{
    _model = std::make_shared<MatrixModelStructure>(); /*!!*/
    qDebug() << "MATRIX IMPLEMENTATION";
}


void MatrixModelBuilder::buildVertex(const Vertex &vertex)
{
    if (!isBuild()) { }

    _model->addVertex(vertex);
}


void MatrixModelBuilder::buildLink(const Link &link)
{
    if (!isBuild()) { }

    _model->addLink(link);
}

void MatrixModelBuilder::buildVertexes()
{
    std::vector<Vertex> vertexes = _reader->readVertexes();
    _vertexNum = vertexes.size();
    for (int i = 0; i < _vertexNum; i++)
        buildVertex(vertexes[i]);
}

void MatrixModelBuilder::buildLinks()
{
    std::vector<Link> links = _reader->readLinks(_vertexNum);
    int linksNum = links.size();
    for (int i = 0; i < linksNum; i++)
    {
        buildLink(links[i]);
    }
}



bool MatrixModelBuilder::isBuild() const
{
    return nullptr != _model;
}

std::shared_ptr<CarcassModel> MatrixModelBuilder::get()
{
    return std::make_shared<CarcassModel>(CarcassModel(_model));
}

void MatrixModelBuilder::openFile(std::string& fileName)
{
    _reader->open(fileName);
}

void MatrixModelBuilder::closeFile()
{
    _reader->close();
}
