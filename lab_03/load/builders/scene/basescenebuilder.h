#ifndef BASESCENEBUILDER_H
#define BASESCENEBUILDER_H


#include "scene.h"
#include "filecarcassmodelreader.h"
#include "basebuilder.h"

class BaseSceneBuilder : public BaseBuilder
{
public:
    BaseSceneBuilder() = default;
    explicit BaseSceneBuilder(std::shared_ptr<FileCarcassModelReader> &reader);
    virtual ~BaseSceneBuilder() = default;

    virtual void build() override = 0;
    virtual void buildObject(const std::shared_ptr<Object> &object) = 0;
    virtual bool isBuild() const override = 0;

    virtual std::shared_ptr<Scene> get() = 0;

    std::shared_ptr<FileCarcassModelReader> _reader;

protected:
    std::shared_ptr<Scene> _scene;

};

#endif // BASESCENEBUILDER_H
