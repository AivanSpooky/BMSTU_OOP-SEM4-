#include "links.h"

err_t read_all_about_links(link_t* &links, size_t &links_cnt, FILE *file)
{
    err_t rc = read_links_cnt(links_cnt, file);
    if (rc == OK)
        rc = read_links_array(links, links_cnt, file);
    return rc;
}

err_t read_links_cnt(size_t &links_cnt, FILE *file)
{
    if (!file)
        return ERR_FILE_NOT_CHOSEN;

    err_t rc = OK;
    int tmp;
    if (fscanf(file, "%d", &tmp) != LINKS_CNT_READ_ARG)
        rc = ERR_CNT_READ_FAIL;
    if (rc == OK)
    {
        if (tmp <= 0)
            rc = ERR_CNT_LOWER_OR_EQUAL_ZERO;
        else
            links_cnt = (size_t) tmp;
    }
    return rc;
}

err_t read_links_array(link_t* &links, size_t links_cnt, FILE *file)
{
    err_t rc = alloc_links(links, links_cnt);
    if (rc == OK)
    {
        rc = read_links(links, links_cnt, file);
        if (rc != OK)
            figure_free_links(links);
    }
    return rc;
}

err_t read_links(link_t* &links, size_t links_cnt, FILE *file)
{
    if (!file)
        return ERR_FILE_NOT_CHOSEN;
    else if (!links)
        return ERR_LINKS_NOT_ALLOCATED;

    err_t rc = OK;
    for (size_t i = 0; rc == OK && i < links_cnt; i++)
        rc = read_link(links[i], file);

    return rc;
}

err_t alloc_links(link_t* &links, size_t links_cnt)
{
    link_t *tmp = (link_t *)malloc(links_cnt * sizeof(link_t));
    err_t rc = OK;
    if (tmp != NULL)
        links = tmp;
    else
        rc = ERR_NULL_MALLOC;
    return rc;
}

void figure_free_links(link_t* &links)
{
    free(links);
    links = NULL;
}
