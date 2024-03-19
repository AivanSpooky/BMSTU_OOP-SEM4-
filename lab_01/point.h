#ifndef POINT_H
#define POINT_H

#include <inttypes.h>
#include <stdio.h>

#include "errors.h"
#include "params.h"
#include "point_struct.h"

/**
 * @brief turn_point_by_center - функция поворачивает точку по индексу относительно центра поворота
 * @param points[var] - точки
 * @param index[in] - индекс
 * @param params[in] - параметры, необходимые для поворота относительно центра
 */
void turn_point_by_center(point_t &point, const rotate_params_t &params);

/**
 * @brief move_point_to_center - функция двигает точку относительно центра поворота
 * @param point[var] - точка
 * @param center[in] - центр поворота
 */
void move_point_to_center(point_t &point, const point_t &center);

void move_point_from_center(point_t &point, const point_t &center);

err_t read_point(point_t &point, FILE *file);

void print_cur_point(FILE *file, point_t* points, size_t index);

/**
 * @brief print_point - функция записывает в файл информацию о конкретной точке
 * @param file[var] - файловая переменная
 * @param point[in] - точка
 * @return функция ничего не возвращает
 */
void print_point(FILE *file, point_t &point);

/**
 * @brief move_point - функция перемещает точку по всем осям
 * @param point[var] - точка
 * @param params[in] - параметры для действия move
 * @return функция ничего не возвращает
 */
void move_point(point_t &point, const move_params_t &params);

/**
 * @brief scale_point - функция масштабирует точку относительно центра по всем осям
 * @param point[var] - точка
 * @param params[in] - параметры для действия scale
 * @return функция ничего не возвращает
 */
void scale_point(point_t &point, const scale_params_t &params);

/**
 * @brief turn_point - функция поворачивает точку по всем осям (относительно центра холста (0, 0, 0))
 * @param point[var] - точка
 * @param angles[in] - углы поворота оси
 * @param center[in] - центр поворота
 * @return функция ничего не возвращает
 */
void turn_point(point_t &point, const rotate_angles_t &angles);

/**
 * @brief turn_by_x_axis - функция поворачивает точку относительно оси X
 * @param point[var] - точка
 * @param angles[in] - параметры для действия rotate
 * @return функция ничего не возвращает
 */
void turn_by_x_axis(point_t &point, const double &angle);

/**
 * @brief turn_by_y_axis - функция поворачивает точку относительно оси Y
 * @param point[var] - точка
 * @param angle[in] - параметры для действия rotate
 * @return функция ничего не возвращает
 */
void turn_by_y_axis(point_t &point, const double &angle);

/**
 * @brief turn_by_y_axis - функция поворачивает точку относительно оси Y
 * @param point[var] - точка
 * @param angle[in] - параметры для действия rotate
 * @return функция ничего не возвращаеты
 */
void turn_by_z_axis(point_t &point, const double &angle);

/**
 * @brief get_cur_point - функция берет из массива точек точку с индексом i
 * @param points - точки
 * @param i - индекс
 * @return возвращает полученную точку
 */
point_t &get_cur_point(const point_t* points, size_t i);

#endif // POINT_H
