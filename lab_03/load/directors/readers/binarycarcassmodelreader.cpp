#include "binarycarcassmodelreader.h"
#include "exceptions.h"
#include <QDebug>

std::string BinaryCarcassModelReader::_tag = "bin";

BinaryCarcassModelReader::BinaryCarcassModelReader()
{
    _file = std::make_shared<std::ifstream>();
}

BinaryCarcassModelReader::BinaryCarcassModelReader(std::shared_ptr<std::ifstream> &file)
{
    _file = file;
}

void BinaryCarcassModelReader::open(std::string &fileName)
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->open(fileName, std::ios::binary);

    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }
}

void BinaryCarcassModelReader::close()
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
}

std::size_t BinaryCarcassModelReader::readCount()
{
    int count;
    _file->read(reinterpret_cast<char*>(&count), sizeof(count));
    return count;
}

Vertex BinaryCarcassModelReader::readVertex()
{
    double x, y, z;
    _file->read(reinterpret_cast<char*>(&x), sizeof(x));
    _file->read(reinterpret_cast<char*>(&y), sizeof(y));
    _file->read(reinterpret_cast<char*>(&z), sizeof(z));
    return Vertex(x, y, z);
}

std::vector<Vertex> BinaryCarcassModelReader::readVertexes()
{
    std::vector<Vertex> vertexes;
    int vertexNum;
    _file->read(reinterpret_cast<char*>(&vertexNum), sizeof(vertexNum));

    if (vertexNum <= 0)
    {
        std::string msg = "wrong vertex num";
        throw SourceException(msg);
    }

    double x, y, z;
    for (int i = 0; i < vertexNum; ++i)
    {
        _file->read(reinterpret_cast<char*>(&x), sizeof(x));
        _file->read(reinterpret_cast<char*>(&y), sizeof(y));
        _file->read(reinterpret_cast<char*>(&z), sizeof(z));
        vertexes.push_back(Vertex(x, y, z));
    }
    return vertexes;
}

std::vector<Link> BinaryCarcassModelReader::readLinks(int &vertexNum)
{
    std::vector<Link> links;
    int linksNum;
    _file->read(reinterpret_cast<char*>(&linksNum), sizeof(linksNum));

    if (linksNum <= 0)
    {
        qDebug() << linksNum;
        std::string msg = "wrong links num";
        throw SourceException(msg);
    }

    int vertex1Index, vertex2Index;
    for (int i = 0; i < linksNum; ++i)
    {
        _file->read(reinterpret_cast<char*>(&vertex1Index), sizeof(vertex1Index));
        _file->read(reinterpret_cast<char*>(&vertex2Index), sizeof(vertex2Index));

        if (vertex1Index <= 0 or vertex2Index <= 0 or
            vertex1Index > vertexNum or vertex2Index > vertexNum)
        {
            qDebug() << "AAAA";
            std::string msg = "wrong link data";
            throw SourceException(msg);
        }

        links.push_back(Link(vertex1Index, vertex2Index));
    }
    return links;
}
