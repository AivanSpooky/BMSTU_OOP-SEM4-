#ifndef MODELCOMMAND_H
#define MODELCOMMAND_H

#include <cstddef>
#include <memory>
#include "transformer.h"

#include "basecommand.h"

using ID = std::shared_ptr<std::size_t>;

class ModelCommand : public BaseCommand { };

class MoveModel : public ModelCommand
{
public:
    MoveModel(const double dx, const double dy, const double dz, const std::size_t id);

    virtual void execute() override;
    virtual void undo() override;
    virtual bool canUndo() override;
    //virtual bool needToRemember() override;
    std::shared_ptr<BaseCommand> clone() const override;

private:
    double _dx, _dy, _dz;
    std::size_t _id;
};



class ScaleModel : public ModelCommand
{
public:
    ScaleModel(const double kx, const double ky, const double kz, const std::size_t id);

    virtual void execute() override;
    virtual void undo() override;
    virtual bool canUndo() override;
    //virtual bool needToRemember() override;
    std::shared_ptr<BaseCommand> clone() const override;

private:
    double _kx, _ky, _kz;
    std::size_t _id;
};



class RotateModel : public ModelCommand
{
public:
    RotateModel(const double ox, const double oy, const double oz, const std::size_t id);

    virtual void execute() override;
    virtual void undo() override;
    virtual bool canUndo() override;
    //virtual bool needToRemember() override;
    std::shared_ptr<BaseCommand> clone() const override;

private:
    double _ox, _oy, _oz;
    std::size_t _id;
};



class TransformModel : public ModelCommand
{
public:
    TransformModel(Transformer &mtr, const std::size_t id);

    virtual void execute() override;
    virtual void undo() override;
    virtual bool canUndo() override;
    //virtual bool needToRemember() override;
    std::shared_ptr<BaseCommand> clone() const override;

private:
    Transformer _mtr;
    std::size_t _id;
};



class DeleteModel : public ModelCommand
{
public:
    DeleteModel(const std::size_t id);

    virtual void execute() override;
    virtual void undo() override;
    virtual bool canUndo() override;
    //virtual bool needToRemember() override;
    std::shared_ptr<BaseCommand> clone() const override;

private:
    std::size_t _id;
};



class LoadModel : public ModelCommand
{
public:
    LoadModel(const ID &id, std::string &fileName, ModelStructureType impl);

    virtual void execute() override;
    virtual void undo() override;
    virtual bool canUndo() override;
    //virtual bool needToRemember() override;
    std::shared_ptr<BaseCommand> clone() const override;

private:
    std::string _fileName;
    ID _id;
    ModelStructureType _impl;
};

#endif //MODELCOMMAND_H
