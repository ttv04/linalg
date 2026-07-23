#pragma once
#include "linalg/types.hpp"

namespace linalg {
    Vector operator*(const Matrix& A, const Vector& b);
    Vector operator*(const Vector& b, const Matrix& A);
    Matrix operator*(const Matrix& A, const Matrix& B);
    Vector operator*(const double& scalar, const Vector& v);
    Vector operator*(const Vector& v, const double& scalar);
    Matrix operator*(const double& scalar, const Matrix& mat);
    Matrix operator*(const Matrix& mat, const double& scalar);
    Vector operator+(const Vector& a, const Vector& b);
    Matrix operator+(const Matrix& A, const Matrix& B);

    double dot(const Vector& a, const Vector& b);
    Matrix transpose(const Matrix& A);
}