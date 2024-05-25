#ifndef FILECAMERABUILDDIRECTOR_H
#define FILECAMERABUILDDIRECTOR_H


#include "basecamerabuilddirector.h"
#include "filecarcassmodelreader.h"

class FileCameraBuildDirector : public BaseCameraBuildDirector
{
public:
    FileCameraBuildDirector();

    ~FileCameraBuildDirector() override = default;

    std::shared_ptr<Camera> create(std::shared_ptr<BaseCameraBuilder> builder,
                                 std::string &fileName) override;
};

#endif // FILECAMERABUILDDIRECTOR_H
