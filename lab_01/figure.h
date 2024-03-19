#ifndef FIGURE_H
#define FIGURE_H

#include <stdio.h>
#include <inttypes.h>

#include "points.h"
#include "links.h"

#include "params.h"
#include "errors.h"


/**
 * @brief figure_t - структура, описывающая фигуру (каркасную модель)
 * @details points_cnt - количество точек фигуры
 * @details points - массив точек фигуры
 * @details links_cnt - количество связей между точками фигуры
 * @details links - массив связей фигуры
 */

typedef struct {
    size_t points_cnt;
    point_t *points;
} points_info_t;

typedef struct {
    size_t links_cnt;
    link_t *links;
} links_info_t;

typedef struct {
    size_t points_cnt;
    point_t *points;
    size_t links_cnt;
    link_t *links;
} figure_t;

/**
 * @brief figure_init - функция инициализирует фигуру (её поля) значениями по умолчанию
 * @return функция возвращает новую проинициализированную фигуру
 */
figure_t figure_init();

/**
 * @brief figure_load - функция формирует фигуру на основе данных из файла
 * @param figure[out] - фигура
 * @param file[in] - файловая переменная
 * @return функция возвращает код ошибки
 */
err_t figure_load(figure_t &figure, FILE *file);

err_t load_new_figure(figure_t &figure, FILE *file);

/**
 * @brief figure_save - функция сохраняет данные о фигуре в файле
 * @param file[var] - файловая переменная
 * @param figure[in] - фигура
 * @return функция возвращает код ошибки
 */
void figure_save(FILE *file, const figure_t &figure);

/**
 * @brief figure_free - функция освобождает память из под всей фигуры (все поля и сама структура)
 * @param figure[out] - фигура
 * @return функция ничего не возвращает
 */
void figure_free(figure_t &figure);

#endif // FIGURE_H
