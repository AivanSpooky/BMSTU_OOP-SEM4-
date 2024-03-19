#include "figure.h"
#include <stdlib.h>
#include <stdio.h>

figure_t figure_init(void)
{
    static figure_t new_figure;

    new_figure.points_cnt = 0;
    new_figure.points = NULL;
    new_figure.links_cnt = 0;
    new_figure.links = NULL;

    return new_figure;
}

err_t figure_load(figure_t &figure, FILE *file)
{
    err_t rc = read_all_about_points(figure.points, figure.points_cnt, file);
    if (rc == OK)
    {
        rc = read_all_about_links(figure.links, figure.links_cnt, file);
        if (rc != OK)
            figure_free_points(figure.points);
    }

    return rc;
}

void figure_save(FILE *file, const figure_t &figure)
{
    fprintf(file, "%zu\n", figure.points_cnt);
    for (size_t i = 0; i < figure.points_cnt; i++)
        print_cur_point(file, figure.points, i);

    fprintf(file, "%zu\n", figure.links_cnt);
    for (size_t i = 0; i < figure.links_cnt; i++)
        print_cur_link(file, figure.links, i);
}



void figure_free(figure_t &figure)
{
    figure_free_points(figure.points);
    figure_free_links(figure.links);
}
