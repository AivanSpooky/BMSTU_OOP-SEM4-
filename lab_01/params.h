#ifndef PARAMS_H
#define PARAMS_H

#include <QGraphicsView>
#include <QWidget>
#include <QLineEdit>

#include "errors.h"
#include "point_struct.h"
#include "drawer_struct.h"

typedef struct {
    QLineEdit *dx;
    QLineEdit *dy;
    QLineEdit *dz;
} move_le_t;

typedef struct {
    double dx;
    double dy;
    double dz;
} move_params_t;

typedef struct {
    QLineEdit *kx;
    QLineEdit *ky;
    QLineEdit *kz;
} scale_le_t;

typedef struct {
    double kx;
    double ky;
    double kz;
} scale_params_t;

typedef struct {
    QLineEdit *cx;
    QLineEdit *cy;
    QLineEdit *cz;
} rotate_c_le_t;

typedef struct {
    QLineEdit *ax;
    QLineEdit *ay;
    QLineEdit *az;
    rotate_c_le_t *center;
} rotate_le_t;

typedef struct {
    double ax;
    double ay;
    double az;
} rotate_angles_t;

typedef struct {
    rotate_angles_t angles;
    point_t center;
} rotate_params_t;

/**
 * @brief lineedits_t - структура, содержащая в себе все поля ввода программы
 * @details move - поля ввода для move
 * @details scale - поля ввода для scale
 * @details rotate - поля ввода для rotate
 */
typedef struct {
    move_le_t move;
    scale_le_t scale;
    rotate_le_t rotate;
} lineedits_t;

/**
 * @brief params_t - структура, описывающая параметры программы
 * @details move - параметры для действия move
 * @details scale - параметры для действия scale
 * @details rotate - параметры для действия rotate
 * @details filename - путь к файлу
 * @details canvas - холст для рисования
 * @details centralwidget - виджет главного окна приложения
 */
typedef struct {
    move_params_t move;
    scale_params_t scale;
    rotate_params_t rotate;
    const char* filename;
    drawer_t drawer;
    QWidget *centralwidget;
} params_t;

/**
 * @brief read_params_for_move - функция считывает параметры из lineedits в params для действия move
 * @param params[var] - параметры программы
 * @param lineedits[in] - поля ввода
 * @return функция ничего не возвращает
 */
err_t read_params_for_move(move_params_t &params, move_le_t &lineedits);

/**
 * @brief read_params_for_scale - функция считывает параметры из lineedits в params для действия scale
 * @param params[var] - параметры программы
 * @param les[in] - поля ввода
 * @return функция ничего не возвращает
 */
err_t read_params_for_scale(scale_params_t &params, scale_le_t &lineedits);

/**
 * @brief read_params_for_rotate - функция считывает параметры из lineedits в params для действия rotate
 * @param params[var] - параметры программы
 * @param lineedits[in] - поля ввода
 * @return функция ничего не возвращает
 */
err_t read_params_for_rotate(rotate_params_t &params, rotate_le_t &lineedits);

#endif // PARAMS_H
