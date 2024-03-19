#ifndef LINKS_H
#define LINKS_H

#include "link.h"

/**
 * @brief read_all_about_links - функция считывает из файла все о связях (их количество и массив самих связей)
 * @param links[out] - массив связей
 * @param links_cnt[out] - количество связей
 * @param file[in] - файловая переменная
 * @return функция возвращает код ошибки
 */
err_t read_all_about_links(link_t* &links, size_t &links_cnt, FILE *file);

/**
 * @brief read_links_cnt - функция считывает из файла информацию о количестве связей
 * @param figure[var] - фигура
 * @param file[in] - файловая переменная
 * @return функция возвращает код ошибки
 */
err_t read_links_cnt(size_t &links_cnt, FILE *file);

err_t read_links_array(link_t* &links, size_t links_cnt, FILE *file);

/**
 * @brief read_links - функция считывает из файла информацию о связях
 * @param links[var] - связи фигуры
 * @param links_cnt[in] - количество связей
 * @param file[in] - файловая переменная
 * @return функция возвращает код ошибки
 */
err_t read_links(link_t* &links, size_t links_cnt, FILE *file);

/**
 * @brief alloc_links - функция выделяет память под связи
 * @param links[var] - связи
 * @param links_cnt[in] - количество связей
 * @return функция возвращает код ошибки
 */
err_t alloc_links(link_t *&links, size_t links_cnt);

/**
 * @brief figure_free_points - функция освобождает память только из под связей фигуры
 * @param links[out] - связи
 * @param links_cnt[out] - количество связей
 * @return функция ничего не возвращает
 */
void figure_free_links(link_t* &links);



#endif // LINKS_H
