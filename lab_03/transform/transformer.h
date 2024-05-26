#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "matrix.h"
#include <cmath>

class Transformer
{
public:
    Transformer(const double &dx, const double &dy, const double &dz, const double &kx, const double &ky, const double &kz, const double &ox, const double &oy, const double &oz);
    operator bool() const noexcept;
    ~Transformer() = default;

    void inverse();
    Matrix<double> GetMatrix() const;
private:
    Matrix<double> _matrix;
};

#endif //TRANSFORMER_H
