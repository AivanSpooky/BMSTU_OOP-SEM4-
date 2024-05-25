#include "historymanagercreator.h"


std::shared_ptr<HistoryManager> HistoryManagerCreator::createManager()
{
    if (nullptr == _manager)
        createInstance();

    return _manager;
}


void HistoryManagerCreator::createInstance()
{
    static std::shared_ptr<HistoryManager> manager(new HistoryManager());
    _manager = manager;
}
