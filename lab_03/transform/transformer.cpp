#include "transformer.h"

Transformer::Transformer(const double &dx, const double &dy, const double &dz, const double &kx, const double &ky, const double &kz, const double &ox, const double &oy, const double &oz)
{
    Matrix<double> mtrmove = {{ 1,  0,  0, 0},
                              { 0,  1,  0, 0},
                              { 0,  0,  1, 0},
                              {dx, dy, dz, 1}};
    Matrix<double> mtrscale = {{kx,  0,  0, 0},
                               { 0, ky,  0, 0},
                               { 0,  0, kz, 0},
                               { 0,  0,  0, 1}};
    Matrix<double> mtr_ox = {{1,        0,        0,        0},
                             {0,     cos(ox), -sin(ox),     0},
                             {0,     sin(ox),  cos(ox),     0},
                             {0,        0,        0,        1}};

    Matrix<double> mtr_oy = {{ cos(oy), 0, sin(oy), 0},
                             {    0,    1,    0,    0},
                             {-sin(oy), 0, cos(oy), 0},
                             {    0,    0,    0,    1}};

    Matrix<double> mtr_oz = {{ cos(oz), -sin(oz),     0,        0},
                             { sin(oz),  cos(oz),     0,        0},
                             {    0,        0,        1,        0},
                             {    0,        0,        0,        1}};
    Matrix<double> mtr_final = mtr_ox * mtr_oy * mtr_oz * mtrmove * mtrscale;

    this->_matrix = mtr_final;
}

void Transformer::inverse()
{
    _matrix.inverse();
}

Matrix<double> Transformer::GetMatrix() const
{
    return Matrix<double>(_matrix);
}
