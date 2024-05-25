#include <QDebug>

#include "modelcommand.h"


MoveModel::MoveModel(const double dx, const double dy, const double dz, const std::size_t id) :
    _dx(dx), _dy(dy), _dz(dz), _id(id) { }

void MoveModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->moveObject(model, _dx, _dy, _dz);
}

void MoveModel::undo()
{
    _dx *= -1;
    _dy *= -1;
    _dz *= -1;
    execute();
}

bool MoveModel::canUndo()
{
    return true;
}

std::shared_ptr<BaseCommand> MoveModel::clone() const
{
    return std::make_shared<MoveModel>(*this);
}



ScaleModel::ScaleModel(const double kx, const double ky, const double kz, const std::size_t id) :
    _kx(kx), _ky(ky), _kz(kz), _id(id) { }

void ScaleModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->scaleObject(model, _kx, _ky, _kz);
}
void ScaleModel::undo()
{
    _kx = 1 / _kx;
    _ky = 1 / _ky;
    _kz = 1 / _kz;
    execute();
}

bool ScaleModel::canUndo()
{
    return true;
}

std::shared_ptr<BaseCommand> ScaleModel::clone() const
{
    return std::make_shared<ScaleModel>(*this);
}


RotateModel::RotateModel(const double ox, const double oy, const double oz, const std::size_t id) :
        _ox(ox), _oy(oy), _oz(oz), _id(id) { }

void RotateModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->rotateObject(model, _ox, _oy, _oz);
}
void RotateModel::undo()
{
    auto model = _scene->getObject(_id);
    if (model)
    {
        _transformManager->rotateObject(model, 0, 0, -_oz);
        _transformManager->rotateObject(model, 0, -_oy, 0);
        _transformManager->rotateObject(model, -_ox, 0, 0);
    }
}

bool RotateModel::canUndo()
{
    return true;
}

std::shared_ptr<BaseCommand> RotateModel::clone() const
{
    return std::make_shared<RotateModel>(*this);
}



TransformModel::TransformModel(const Matrix<double> &mtr, const std::size_t id) :
        _mtr(mtr), _id(id) { }

void TransformModel::execute()
{
    auto model = _scene->getObject(_id);
    _transformManager->transformObject(model, _mtr);
}

void TransformModel::undo()
{
    _mtr.inverse();
    execute();
}

bool TransformModel::canUndo()
{
    return true;
}

std::shared_ptr<BaseCommand> TransformModel::clone() const
{
    return std::make_shared<TransformModel>(*this);
}



DeleteModel::DeleteModel(const std::size_t id) : _id(id) { }

void DeleteModel::execute()
{
    Iterator objIt = _scene->getObjectIter(_id);
    _scene->deleteObject(objIt);
}

std::shared_ptr<BaseCommand> DeleteModel::clone() const
{
    return std::make_shared<DeleteModel>(*this);
}

void DeleteModel::undo()
{
    return;
}

bool DeleteModel::canUndo()
{
    return false;
}




LoadModel::LoadModel(const ID &id, std::string &fileName) :
    _fileName(fileName), _id(id) { }

void LoadModel::execute()
{
    auto model = _loadManager->load(_fileName);
    (*_id) = _scene->addObject(model);
}

void LoadModel::undo()
{
    return;
}

bool LoadModel::canUndo()
{
    return false;
}

std::shared_ptr<BaseCommand> LoadModel::clone() const
{
    return std::make_shared<LoadModel>(*this);
}

