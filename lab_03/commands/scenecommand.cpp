#include "scenecommand.h"


ClearScene::ClearScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) {}

void ClearScene::execute()
{
    _drawer->clearScene();
}

void ClearScene::undo()
{
    return;
}

bool ClearScene::canUndo()
{
    return false;
}

std::shared_ptr<BaseCommand> ClearScene::clone() const
{
    return std::make_shared<ClearScene>(*this);
}



DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) { }

void DrawScene::execute()
{
    _drawCompositeAdapter->setDrawer(_drawer);
    _drawManager->drawScene(_scene);
}

void DrawScene::undo()
{
    return;
}

bool DrawScene::canUndo()
{
    return false;
}

std::shared_ptr<BaseCommand> DrawScene::clone() const
{
    return std::make_shared<DrawScene>(*this);
}



LoadScene::LoadScene(const std::string fileName) : _fileName(fileName) { }

void LoadScene::execute()
{
    _scene = _loadManager->loadScene(_fileName);
    _sceneManager->setScene(_scene);
}

void LoadScene::undo()
{
    return;
}

bool LoadScene::canUndo()
{
    return false;
}

std::shared_ptr<BaseCommand> LoadScene::clone() const
{
    return std::make_shared<LoadScene>(*this);
}
