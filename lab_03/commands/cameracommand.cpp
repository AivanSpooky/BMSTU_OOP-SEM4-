#include <QDebug>

#include "cameracommand.h"

AddCamera::AddCamera(const ID &id, const Vertex &location) :
    _id(id), _location(location) {}

void AddCamera::execute()
{
    (*_id) = _scene->addCamera(_location);
}

void AddCamera::undo()
{
    return;
}

bool AddCamera::canUndo()
{
    return false;
}

std::shared_ptr<BaseCommand> AddCamera::clone() const
{
    return std::make_shared<AddCamera>(*this);
}


DeleteCamera::DeleteCamera(const std::size_t id) : _id(id) {}

void DeleteCamera::execute()
{
    Iterator objIt = _scene->getObjectIter(_id);
    _scene->deleteObject(objIt);
}

void DeleteCamera::undo()
{
    return;
}

bool DeleteCamera::canUndo()
{
    return false;
}


std::shared_ptr<BaseCommand> DeleteCamera::clone() const
{
    return std::make_shared<DeleteCamera>(*this);
}



MoveCamera::MoveCamera(const double dx, const double dy, const double dz, const size_t id) :
    _dx(dx), _dy(dy), _dz(dz), _id(id) {}

void MoveCamera::execute()
{
    auto camera = _scene->getObject(_id);
    _transformManager->moveObject(camera, _dx, _dy, _dz);
}

void MoveCamera::undo()
{
    _dx *= -1;
    _dy *= -1;
    _dz *= -1;
    execute();
}

bool MoveCamera::canUndo()
{
    return true;
}

std::shared_ptr<BaseCommand> MoveCamera::clone() const
{
    return std::make_shared<MoveCamera>(*this);
}


SetCamera::SetCamera(const std::size_t id) : _id(id) {}

void SetCamera::execute()
{
    _sceneManager->setCamera(_id);
}

void SetCamera::undo()
{
    return;
}

bool SetCamera::canUndo()
{
    return false;
}

std::shared_ptr<BaseCommand> SetCamera::clone() const
{
    return std::make_shared<SetCamera>(*this);
}
