#ifndef CAMERABUILDER_H
#define CAMERABUILDER_H

#include "basecamerabuilder.h"

class CameraBuilder : public BaseCameraBuilder
{
public:
    CameraBuilder() = default;
    explicit CameraBuilder(std::shared_ptr<FileCarcassModelReader> reader);
    ~CameraBuilder() = default;

    void build() override;
    void buildLocation(const Vertex &location) override;
    bool isBuild() const override;

    std::shared_ptr<Camera> get() override;
};

#endif //CAMERABUILDER_H
