#include "errors.h"
#include <QDebug>

void error_handler(const err_t rc)
{
    qDebug() << "Ошибка!";
    switch(rc)
    {
        case ERR_INVALID_ACTION:
            qDebug() << "Выбрано несуществующее действие! rc = " << rc << "\n";
            break;
        case ERR_NULL_MALLOC:
            qDebug() << "Не удалось выделить память! rc = " << rc << "\n";
            break;
        case ERR_FILE_NOT_CHOSEN:
            qDebug() << "Файл не выбран! rc = " << rc << "\n";
            break;
        case ERR_FILE_CANNOT_OPEN:
            qDebug() << "Не удалось открыть файл! rc = " << rc << "\n";
            break;
        case ERR_POINT_READ_FAIL:
            qDebug() << "Не удалось прочитать точки! rc = " << rc << "\n";
            break;
        case ERR_LINK_READ_FAIL:
            qDebug() << "Не удалось прочитать связи! rc = " << rc << "\n";
            break;
        case ERR_CNT_READ_FAIL:
            qDebug() << "Не удалось прочитать количество! rc = " << rc << "\n";
            break;
        case ERR_EMPTY_FIGURE_OR_CANVAS:
            qDebug() << "Не удалось отрисовать фигуру! rc = " << rc << "\n";
            break;
        case ERR_SCENE_CREATE_FAIL:
            qDebug() << "Не удалось создать сцену отрисовки! rc = " << rc << "\n";
            break;
        case ERR_WRONG_POINT_ID:
            qDebug() << "Указан неправильный индекс точки! rc = " << rc << "\n";
            break;
        case ERR_INVALID_INPUT:
            qDebug() << "Неверный ввод! rc = " << rc << "\n";
            break;
        case ERR_NULL_POINTER:
            qDebug() << "Передан NULL-указатель! rc = " << rc << "\n";
            break;
        case ERR_FILENAME_EMPTY:
            qDebug() << "Пустое название файла! rc = " << rc << "\n";
            break;
        case ERR_POINTS_NOT_ALLOCATED:
            qDebug() << "Под точки не была выделена память! rc = " << rc << "\n";
            break;
        case ERR_LINKS_NOT_ALLOCATED:
            qDebug() << "Под связи не была выделена память! rc = " << rc << "\n";
            break;
        case ERR_CNT_LOWER_OR_EQUAL_ZERO:
            qDebug() << "Количество должно быть положительным! rc = " << rc << "\n";
            break;
        case ERR_NULL_CANVAS:
            qDebug() << "Холст задан как NULL-указатель! rc = " << rc << "\n";
            break;
        case ERR_FILL_NEEDED_FIELDS:
            qDebug() << "Заполните недостающие поля! rc = " << rc << "\n";
            break;
        default:
            qDebug() << "Произошла ошибка!";
            break;
    }
}
