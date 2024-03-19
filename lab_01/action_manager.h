#ifndef ACTION_MANAGER_H
#define ACTION_MANAGER_H

#include "errors.h"
#include "figure.h"
#include "params.h"

#include "action.h"

/**
 * @brief action_t - множество для описания всех действий программы через состояния
 * @details MOVE - перенос
 * @details SCALE - масштабирование
 * @details ROTATE - поворот
 * @details LOAD - загрузка
 * @details SAVE - сохранение
 * @details DRAW - отрисовка
 * @details CLEAR - очистка
 * @details EXIT - выход
 */
typedef enum {
    MOVE = 0,
    SCALE = 1,
    ROTATE = 3,
    LOAD = 4,
    SAVE = 5,
    DRAW = 6,
    CLEAR = 7,
    EXIT = 8,
} action_t;

/**
 * @brief make_action - функция, которая выполняет определенное действие
 * @param action[in] - действие, которое необходимо выполнить
 * @param params[in] - параметры программы
 * @return функция возвращает код ошибки
 */
err_t make_action(const action_t action, const params_t &params);

#endif // ACTION_MANAGER_H
