#ifndef DRAWER_H
#define DRAWER_H

#include "errors.h"
#include "drawer_struct.h"
#include "figure.h"

/**
 * @brief clear_canvas - функция очищает холст отрисовщика
 * @param canvas[var] - холст
 */
void clear_canvas(canvas_t &canvas);

/**
 * @brief clear_canvas - функция обновляет холст отрисовщика
 * @param canvas[var] - холст
 */
void update_canvas(canvas_t &canvas);
/**
 * @brief draw_lines - функция рисует линии фигуры на отрисовщике
 * @param canvas[var] - холст
 * @param figure[in] - фигура
 * @return функция возвращает код ошибки
 */
err_t draw_lines(canvas_t &canvas, const figure_t &figure);

/**
 * @brief draw_current_line - функция рисует конкретную связь (линию) фигуры на отрисовщике
 * @param canvas[var] - холст
 * @param points[in] - точки фигуры
 * @param link[in] - связь, которая описывает начало и конец линии
 * @return функция ничего не возвращает
 */
void draw_current_line(const canvas_t &canvas, const point_t* points, const link_t &link);



#endif // DRAWER_H
