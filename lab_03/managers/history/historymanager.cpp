#include "historymanager.h"
#include "exceptions.h"
#include <memory>

HistoryManager::HistoryManager() : _historyHolder(std::make_shared<CommandHistoryCarryTaker>()) {}

void HistoryManager::manageCommand(const std::shared_ptr<BaseCommand>& command)
{
    if (command->canUndo())
        _historyHolder->push(command);

    if (auto undoCommand = std::dynamic_pointer_cast<UndoCommand>(command))
    {
        auto lastCommand = _historyHolder->pop();
        if (lastCommand && lastCommand->canUndo())
            lastCommand->undo();
        else if (lastCommand)
        {
            std::string msg = "Cannot undo this action!";
            throw UndoException(msg);
        }
    }
    else if (auto delCmd = std::dynamic_pointer_cast<DeleteCamera>(command))
    {
        _historyHolder->clear();
        delCmd->execute();
    }
    else if (auto delCmd = std::dynamic_pointer_cast<DeleteModel>(command))
    {
        _historyHolder->clear();
        delCmd->execute();
    }
    else
    {
        command->execute();
    }
}
