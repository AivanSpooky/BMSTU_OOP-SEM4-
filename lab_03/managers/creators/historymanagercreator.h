#ifndef HISTORYMANAGERCREATOR_H
#define HISTORYMANAGERCREATOR_H

#include <memory>
#include "historymanager.h"

class HistoryManagerCreator
{
public:
    std::shared_ptr<HistoryManager> createManager();

private:
    void createInstance();

    std::shared_ptr<HistoryManager> _manager;
};

#endif // HISTORYMANAGERCREATOR_H
