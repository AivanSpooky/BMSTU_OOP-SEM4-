#ifndef COMMANDHISTORYCARRYTAKER_H
#define COMMANDHISTORYCARRYTAKER_H

#include "basehistorycarrytaker.h"

class CommandHistoryCarryTaker : public BaseHistoryCarryTaker
{
public:
    CommandHistoryCarryTaker();
    ~CommandHistoryCarryTaker() = default;

    void push(std::shared_ptr<BaseCommand> cmd);
    void clear();
    std::shared_ptr<BaseCommand> pop();
    bool isEmpty() const;

private:
    std::vector<std::shared_ptr<BaseCommand>> _cmds;
};

#endif // COMMANDHISTORYCARRYTAKER_H
