#include "drawer.h"

void clear_canvas(canvas_t &canvas)
{
    canvas.canvas_field->scene()->clear();
}

void update_canvas(canvas_t &canvas)
{
    canvas.canvas_field->viewport()->update();
}

err_t draw_lines(canvas_t &canvas, const figure_t &figure)
{
    err_t rc = OK;
    for (size_t i = 0; rc == OK && i < figure.links_cnt; i++)
    {
        if (link_is_correct(figure.links[i], figure.points_cnt))
            draw_current_line(canvas, figure.points, figure.links[i]);
        else
            rc = ERR_WRONG_POINT_ID;
    }
    return rc;
}

void draw_current_line(const canvas_t &canvas, const point_t* points, const link_t &link)
{
    point_t point_beg = points[link.id_beg];
    point_t point_end = points[link.id_end];
    draw_link(canvas, point_beg, point_end);
}


