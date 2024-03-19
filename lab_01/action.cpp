#include "action.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include <cstdio>
#include <iostream>

#include <QPointF>
#include <QGraphicsView>
#include <GL/glu.h>
#include "drawer.h"

void open_text_file(FILE **file, const char* &filename, const char* mode)
{
    *file = fopen(filename, mode);
}

err_t open_file(FILE **file, const char* &filename, const file_modes_t mode)
{
    if (filename == NULL)
        return ERR_FILE_NOT_CHOSEN;

    err_t rc = OK;
    switch (mode)
    {
        case TEXT_READ:
            open_text_file(file, filename, "r");
            break;

        case TEXT_WRITE:
            open_text_file(file, filename, "w");
            break;

        default:
            rc = ERR_FILE_NOT_CHOSEN;
            break;
    }

    if (rc == OK)
    {
        if (*file != NULL)
            std::cout << "File has opened successfully";
        else
            rc = ERR_FILE_CANNOT_OPEN;
    }

    return rc;
}

void close_file(FILE *file)
{
    fclose(file);
}

err_t action_load(figure_t &figure, const char* filename)
{
    if (filename == NULL)
        return ERR_FILENAME_EMPTY;

    FILE *file = NULL;
    err_t rc = open_file(&file, filename, TEXT_READ);
    if (rc == OK)
    {
        rc = load_new_figure(figure, file);
        close_file(file);
    }

    return rc;
}

err_t load_new_figure(figure_t &figure, FILE *file)
{
    figure_t new_figure = figure_init();
    err_t rc = figure_load(new_figure, file);
    if (rc == OK)
    {
        figure_free(figure);
        figure = new_figure;
    }
    return rc;
}

err_t action_save(const figure_t &figure, const char* filename)
{
    if (filename == NULL)
        return ERR_FILE_NOT_CHOSEN;

    FILE *file = NULL;
    err_t rc = open_file(&file, filename, TEXT_WRITE);
    if (rc == OK)
    {
        figure_save(file, figure);
        close_file(file);
    }

    return rc;
}

err_t action_move(figure_t &figure, const move_params_t &params)
{
    if (!figure.points)
        return ERR_POINTS_NOT_ALLOCATED;
    else if (!figure.links)
        return ERR_LINKS_NOT_ALLOCATED;

    for (size_t i = 0; i < figure.points_cnt; i++)
        move_point(figure.points[i], params);

    return OK;
}

err_t action_scale(figure_t &figure, const scale_params_t &params)
{
    if (!figure.points)
        return ERR_POINTS_NOT_ALLOCATED;
    else if (!figure.links)
        return ERR_LINKS_NOT_ALLOCATED;

    for (size_t i = 0; i < figure.points_cnt; i++)
        scale_point(figure.points[i], params);

    return OK;
}

err_t action_rotate(figure_t &figure, const rotate_params_t &params)
{
    if (!figure.points)
        return ERR_POINTS_NOT_ALLOCATED;
    else if (!figure.links)
        return ERR_LINKS_NOT_ALLOCATED;

    for (size_t i = 0; i < figure.points_cnt; i++)
        turn_point_by_center(figure.points[i], params);

    return OK;
}

err_t action_draw(drawer_t drawer, const figure_t &figure)
{
    if (!figure.points)
        return ERR_POINTS_NOT_ALLOCATED;
    else if (!figure.links)
        return ERR_LINKS_NOT_ALLOCATED;

    clear_canvas(drawer.canvas);

    err_t rc = draw_lines(drawer.canvas, figure);
    if (rc == OK)
        update_canvas(drawer.canvas);

    return rc;
}

