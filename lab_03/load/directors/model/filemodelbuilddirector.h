#ifndef FILEMODELBUILDDIRECTOR_H
#define FILEMODELBUILDDIRECTOR_H

#include "basemodelbuilddirector.h"
#include "modelbuilder.h"
#include "filecarcassmodelreader.h"
#include <memory>
#include <string>
#include <vector>

class FileModelBuildDirector : public BaseModelBuildDirector
{
public:
    FileModelBuildDirector();
    ~FileModelBuildDirector() override = default;

    std::shared_ptr<CarcassModel> create(std::shared_ptr<BaseModelBuilder> builder, std::string &fileName) override;
};

#endif // FILEMODELBUILDDIRECTOR_H
