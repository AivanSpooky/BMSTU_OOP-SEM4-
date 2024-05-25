#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H

#include "basecommand.h"

class UndoCommand : public BaseCommand {
public:
    UndoCommand() = default;
    virtual ~UndoCommand() = default;

    void execute() override {
        // This will be handled in HistoryManager
    }

    void undo() override {}

    bool canUndo() override
    {
        return false;
    }
    // virtual bool needToRemember() override
    // {
    //     return false;
    // }
    std::shared_ptr<BaseCommand> clone() const override;
};

#endif // UNDOCOMMAND_H
