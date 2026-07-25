#include <gtest/gtest.h>
#include "linalg/types.hpp"

TEST(types, vector0) {
    // Basic vector object testing
    linalg::Vector v1(10);
    EXPECT_EQ(v1.size(), 10);
    for (size_t i = 0; i < v1.size(); i++) {
        EXPECT_DOUBLE_EQ(v1.get(i), 0.0);
    }
    
    v1.set(4, 10.2);
    EXPECT_DOUBLE_EQ(v1.get(4), 10.2);
}

TEST(types, vectorrand) {
    // Vector with modified constructor
    linalg::Vector v1(10, {
        1, 2, 4, 8, 16, 32, 64, 128, 256, 512
    });

    double c = 1;
    for (size_t i = 0; i < v1.size(); i++) {
        EXPECT_DOUBLE_EQ(v1.get(i), c);
        c *= 2;
    }

}

TEST(types, matrix0) {
    // Basic matrix object testing
    linalg::Matrix m1(5, 2);

    EXPECT_EQ(m1.r_size(), 5);
    EXPECT_EQ(m1.c_size(), 2);
    for (size_t i = 0; i < m1.r_size(); i++) {
        for (size_t j = 0; j < m1.c_size(); j++) {
            EXPECT_DOUBLE_EQ(m1.get(i, j), 0.0);
        }
    }
    m1.set(3, 4, 12.4);
    EXPECT_DOUBLE_EQ(m1.get(3, 4), 12.4);
}

TEST(types, matrixrand) {
    linalg::Matrix m1(3, 4, {
        {1, 2, 3, 4},
        {1, 4, 9, 16},
        {1, 8, 27, 64}
    });

    for (size_t j = 0; j < m1.c_size(); j++) {
        double sum = (double)(j + 1);
        for (size_t i = 0; i < m1.r_size(); i++) {
            EXPECT_DOUBLE_EQ(m1.get(i, j), sum);
            sum *= (j + 1);
        }
    }
}

TEST(types, squarematrix) {
    linalg::SquareMatrix sm1(3);

    EXPECT_EQ(sm1.size(), 3);
    for (size_t i = 0; i < sm1.size(); i++) {
        for (size_t j = 0; j < sm1.size(); j++) {
            EXPECT_DOUBLE_EQ(sm1.get(i, j), 0.0);
        }
    }
}

TEST(types, identitymatrix) {
    linalg::SquareMatrix I = linalg::Identity(3);
    for (size_t i = 0; i < I.size(); i++) {
        for (size_t j = 0; j < I.size(); j++) {
            if (i == j) {
                EXPECT_DOUBLE_EQ(I.get(i, j), 1.0);
            }
            else {
                EXPECT_DOUBLE_EQ(I.get(i, j), 0.0);
            }
        }
    } 
}

TEST(types, get_row) {
    linalg::Matrix A(3, 4, {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    });

    linalg::Vector row0 = A.get_row(0);
    linalg::Vector row1 = A.get_row(1);
    linalg::Vector row2 = A.get_row(2);

    EXPECT_EQ(row0.size(), 4);
    EXPECT_DOUBLE_EQ(row0.get(0), 1.0);
    EXPECT_DOUBLE_EQ(row0.get(1), 2.0);
    EXPECT_DOUBLE_EQ(row0.get(2), 3.0);
    EXPECT_DOUBLE_EQ(row0.get(3), 4.0);

    EXPECT_EQ(row1.size(), 4);
    EXPECT_DOUBLE_EQ(row1.get(0), 5.0);
    EXPECT_DOUBLE_EQ(row1.get(1), 6.0);
    EXPECT_DOUBLE_EQ(row1.get(2), 7.0);
    EXPECT_DOUBLE_EQ(row1.get(3), 8.0);

    EXPECT_EQ(row2.size(), 4);
    EXPECT_DOUBLE_EQ(row2.get(0), 9.0);
    EXPECT_DOUBLE_EQ(row2.get(1), 10.0);
    EXPECT_DOUBLE_EQ(row2.get(2), 11.0);
    EXPECT_DOUBLE_EQ(row2.get(3), 12.0);
}

TEST(types, set_row) {
    linalg::Matrix A(2, 3, {
        {0, 0, 0},
        {0, 0, 0}
    });
    linalg::Vector row(3, {1, 2, 3});

    A.set_row(1, row);

    EXPECT_DOUBLE_EQ(A.get(0, 0), 0.0);
    EXPECT_DOUBLE_EQ(A.get(0, 1), 0.0);
    EXPECT_DOUBLE_EQ(A.get(0, 2), 0.0);
    EXPECT_DOUBLE_EQ(A.get(1, 0), 1.0);
    EXPECT_DOUBLE_EQ(A.get(1, 1), 2.0);
    EXPECT_DOUBLE_EQ(A.get(1, 2), 3.0);

    // round-trip: set then get
    linalg::Vector got = A.get_row(1);
    EXPECT_EQ(got.size(), 3);
    EXPECT_DOUBLE_EQ(got.get(0), 1.0);
    EXPECT_DOUBLE_EQ(got.get(1), 2.0);
    EXPECT_DOUBLE_EQ(got.get(2), 3.0);
}