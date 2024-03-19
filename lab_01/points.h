#ifndef POINTS_H
#define POINTS_H

#include "point.h"

void move_cur_point(point_t* &points, size_t index, const move_params_t &params);

void scale_cur_point(point_t* &points, size_t index, const scale_params_t &params);

void rotate_cur_point(point_t* &points, size_t index, const rotate_params_t &params);

/**
 * @brief read_points_cnt - функция считывает из файла информацию о количестве точек
 * @param figure[var] - фигура
 * @param file[in] - файловая переменная
 * @return функция возвращает код ошибки
 */
err_t read_points_cnt(size_t &points_cnt, FILE *file);

/**
 * @brief read_all_about_points - функция считывает из файла все о точках (их количество и массив самих точек)
 * @param points[out] - массив точек
 * @param points_cnt[out] - количество точек
 * @param file[in] - файловая переменная
 * @return функция возвращает код ошибки
 */
err_t read_all_about_points(point_t* &points, size_t &points_cnt, FILE *file);

err_t read_points_array(point_t* &points, size_t points_cnt, FILE *file);

/**
 * @brief read_points - функция считывает из файла информацию о точках
 * @param points[var] - фигура
 * @param file[in] - файловая переменная
 * @return функция возвращает код ошибки
 */
err_t read_points(point_t* &points, size_t points_cnt, FILE *file);

/**
 * @brief alloc_points - функция выделяет память под точки
 * @param points[var] - точки фигуры
 * @param points_cnt[in] - количество точек
 * @return функция возвращает код ошибки
 */
err_t alloc_points(point_t *&points, size_t points_cnt);

/**
 * @brief figure_free_points - функция освобождает память только из под точек фигуры
 * @param points[out] - точки
 * @param points_cnt[out] - количество точек
 * @return функция ничего не возвращает
 */
void figure_free_points(point_t* &points);


#endif // POINTS_H
