#ifndef FILESCENEBUILDDIRECTOR_H
#define FILESCENEBUILDDIRECTOR_H


#include "basescenebuilddirector.h"
#include "filecarcassmodelreader.h"

class FileSceneBuildDirector : public BaseSceneBuildDirector
{
public:
    FileSceneBuildDirector();

    ~FileSceneBuildDirector() = default;

    std::shared_ptr<Scene> create(std::shared_ptr<SceneBuilder> builder,
                                std::string &fileName) override;

protected:
    virtual void createModels(std::shared_ptr<SceneBuilder> builder,
                    std::string &fileName) override;
    virtual void createCameras(std::shared_ptr<SceneBuilder> builder,
                     std::string &fileName) override;
};

#endif // FILESCENEBUILDDIRECTOR_H
