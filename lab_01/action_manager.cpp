#include "action_manager.h"
#include <stdio.h>

err_t make_action(const action_t action, const params_t &params)
{
    static figure_t figure = figure_init();

    err_t rc = OK;
    switch (action)
    {
        case MOVE:
            rc = action_move(figure, params.move);
            break;
        case SCALE:
            rc = action_scale(figure, params.scale);
            break;

        case ROTATE:
            rc = action_rotate(figure, params.rotate);
            break;

        case LOAD:
            rc = action_load(figure, params.filename);
            break;

        case SAVE:
            rc = action_save(figure, params.filename);
            break;

        case DRAW:
            rc = action_draw(params.drawer, figure);
            break;

        case EXIT:
            figure_free(figure);
            break;

        default:
            rc = ERR_INVALID_ACTION;
            break;
    }
    return rc;
}
