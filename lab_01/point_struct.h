#ifndef POINT_STRUCT_H
#define POINT_STRUCT_H

/**
 * @brief point_t - структура, описывающая информацию о конкретной точке
 * @details POINTS_CNT_READ_ARG - кол-во аргументов, необходимых для описании информация о количестве точек
 * @details x - координата по оси x
 * @details y - координата по оси y
 * @details z - координата по оси z
 */
#define POINTS_CNT_READ_ARG 1
#define POINT_ARGS_CNT 3
typedef struct {
    double x;
    double y;
    double z;
} point_t;

#endif // POINT_STRUCT_H
