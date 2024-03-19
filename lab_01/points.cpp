#include "points.h"


void move_cur_point(point_t* &points, size_t index, const move_params_t &params)
{
    point_t &point = get_cur_point(points, index);
    move_point(point, params);
}

void scale_cur_point(point_t* &points, size_t index, const scale_params_t &params)
{
    point_t &point = get_cur_point(points, index);
    scale_point(point, params);
}

err_t read_all_about_points(point_t* &points, size_t &points_cnt, FILE *file)
{
    err_t rc = read_points_cnt(points_cnt, file);
    if (rc == OK)
        rc = read_points_array(points, points_cnt, file);
    return rc;
}

err_t read_points_cnt(size_t &points_cnt, FILE *file)
{
    if (!file)
        return ERR_FILE_NOT_CHOSEN;

    err_t rc = OK;
    int tmp;
    if (fscanf(file, "%d", &tmp) != POINTS_CNT_READ_ARG)
        rc = ERR_CNT_READ_FAIL;
    if (rc == OK)
    {
        if (tmp <= 0)
            rc = ERR_CNT_LOWER_OR_EQUAL_ZERO;
        else
            points_cnt = (size_t) tmp;
    }
    return rc;
}

err_t read_points_array(point_t* &points, size_t points_cnt, FILE *file)
{
    err_t rc = alloc_points(points, points_cnt);
    if (rc == OK)
    {
        rc = read_points(points, points_cnt, file);
        if (rc != OK)
            figure_free_points(points);
    }
    return rc;
}

err_t read_points(point_t* &points, size_t points_cnt, FILE *file)
{
    if (!file)
        return ERR_FILE_NOT_CHOSEN;
    else if (!points)
        return ERR_POINTS_NOT_ALLOCATED;

    err_t rc = OK;
    for (size_t i = 0; rc == OK && i < points_cnt; i++)
        rc = read_point(points[i], file);

    return rc;
}

err_t alloc_points(point_t* &points, size_t points_cnt)
{
    point_t *tmp = (point_t *)malloc(points_cnt * sizeof(point_t));
    err_t rc = OK;
    if (tmp != NULL)
        points = tmp;
    else
        rc = ERR_NULL_MALLOC;
    return rc;
}

void figure_free_points(point_t* &points)
{
    free(points);
    points = NULL;
}


