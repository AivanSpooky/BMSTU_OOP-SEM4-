#include "undocommand.h"

std::shared_ptr<BaseCommand> UndoCommand::clone() const
{
    return std::make_shared<UndoCommand>(*this);
}
