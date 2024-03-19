#ifndef LINK_H
#define LINK_H

#include "inttypes.h"
#include <stdio.h>

#include "errors.h"
#include <QGraphicsView>
#include "point.h"

/**
 * @brief link_t - структура описывает связь между двумя точками
 * @details LINKS_CNT_READ_ARG - кол-во аргументов, необходимых для описании информация о количестве связей
 * @details LINK_ARGS_CNT - количество полей структуры
 * @details id_beg - номер первой точки связи (начало)
 * @details id_end - номер второй точки связи (конец)
 */
#define LINKS_CNT_READ_ARG 1
#define LINK_ARGS_CNT 2
typedef struct {
    size_t id_beg;
    size_t id_end;
} link_t;

/**
 * @brief read_link - функция считывают из файла информацию об одной связи
 * @param link[var] - связь
 * @param file[in] - файловая переменная
 * @return функция возвращает код ошибки
 */
err_t read_link(link_t &link, FILE *file);

/**
 * @brief print_link - функция сохраняет информацию о конкретной связи в файл
 * @param file[var] - файловая переменная
 * @param link[in] - связь
 * @return функция ничего не возвращает
 */
void print_link(FILE *file, link_t &link);

void print_cur_link(FILE *file, link_t* links, size_t index);

/**
 * @brief draw_link - функция рисует конкретную связь на холсте
 * @param canvas[var] - отрисовщик, а конкретно холст и цвет
 * @param first_point[in] - первая точка
 * @param second_point[in] - вторая точка
 * @return функция ничего не возвращает
 */
void draw_link(const canvas_t &canvas, const point_t &first_point, const point_t &second_point);

size_t get_id_beg_from_cur_link(const link_t* links, size_t index);

size_t get_id_end_from_cur_link(const link_t* links, size_t index);

link_t &get_cur_link(const link_t *links, size_t i);

bool link_is_correct(const link_t &link, size_t points_cnt);

#endif // LINK_H
