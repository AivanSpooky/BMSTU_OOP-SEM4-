#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QVBoxLayout>
#include <vector>
#include <QDebug>
#include <memory>

#include "button.h"

#define FLOOR_COUNT 9
#define DOORS_TIME  600
#define MOVING_TIME 1000

enum Direction
{
    DOWN = -1,
    STOP = 0,
    UP = 1
};

class Controller : public QWidget
{
    Q_OBJECT;

    enum ControllerStatus
    {
        FREE,
        GET_TARGET,
        BUSY
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller() = default;


private:
    bool _targetExist(ssize_t &newFloor);

    ControllerStatus _status;

    ssize_t _currentFloor;
    ssize_t _neededFloor;
    Direction _direction;

    std::vector<std::shared_ptr<Button>> _buttons;
    std::vector<bool> _visitedFloors;
    
    std::unique_ptr<QVBoxLayout> _layout;

signals:
    void _controllerStoppedSignal();
    void _cabinStoppedSignal(bool, ssize_t, ssize_t = 1);
    void _getTargetSignal(ssize_t &neededFloor, ssize_t &_currentFloor);
    void _floorPassedSignal(ssize_t floor, Direction direction);


public slots:
    void newTargetSlot(ssize_t floor);
    void floorPassedSlot(ssize_t floor, Direction direction);
    void controllerStoppedSlot();
};

#endif
