#ifndef ERRORS_H
#define ERRORS_H

// Описание множества всех возможных ошибок в программе
typedef enum {
    OK = 0,
    ERR_INVALID_ACTION = 1,
    ERR_NULL_MALLOC = 2,
    ERR_FILE_NOT_CHOSEN = 3,
    ERR_FILE_CANNOT_OPEN = 4,
    ERR_POINT_READ_FAIL = 5,
    ERR_LINK_READ_FAIL = 6,
    ERR_CNT_READ_FAIL = 7,
    ERR_EMPTY_FIGURE_OR_CANVAS = 8,
    ERR_SCENE_CREATE_FAIL = 9,
    ERR_QQUICKWIDGET_NOT_READY = 10,
    ERR_WRONG_POINT_ID = 11,
    ERR_INVALID_INPUT = 12,
    ERR_NULL_POINTER = 13,
    ERR_FILENAME_EMPTY = 14,
    ERR_POINTS_NOT_ALLOCATED = 15,
    ERR_LINKS_NOT_ALLOCATED = 16,
    ERR_CNT_LOWER_OR_EQUAL_ZERO = 17,
    ERR_NULL_CANVAS = 18,
    ERR_FILL_NEEDED_FIELDS = 19,
} err_t;

void error_handler(const err_t rc);

#endif // ERRORS_H
