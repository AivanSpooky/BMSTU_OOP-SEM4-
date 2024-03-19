#include "link.h"

err_t read_link(link_t &link, FILE *file)
{
    err_t rc = OK;
    if (fscanf_s(file, "%zu %zu", &(link.id_beg), &(link.id_end)) != LINK_ARGS_CNT)
        rc = ERR_LINK_READ_FAIL;
    return rc;
}

void print_link(FILE *file, link_t &link)
{
    fprintf(file, "%zu %zu\n", link.id_beg, link.id_end);
}

void draw_link(const canvas_t &canvas, const point_t &first_point, const point_t &second_point)
{
    canvas.canvas_field->scene()->addLine(first_point.x, first_point.y, second_point.x, second_point.y, canvas.color);
}

size_t get_id_beg_from_cur_link(const link_t* links, size_t index)
{
    link_t &cur_link = get_cur_link(links, index);
    return cur_link.id_beg;
}

void print_cur_link(FILE *file, link_t *links, size_t index)
{
    link_t &link = get_cur_link(links, index);
    print_link(file, link);
}

size_t get_id_end_from_cur_link(const link_t* links, size_t index)
{
    link_t &cur_link = get_cur_link(links, index);
    return cur_link.id_end;
}

link_t &get_cur_link(const link_t* links, size_t i)
{
    return (link_t &) links[i];
}

bool link_is_correct(const link_t &link, size_t points_cnt)
{
    if (link.id_beg < points_cnt && link.id_end < points_cnt)
        return true;
    return false;
}
