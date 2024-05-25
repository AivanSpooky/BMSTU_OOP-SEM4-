#ifndef BASECAMERABUILDER_H
#define BASECAMERABUILDER_H

#include "camera.h"
#include "filecarcassmodelreader.h"
#include "basebuilder.h"

class BaseCameraBuilder : public BaseBuilder
{
public:
    BaseCameraBuilder() = default;
    explicit BaseCameraBuilder(std::shared_ptr<FileCarcassModelReader> &reader);
    virtual ~BaseCameraBuilder() = default;

    virtual void build() override = 0;
    virtual void buildLocation(const Vertex &location) = 0;
    virtual bool isBuild() const override = 0;

    virtual std::shared_ptr<Camera> get() = 0;

    std::shared_ptr<FileCarcassModelReader> _reader;
protected:
    std::shared_ptr<Camera> _camera;
};

#endif // BASECAMERABUILDER_H
