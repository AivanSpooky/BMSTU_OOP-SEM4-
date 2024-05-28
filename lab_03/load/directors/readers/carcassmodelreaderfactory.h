#ifndef CARCASSMODELREADERFACTORY_H
#define CARCASSMODELREADERFACTORY_H

#include <memory>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <functional>
#include "exceptions.h"
#include "basecarcassmodelreader.h"
#include "filecarcassmodelreader.h"

class CarcassModelReaderFactory
{
public:
    CarcassModelReaderFactory();

    std::shared_ptr<BaseCarcassModelReader> createReader(const std::string& fileName);

private:
    std::string getFileExtension(const std::string& fileName);

    using ReaderCreator = std::function<std::shared_ptr<BaseCarcassModelReader>()>;

    std::unordered_map<std::string, ReaderCreator> readerCreators;
};


#endif // CARCASSMODELREADERFACTORY_H
