#ifndef CARCASSMODELREADERFACTORY_H
#define CARCASSMODELREADERFACTORY_H

#include <memory>
#include <string>
#include <stdexcept>
#include "exceptions.h"
#include "basecarcassmodelreader.h"
#include "filecarcassmodelreader.h"

class CarcassModelReaderFactory
{
public:
    std::shared_ptr<BaseCarcassModelReader> createReader(const std::string& fileName) {
        std::string extension = getFileExtension(fileName);
        if (extension == "txt") {
            return std::make_shared<FileCarcassModelReader>();
        }
        else {
            std::string msg = "Unsupported file extension";
            throw SourceException(msg);
        }
    }

private:
    std::string getFileExtension(const std::string& fileName)
    {
        size_t pos = fileName.find_last_of('.');
        if (pos != std::string::npos)
            return fileName.substr(pos + 1);
        return "";
    }
};

#endif // CARCASSMODELREADERFACTORY_H
