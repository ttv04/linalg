#include <gtest/gtest.h>
#include "linalg/types.hpp"
#include "linalg/ops.hpp"
#include "linalg/factors.hpp"
#include "linalg/solvers.hpp"

namespace {

// A x = b with known solution x = (1, 2, 3)
linalg::SquareMatrix test_A() {
    return linalg::SquareMatrix(3, {
        {2, 1, 1},
        {4, -6, 0},
        {-2, 7, 2}
    });
}

linalg::Vector test_b() {
    return linalg::Vector(3, {5, -2, 9});
}

linalg::Vector test_x() {
    return linalg::Vector(3, {1, 1, 2});
}

}  // namespace

TEST(solvers, back_substitution) {
    // Upper triangular: U x = b with x = (1, 2, 3)
    linalg::SquareMatrix U(3, {
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 1}
    });
    linalg::Vector b(3, {6, 5, 3});
    linalg::Vector x = linalg::back_substitution(U, b);

    EXPECT_DOUBLE_EQ(x.get(0), 1.0);
    EXPECT_DOUBLE_EQ(x.get(1), 2.0);
    EXPECT_DOUBLE_EQ(x.get(2), 3.0);
}

TEST(solvers, gauss_jordan) {
    linalg::Vector x = linalg::gauss_jordan(test_A(), test_b());
    linalg::Vector expected = test_x();

    for (size_t i = 0; i < x.size(); i++) {
        EXPECT_NEAR(x.get(i), expected.get(i), 1e-9);
    }

    // Residual: A x ≈ b
    linalg::Vector Ax = test_A() * x;
    for (size_t i = 0; i < Ax.size(); i++) {
        EXPECT_NEAR(Ax.get(i), test_b().get(i), 1e-9);
    }
}

TEST(solvers, lu_decomposition) {
    linalg::LU alu(test_A());
    linalg::Vector x = linalg::lu_decomposition(alu, test_b());
    linalg::Vector expected = test_x();

    for (size_t i = 0; i < x.size(); i++) {
        EXPECT_NEAR(x.get(i), expected.get(i), 1e-9);
    }
}
