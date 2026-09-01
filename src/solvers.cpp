#include "linalg/solvers.hpp"
#include "linalg/ops.hpp"

namespace linalg {

    Vector back_substitution(const SquareMatrix& U, const Vector& b) {
        const size_t n = U.size();
        Vector x(n);

        // Solve Ux = b for upper-triangular U (bottom → top)
        for (size_t i = n; i-- > 0;) {
            double sum = b.get(i);
            for (size_t j = i + 1; j < n; j++) {
                sum -= U.get(i, j) * x.get(j);
            }
            x.set(i, sum / U.get(i, i));
        }
        return x;
    }

    Vector gauss_jordan(const SquareMatrix& A, const Vector& b) {
        // Forward elimination (same row ops as LU), applied to A and b
        SquareMatrix U = A;
        Vector y = b;
        const size_t n = A.size();

        for (size_t col = 0; col + 1 < n; col++) {
            for (size_t row = col + 1; row < n; row++) {
                double r = -U.get(row, col) / U.get(col, col);
                U.set_row(row, U.get_row(row) + r * U.get_row(col));
                y.set(row, y.get(row) + r * y.get(col));
            }
        }

        return back_substitution(U, y);
    }

    Vector lu_decomposition(const LU& ALU, const Vector& b) {
        const SquareMatrix& L = ALU.L();
        const SquareMatrix& U = ALU.U();
        const size_t n = L.size();

        // Forward substitution: Lz = b (L unit lower-triangular)
        Vector z(n);
        for (size_t i = 0; i < n; i++) {
            double sum = b.get(i);
            for (size_t j = 0; j < i; j++) {
                sum -= L.get(i, j) * z.get(j);
            }
            z.set(i, sum / L.get(i, i));
        }

        // Back substitution: Ux = z
        return back_substitution(U, z);
    }

}  // namespace linalg
