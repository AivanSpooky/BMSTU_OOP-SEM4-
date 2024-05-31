#include "button.h"
#include <QDebug>

void Button::reset()
{
    if (_status == ACTIVE)
    {
        this->setStyleSheet("background-color:cyan;"
                            "border-style: outset;"
                            "border-width: 2px;"
                            "border-radius: 10px;"
                            "border-color: beige;"
                            "font: bold 14px;"
                            "padding: 6px;");
        this->update();

        _status = NOT_ACTIVE;

        // Возвращаем возможность ввода виджета
        this->setDisabled(false);
    }
}

Button::Button(QWidget *parent) : QPushButton(parent)
{
    QObject::connect(this, SIGNAL(clicked()),
                     this, SLOT(_pressedSlot()));
    QObject::connect(this, SIGNAL(unpressedSignal()),
                     this, SLOT(unpressedSlot()));

    _status = NOT_ACTIVE;
    _buttonFloor = 1;

    setStyleSheet("background-color:gray;"
                  "border-style: outset;"
                  "border-width: 2px;"
                  "border-radius: 10px;"
                  "border-color: beige;"
                  "font: bold 14px;"
                  "padding: 6px;");
}

void Button::setFloor(const ssize_t &floor)
{
    _buttonFloor = floor;
}

void Button::_pressedSlot()
{
    if (_status == NOT_ACTIVE)
    {
        // Сделали красным
        this->setStyleSheet("background-color:red;"
                            "border-style: outset;"
                            "border-width: 2px;"
                            "border-radius: 10px;"
                            "border-color: beige;"
                            "font: bold 14px;"
                            "padding: 6px;");
        this->update();

        // Сказали, что кнопка сейчас нажата
        _status = ACTIVE;
        // Отключили события ввода виджета
        this->setDisabled(true);

        // Вызывали обработчик нажатия сигнала 
        emit pressedSignal(_buttonFloor);
    }
}

void Button::unpressedSlot()
{
    if (_status == ACTIVE)
    {
        this->setStyleSheet("background-color:cyan;"
                            "border-style: outset;"
                            "border-width: 2px;"
                            "border-radius: 10px;"
                            "border-color: beige;"
                            "font: bold 14px;"
                            "padding: 6px;");
        this->update();

        _status = NOT_ACTIVE;

        // Возвращаем возможность ввода виджета
        this->setDisabled(false);
    }
}

void Button::setActiveState()
{
    // Этот этаж мы сейчас проезжаем
    this->setStyleSheet("background-color:yellow;"
                        "border-style: outset;"
                        "border-width: 2px;"
                        "border-radius: 10px;"
                        "border-color: beige;"
                        "font: bold 14px;"
                        "padding: 6px;");
    this->update();
}

void Button::setDefaultState()
{
    // Этот этаж мы проехали
    this->setStyleSheet("background-color:gray;"
                        "border-style: outset;"
                        "border-width: 2px;"
                        "border-radius: 10px;"
                        "border-color: beige;"
                        "font: bold 14px;"
                        "padding: 6px;");
    this->update();
}

