#ifndef DRAWER_STRUCT_H
#define DRAWER_STRUCT_H

#include <QGraphicsView>

typedef struct {
    QGraphicsView *canvas_field;
    QPen color = QPen(Qt::black);
} canvas_t;

typedef struct {
    canvas_t canvas;
} drawer_t;

#endif // DRAWER_STRUCT_H
