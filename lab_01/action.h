#ifndef ACTION_H
#define ACTION_H

#include "errors.h"

#include "figure.h"

typedef enum {
    TEXT_READ = 0,
    TEXT_WRITE = 1,
} file_modes_t;

err_t open_file(FILE **file, const char* &filename, const file_modes_t mode);

/**
 * @brief action_load - функция, которая загружает данные из выбранного файла в фигуру
 * @param figure[var] - фигура
 * @param filename[in] - имя файла
 * @return функция возвращает код ошибки
 */
err_t action_load(figure_t &figure, const char *filename);

/**
 * @brief action_save - фнукция сохраняет данные фигуры в выбранный файл
 * @param figure[in] - фигура
 * @param filename[in] - параметры программы
 * @return функция возвращает код ошибки
 */
err_t action_save(const figure_t &figure, const char *filename);

/**
 * @brief action_draw - функция, которая рисует фигуру на холсте
 * @param drawer[var] - отрисовщик (со всеми атрибутами)
 * @param figure[in] - фигура
 * @return функция возвращает код ошибки
 */
err_t action_draw(drawer_t drawer, const figure_t &figure);

/**
 * @brief action_move - функция, которая передвигает фигуру на основе смещений
 * @param figure[var] - фигура
 * @param params[in] - параметры для перемещения
 * @return ункция возвращает код ошибки
 */
err_t action_move(figure_t &figure, const move_params_t &params);

/**
 * @brief action_scale - функция, которая масштабирует фигуру на основе коэффициентов (точка масштабирования взята по умолчанию)
 * @param figure[var] - фигура
 * @param params[in] - параметры для масштабирования
 * @return ункция возвращает код ошибки
 */
err_t action_scale(figure_t &figure, const scale_params_t &params);

/**
 * @brief action_rotate - функция, которая поворачивает фигуру на основе углов с осями (центр поворота взят по умолчанию)
 * @param figure[var] - фигура
 * @param params[in] - параметры для поворота
 * @return ункция возвращает код ошибки
 */
err_t action_rotate(figure_t &figure, const rotate_params_t &params);

#endif // ACTION_H
