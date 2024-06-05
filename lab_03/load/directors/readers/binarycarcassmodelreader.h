#ifndef BINARYCARCASSMODELREADER_H
#define BINARYCARCASSMODELREADER_H

#include <fstream>
#include <vector>
#include "basecarcassmodelreader.h"
#include "exceptions.h"

class BinaryCarcassModelReader : public BaseCarcassModelReader
{
public:
    BinaryCarcassModelReader();
    BinaryCarcassModelReader(std::shared_ptr<std::ifstream> &file);

    virtual void open(std::string &fileName) override;
    virtual void close() override;

    virtual std::size_t readCount() override;
    virtual Vertex readVertex() override;
    virtual std::vector<Vertex> readVertexes() override;
    virtual std::vector<Link> readLinks(int &vertexNum) override;

    static std::string _tag;

private:
    std::shared_ptr<std::ifstream> _file;
};

#endif // BINARYCARCASSMODELREADER_H
