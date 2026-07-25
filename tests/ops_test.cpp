#include <gtest/gtest.h>
#include "linalg/ops.hpp"

TEST(ops, transpose) {
    linalg::Matrix A(2, 3, {
        {1, 2, 4},
        {9, 3, 1}
    });

    linalg::Matrix At = linalg::transpose(A);

    EXPECT_EQ(At.r_size(), 3);
    EXPECT_EQ(At.c_size(), 2);
    EXPECT_DOUBLE_EQ(At.get(0, 0), 1.0);
    EXPECT_DOUBLE_EQ(At.get(0, 1), 9.0);
    EXPECT_DOUBLE_EQ(At.get(1, 0), 2.0);
    EXPECT_DOUBLE_EQ(At.get(1, 1), 3.0);
    EXPECT_DOUBLE_EQ(At.get(2, 0), 4.0);
    EXPECT_DOUBLE_EQ(At.get(2, 1), 1.0);
}

TEST(ops, dot) {
    linalg::Vector a(5, {1, 0, 1, 0, 1});
    linalg::Vector b(5, {1, 2, 4, 8, 16});

    EXPECT_DOUBLE_EQ(linalg::dot(a, b), 21.0);
}

TEST(ops, scalar_vector) {
    linalg::Vector v(3, {1, 2, 3});

    linalg::Vector left = 2.0 * v;
    linalg::Vector right = v * 2.0;

    for (size_t i = 0; i < v.size(); i++) {
        EXPECT_DOUBLE_EQ(left.get(i), 2.0 * (i + 1));
        EXPECT_DOUBLE_EQ(right.get(i), 2.0 * (i + 1));
    }
}

TEST(ops, scalar_matrix) {
    linalg::Matrix A(2, 2, {
        {1, 2},
        {3, 4}
    });

    linalg::Matrix left = 3.0 * A;
    linalg::Matrix right = A * 3.0;

    EXPECT_DOUBLE_EQ(left.get(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(left.get(0, 1), 6.0);
    EXPECT_DOUBLE_EQ(left.get(1, 0), 9.0);
    EXPECT_DOUBLE_EQ(left.get(1, 1), 12.0);

    EXPECT_DOUBLE_EQ(right.get(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(right.get(0, 1), 6.0);
    EXPECT_DOUBLE_EQ(right.get(1, 0), 9.0);
    EXPECT_DOUBLE_EQ(right.get(1, 1), 12.0);
}

TEST(ops, vector_add) {
    linalg::Vector a(3, {1, 2, 3});
    linalg::Vector b(3, {4, 5, 6});
    linalg::Vector c = a + b;

    EXPECT_EQ(c.size(), 3);
    EXPECT_DOUBLE_EQ(c.get(0), 5.0);
    EXPECT_DOUBLE_EQ(c.get(1), 7.0);
    EXPECT_DOUBLE_EQ(c.get(2), 9.0);
}

TEST(ops, matrix_add) {
    linalg::Matrix A(2, 2, {
        {1, 2},
        {3, 4}
    });
    linalg::Matrix B(2, 2, {
        {5, 6},
        {7, 8}
    });
    linalg::Matrix C = A + B;

    EXPECT_EQ(C.r_size(), 2);
    EXPECT_EQ(C.c_size(), 2);
    EXPECT_DOUBLE_EQ(C.get(0, 0), 6.0);
    EXPECT_DOUBLE_EQ(C.get(0, 1), 8.0);
    EXPECT_DOUBLE_EQ(C.get(1, 0), 10.0);
    EXPECT_DOUBLE_EQ(C.get(1, 1), 12.0);
}

TEST(ops, matrix_vector) {
    // A (3x2) * b (2) -> c (3)
    linalg::Matrix A(3, 2, {
        {1, 2},
        {3, 4},
        {5, 6}
    });
    linalg::Vector b(2, {1, 2});
    linalg::Vector c = A * b;

    EXPECT_EQ(c.size(), 3);
    EXPECT_DOUBLE_EQ(c.get(0), 5.0);   // 1*1 + 2*2
    EXPECT_DOUBLE_EQ(c.get(1), 11.0);  // 3*1 + 4*2
    EXPECT_DOUBLE_EQ(c.get(2), 17.0);  // 5*1 + 6*2
}

TEST(ops, vector_matrix) {
    // b (2) as row * A (2x3) -> c (3)
    linalg::Vector b(2, {1, 2});
    linalg::Matrix A(2, 3, {
        {1, 2, 3},
        {4, 5, 6}
    });
    linalg::Vector c = b * A;

    EXPECT_EQ(c.size(), 3);
    EXPECT_DOUBLE_EQ(c.get(0), 9.0);   // 1*1 + 2*4
    EXPECT_DOUBLE_EQ(c.get(1), 12.0);  // 1*2 + 2*5
    EXPECT_DOUBLE_EQ(c.get(2), 15.0);  // 1*3 + 2*6
}

TEST(ops, matrix_matrix) {
    // A (2x3) * B (3x2) -> C (2x2)
    linalg::Matrix A(2, 3, {
        {1, 2, 3},
        {4, 5, 6}
    });
    linalg::Matrix B(3, 2, {
        {7, 8},
        {9, 10},
        {11, 12}
    });
    linalg::Matrix C = A * B;

    EXPECT_EQ(C.r_size(), 2);
    EXPECT_EQ(C.c_size(), 2);
    EXPECT_DOUBLE_EQ(C.get(0, 0), 58.0);   // 1*7 + 2*9 + 3*11
    EXPECT_DOUBLE_EQ(C.get(0, 1), 64.0);   // 1*8 + 2*10 + 3*12
    EXPECT_DOUBLE_EQ(C.get(1, 0), 139.0);  // 4*7 + 5*9 + 6*11
    EXPECT_DOUBLE_EQ(C.get(1, 1), 154.0);  // 4*8 + 5*10 + 6*12
}

TEST(ops, identity_multiply) {
    linalg::Matrix A(2, 2, {
        {2, 3},
        {4, 5}
    });
    linalg::SquareMatrix I = linalg::Identity(2);

    linalg::Matrix left = I * A;
    linalg::Matrix right = A * I;

    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 2; j++) {
            EXPECT_DOUBLE_EQ(left.get(i, j), A.get(i, j));
            EXPECT_DOUBLE_EQ(right.get(i, j), A.get(i, j));
        }
    }
}

TEST(ops, vector_negate) {
    linalg::Vector v(3, {1, -2, 3});
    linalg::Vector neg = -v;

    EXPECT_EQ(neg.size(), 3);
    EXPECT_DOUBLE_EQ(neg.get(0), -1.0);
    EXPECT_DOUBLE_EQ(neg.get(1), 2.0);
    EXPECT_DOUBLE_EQ(neg.get(2), -3.0);
}

TEST(ops, matrix_negate) {
    linalg::Matrix A(2, 2, {
        {1, -2},
        {3, -4}
    });
    linalg::Matrix neg = -A;

    EXPECT_EQ(neg.r_size(), 2);
    EXPECT_EQ(neg.c_size(), 2);
    EXPECT_DOUBLE_EQ(neg.get(0, 0), -1.0);
    EXPECT_DOUBLE_EQ(neg.get(0, 1), 2.0);
    EXPECT_DOUBLE_EQ(neg.get(1, 0), -3.0);
    EXPECT_DOUBLE_EQ(neg.get(1, 1), 4.0);
}

TEST(ops, vector_eq) {
    linalg::Vector a(3, {1, 2, 3});
    linalg::Vector b(3, {1, 2, 3});
    linalg::Vector c(3, {1, 2, 4});

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

TEST(ops, matrix_eq) {
    linalg::Matrix A(2, 2, {
        {1, 2},
        {3, 4}
    });
    linalg::Matrix B(2, 2, {
        {1, 2},
        {3, 4}
    });
    linalg::Matrix C(2, 2, {
        {1, 2},
        {3, 5}
    });

    EXPECT_TRUE(A == B);
    EXPECT_FALSE(A == C);
}
