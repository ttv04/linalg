#pragma once

#include "linalg/types.hpp"
#include "linalg/factors.hpp"

namespace linalg {
    Vector back_substitution(const SquareMatrix& U, const Vector& b);
    Vector gauss_jordan(const SquareMatrix& A, const Vector& b);
    Vector lu_decomposition(const LU& ALU, const Vector& b);
}
