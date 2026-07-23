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