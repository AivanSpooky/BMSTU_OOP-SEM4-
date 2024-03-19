#include "point.h"
#include <cmath>

err_t read_point(point_t &point, FILE *file)
{
    if (file == NULL)
        return ERR_FILE_NOT_CHOSEN;

    err_t rc = OK;
    if (fscanf_s(file, "%lf %lf %lf", &(point.x), &(point.y), &(point.z)) != POINT_ARGS_CNT)
        rc = ERR_POINT_READ_FAIL;

    return rc;
}

void print_cur_point(FILE *file, point_t *points, size_t index)
{
    point_t &point = get_cur_point(points, index);
    print_point(file, point);
}

void print_point(FILE *file, point_t &point)
{
    fprintf(file, "%lf %lf %lf\n", point.x, point.y, point.z);
}

void move_point(point_t &point, const move_params_t &params)
{
    point.x += params.dx;
    point.y += params.dy;
    point.z += params.dz;
}

void move_point_to_center(point_t &point, const point_t &center)
{
    point.x -= center.x;
    point.y -= center.y;
    point.z -= center.z;
}

void move_point_from_center(point_t &point, const point_t &center)
{
    point.x += center.x;
    point.y += center.y;
    point.z += center.z;
}

void scale_point(point_t &point, const scale_params_t &params)
{
    point.x *= params.kx;
    point.y *= params.ky;
    point.z *= params.kz;
}

double degree2radians(double ang)
{
    return ang * M_PI / 180;
}

void turn_point_by_center(point_t &point, const rotate_params_t &params)
{
    move_point_to_center(point, params.center);

    turn_point(point, params.angles);

    move_point_from_center(point, params.center);
}

void turn_point(point_t &point, const rotate_angles_t &angles)
{
    turn_by_x_axis(point, angles.ax);
    turn_by_y_axis(point, angles.ay);
    turn_by_z_axis(point, angles.az);
}

void turn_by_x_axis(point_t &point, const double &angle)
{
    double radian_a = degree2radians(angle);
    double cos_ax = cos(radian_a);
    double sin_ax = sin(radian_a);

    double new_y = point.y * cos_ax - point.z * sin_ax;
    double new_z = point.y * sin_ax + point.z * cos_ax;

    point.y = new_y;
    point.z = new_z;
}

void turn_by_y_axis(point_t &point, const double &angle)
{
    double radian_a = degree2radians(angle);
    double cos_ay = cos(radian_a);
    double sin_ay = sin(radian_a);

    double new_x = point.x * cos_ay + point.z * sin_ay;
    double new_z = -point.x * sin_ay + point.z * cos_ay;

    point.x = new_x;
    point.z = new_z;
}

void turn_by_z_axis(point_t &point, const double &angle)
{
    double radian_a = degree2radians(angle);
    double cos_az = cos(radian_a);
    double sin_az = sin(radian_a);

    double new_x = point.x * cos_az + point.y * sin_az;
    double new_y = -point.x * sin_az + point.y * cos_az;

    point.x = new_x;
    point.y = new_y;
}

point_t &get_cur_point(const point_t* points, size_t i)
{
    return (point_t &) points[i];
}

