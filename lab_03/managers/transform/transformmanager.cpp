#include <cmath>

#include "transformmanager.h"

void TransformManager::moveObject(const std::shared_ptr <Object> &object,
                                  const double &dx,
                                  const double &dy,
                                  const double &dz)
{
    Transformer mtr(dx, dy, dz, 1, 1, 1, 0, 0, 0);

    object->updateCenter();
    object->transform(mtr, object->getCenter());
}


void TransformManager::scaleObject(const std::shared_ptr <Object> &object,
                                   const double &kx,
                                   const double &ky,
                                   const double &kz)
{
    Transformer mtr = Transformer(0, 0, 0, kx, ky, kz, 0, 0, 0);

    object->updateCenter();
    object->transform(mtr, object->getCenter());
}


void TransformManager::rotateObject(const std::shared_ptr <Object> &object,
                                   const double &ox,
                                   const double &oy,
                                   const double &oz)
{
    Transformer mtr = Transformer(0, 0, 0, 1, 1, 1, ox, oy, oz);

    object->updateCenter();
    object->transform(mtr, object->getCenter());
}

void TransformManager::transformObject(const std::shared_ptr<Object> &object,
                                       Transformer &mtr)
{
    object->updateCenter();
    object->transform(mtr, object->getCenter());
}
