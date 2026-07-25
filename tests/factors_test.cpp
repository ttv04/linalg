#include <gtest/gtest.h>
#include "linalg/factors.hpp"
#include "linalg/ops.hpp"
#include "linalg/types.hpp"

TEST(LU, lu) {
    linalg::SquareMatrix A(3, {
        {2,  1, 1},
        {4, -6, 0},
        {-2, 7, 2}
    });

    linalg::LU lu(A);
    
    linalg::Matrix U = lu.U();
    linalg::Matrix L = lu.L();

    EXPECT_DOUBLE_EQ(U.r_size(), 3);
    EXPECT_DOUBLE_EQ(U.c_size(), 3);
    EXPECT_DOUBLE_EQ(L.r_size(), 3);
    EXPECT_DOUBLE_EQ(L.c_size(), 3);

    EXPECT_EQ(L * U == A, true);
}