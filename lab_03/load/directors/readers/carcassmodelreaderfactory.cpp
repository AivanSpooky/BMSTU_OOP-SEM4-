#include "carcassmodelreaderfactory.h"

CarcassModelReaderFactory::CarcassModelReaderFactory()
{
    readerCreators["txt"] = []() -> std::shared_ptr<BaseCarcassModelReader> {
        return std::make_shared<FileCarcassModelReader>();
    };
}

std::shared_ptr<BaseCarcassModelReader> CarcassModelReaderFactory::createReader(const std::string& fileName)
{
    std::string extension = getFileExtension(fileName);
    auto it = readerCreators.find(extension);
    if (it != readerCreators.end())
        return it->second();
    else {
        std::string msg = "Unsupported file extension";
        throw SourceException(msg);
    }
}

std::string CarcassModelReaderFactory::getFileExtension(const std::string& fileName)
{
    size_t pos = fileName.find_last_of('.');
    if (pos != std::string::npos)
        return fileName.substr(pos + 1);
    return "";
}
