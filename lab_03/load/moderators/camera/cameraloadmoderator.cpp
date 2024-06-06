#include "cameraloadmoderator.h"
#include "exceptions.h"
#include "camerabuilder.h"


CameraLoadModerator::CameraLoadModerator(std::shared_ptr<BaseCameraBuildDirector> director)
    : _builder(std::make_shared<CameraBuilder>(std::make_shared<FileCarcassModelReader>())),
    _director(std::move(director))
{
}/*:
    _builder(new CameraBuilder(std::make_shared<FileCarcassModelReader>()))
{
    _director = director;
}*/

std::shared_ptr<Object> CameraLoadModerator::load(std::string &fileName)
{
    std::shared_ptr<Camera> camera_sh_ptr;

    try
    {
        camera_sh_ptr = _director->create(_builder, fileName);
    }
    catch (SourceException &error)
    {
        std::string msg = "Error : Open file";
        throw SourceException(msg);
    }
    catch (std::exception &error)
    {
        std::string msg = "Error : Read model";
        throw SourceException(msg);
    }

    return std::shared_ptr<Object>(camera_sh_ptr);
}

void CameraLoadModerator::change_impl(ModelStructureType impl) {}
