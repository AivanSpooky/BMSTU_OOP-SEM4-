#include "modelscommand.h"


MoveModels::MoveModels(const double dx, const double dy, const double dz) :
    _dx(dx), _dy(dy), _dz(dz) { }

void MoveModels::execute()
{
    _transformManager->moveObject(_scene->getVisibleObjects(), _dx, _dy, _dz);
}

void MoveModels::undo()
{
    _dx *= -1;
    _dy *= -1;
    _dz *= -1;
    execute();
}

bool MoveModels::canUndo()
{
    return true;
}

std::shared_ptr<BaseCommand> MoveModels::clone() const
{
    return std::make_shared<MoveModels>(*this);
}



ScaleModels::ScaleModels(const double kx, const double ky, const double kz) :
    _kx(kx), _ky(ky), _kz(kz) { }

void ScaleModels::execute()
{
    _transformManager->scaleObject(_scene->getVisibleObjects(), _kx, _ky, _kz);
}

void ScaleModels::undo()
{
    _kx = 1 / _kx;
    _ky = 1 / _ky;
    _kz = 1 / _kz;
    execute();
}

bool ScaleModels::canUndo()
{
    return true;
}

std::shared_ptr<BaseCommand> ScaleModels::clone() const
{
    return std::make_shared<ScaleModels>(*this);
}


RotateModels::RotateModels(const double ox, const double oy, const double oz) :
        _ox(ox), _oy(oy), _oz(oz) { }

void RotateModels::execute()
{
    _transformManager->rotateObject(_scene->getVisibleObjects(), _ox, _oy, _oz);
}

void RotateModels::undo()
{
    _transformManager->rotateObject(_scene->getVisibleObjects(), 0, 0, -_oz);
    _transformManager->rotateObject(_scene->getVisibleObjects(), 0, -_oy, 0);
    _transformManager->rotateObject(_scene->getVisibleObjects(), -_ox, 0, 0);
}

bool RotateModels::canUndo()
{
    return true;
}

std::shared_ptr<BaseCommand> RotateModels::clone() const
{
    return std::make_shared<RotateModels>(*this);
}


TransformModels::TransformModels(Transformer &mtr) :
        _mtr(mtr) { }

void TransformModels::execute()
{
    _transformManager->transformObject(_scene->getVisibleObjects(), _mtr);
}

void TransformModels::undo()
{
    _mtr.inverse();
    execute();
}

bool TransformModels::canUndo()
{
    return true;
}

std::shared_ptr<BaseCommand> TransformModels::clone() const
{
    return std::make_shared<TransformModels>(*this);
}
