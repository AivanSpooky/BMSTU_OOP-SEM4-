#include "commandhistorycarrytaker.h"
#include <QDebug>

CommandHistoryCarryTaker::CommandHistoryCarryTaker() : _cmds{}
{
    // Инициализация вектора
}

void CommandHistoryCarryTaker::push(std::shared_ptr<BaseCommand> cmd) {
    if (!cmd) {
        std::cerr << "Error: Trying to push a null command to history." << std::endl;
        return;
    }
    _cmds.push_back(cmd);
    //qDebug() << "Command pushed to history:" << typeid(*cmd).name();
    //std::cout << "Command pushed to history." << std::endl;
}

void CommandHistoryCarryTaker::clear()
{
    _cmds.clear();
}

std::shared_ptr<BaseCommand> CommandHistoryCarryTaker::pop() {
    if (_cmds.empty()) {
        std::cerr << "Error: Trying to pop from an empty history." << std::endl;
        return nullptr;
    }
    auto cmd = _cmds.back();
    _cmds.pop_back();
    //std::cout << "Command popped from history." << std::endl;
    return cmd;
}

bool CommandHistoryCarryTaker::isEmpty() const {
    return _cmds.empty();
}
