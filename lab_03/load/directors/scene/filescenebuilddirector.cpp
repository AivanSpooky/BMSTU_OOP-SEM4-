#include "filescenebuilddirector.h"
#include "filecamerabuilddirector.h"
#include "filemodelbuilddirector.h"
#include "exceptions.h"

FileSceneBuildDirector::FileSceneBuildDirector() {}

std::shared_ptr<Scene> FileSceneBuildDirector::create(std::shared_ptr<SceneBuilder> builder,
                                                    std::string &fileName)
{
    builder->_reader->open(fileName);

    builder->build();

    createModels(builder, fileName);
    createCameras(builder, fileName);

    builder->_reader->close();

    return builder->get();
}

void FileSceneBuildDirector::createModels(std::shared_ptr<SceneBuilder> builder,
                                        std::string &fileName)
{
    size_t modelsCount = builder->_reader->readCount();

    auto modBuilder = std::make_shared<ModelBuilder>();

    for (size_t i = 0; i < modelsCount; i++)
    {
        auto model = FileModelBuildDirector().create(modBuilder, fileName);
        builder->buildObject(model);
    }
}

void FileSceneBuildDirector::createCameras(std::shared_ptr<SceneBuilder> builder,
                                         std::string &fileName)
{
    size_t camsCount = builder->_reader->readCount();

    auto camBuilder = std::make_shared<CameraBuilder>();

    for (size_t i = 0; i < camsCount; i++)
    {
        auto camera = FileCameraBuildDirector().create(camBuilder, fileName);
        builder->buildObject(camera);
    }
}
