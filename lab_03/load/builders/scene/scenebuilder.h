#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "basescenebuilder.h"

class SceneBuilder : public BaseSceneBuilder
{
public:
    SceneBuilder() = default;
    explicit SceneBuilder(std::shared_ptr<FileCarcassModelReader> reader);
    ~SceneBuilder() = default;

    void build() override;
    void buildObject(const std::shared_ptr<Object> &object) override;
    bool isBuild() const override;

    std::shared_ptr<Scene> get() override;
};


#endif //SCENEBUILDER_H
