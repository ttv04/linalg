#pragma once

#include "linalg/factors.hpp"
#include "linalg/ops.hpp"
#include "linalg/types.hpp"

namespace linalg {
    LU::LU(const SquareMatrix& A) 
        : l(SquareMatrix(0)), u(A) {
        
        factor();
    }

    void LU::factor() {
        l = linalg::Identity(u.size());

        for (size_t col = 0; col < u.size() - 1; col++) {
            for (size_t row = col + 1; row < u.size(); row++) {
                double r = -u.get(row, col) / u.get(col, col);
                l.set(row, col, -r);
                u.set_row(
                    row,
                    u.get_row(row) + r * u.get_row(col)
                );
            }
        }
    }

    const SquareMatrix& LU::L() const {
        return l;
    }

    const SquareMatrix& LU::U() const {
        return u;
    }

}

