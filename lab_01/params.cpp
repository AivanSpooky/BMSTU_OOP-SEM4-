#include "params.h"

err_t read_params_for_move(move_params_t &params, move_le_t &lineedits)
{
    if (lineedits.dx->text().isEmpty() || !lineedits.dx->hasAcceptableInput() ||\
        lineedits.dy->text().isEmpty() || !lineedits.dy->hasAcceptableInput() ||\
        lineedits.dz->text().isEmpty() || !lineedits.dz->hasAcceptableInput())
    {
        return ERR_FILL_NEEDED_FIELDS;
    }

    double dx = lineedits.dx->text().toDouble();
    double dy = lineedits.dy->text().toDouble();
    double dz = lineedits.dz->text().toDouble();

    params.dx = dx;
    params.dy = dy;
    params.dz = dz;
    return OK;
}

err_t read_params_for_scale(scale_params_t &params, scale_le_t &lineedits)
{
    if (lineedits.kx->text().isEmpty() || !lineedits.kx->hasAcceptableInput() || \
        lineedits.ky->text().isEmpty() || !lineedits.ky->hasAcceptableInput() || \
        lineedits.kz->text().isEmpty() || !lineedits.kz->hasAcceptableInput())
    {
        return ERR_FILL_NEEDED_FIELDS;
    }

    double kx = lineedits.kx->text().toDouble();
    double ky = lineedits.ky->text().toDouble();
    double kz = lineedits.kz->text().toDouble();

    //params->scale = new scale_params_t;
    params.kx = kx;
    params.ky = ky;
    params.kz = kz;
    return OK;
}

err_t read_params_for_rotate(rotate_params_t &params, rotate_le_t &lineedits)
{
    if (lineedits.ax->text().isEmpty() || !lineedits.ax->hasAcceptableInput() || \
        lineedits.ay->text().isEmpty() || !lineedits.ay->hasAcceptableInput() || \
        lineedits.az->text().isEmpty() || !lineedits.az->hasAcceptableInput() /*|| \
        les->rotate.center->cx->text().isEmpty() || !les->rotate.center->cx->hasAcceptableInput() || \
        les->rotate.center->cy->text().isEmpty() || !les->rotate.center->cy->hasAcceptableInput() || \
        les->rotate.center->cz->text().isEmpty() || !les->rotate.center->cz->hasAcceptableInput()*/)
    {
        return ERR_FILL_NEEDED_FIELDS;
    }
    double ax = lineedits.ax->text().toDouble();
    double ay = lineedits.ay->text().toDouble();
    double az = lineedits.az->text().toDouble();

    //params->rotate = new rotate_params_t;
    params.angles.ax = ax;
    params.angles.ay = ay;
    params.angles.az = az;

    // double cx = les->rotate.center->cx->text().toDouble();
    // double cy = les->rotate.center->cy->text().toDouble();
    // double cz = les->rotate.center->cz->text().toDouble();
    double cx = 0;
    double cy = 0;
    double cz = 0;
    //params->rotate->center = new point_t;
    params.center.x = cx;
    params.center.y = cy;
    params.center.z = cz;
    return OK;
}
