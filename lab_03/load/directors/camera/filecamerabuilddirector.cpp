#include "filecamerabuilddirector.h"
#include "exceptions.h"

FileCameraBuildDirector::FileCameraBuildDirector() {}

std::shared_ptr<Camera> FileCameraBuildDirector::create(std::shared_ptr<BaseCameraBuilder> builder,
                                                      std::string &fileName)
{
    builder->_reader->open(fileName);

    builder->build();
    Vertex location = builder->_reader->readVertex();
    builder->buildLocation(location);

    builder->_reader->close();

    return builder->get();
}
