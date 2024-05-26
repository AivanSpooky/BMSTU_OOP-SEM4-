#ifndef MODELLOADMODERATOR_H
#define MODELLOADMODERATOR_H

#include "baseloadmoderator.h"
#include "basemodelbuilddirector.h"
#include "filecarcassmodelreader.h"
#include "basemodelbuilder.h"
#include "carcassmodelreaderfactory.h"

class ModelLoadModerator : public BaseLoadModerator
{
public:
    ModelLoadModerator() = default;
    explicit ModelLoadModerator(std::shared_ptr<BaseModelBuildDirector> director);

    ~ModelLoadModerator() = default;

    std::shared_ptr<Object> load(std::string &fileName) override;

private:
    std::shared_ptr<BaseModelBuildDirector> _director;
};

#endif // MODELLOADMODERATOR_H
