#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H

#include "basemanager.h"
#include "basecommand.h"
#include "undocommand.h"
#include "cameracommand.h"
#include "modelcommand.h"
#include "commandhistorycarrytaker.h"
#include <memory>


class HistoryManager : public BaseManager
{
public:
    HistoryManager();
    HistoryManager(const HistoryManager &manager) = delete;
    HistoryManager &operator = (const HistoryManager &manager) = delete;

    ~HistoryManager() = default;

    void manageCommand(const std::shared_ptr<BaseCommand>& command);

private:
    std::shared_ptr<CommandHistoryCarryTaker> _historyHolder;
};


#endif //TRANSFORMMANAGER_H
