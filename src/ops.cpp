#include "linalg/ops.hpp"
#include <iostream>

namespace linalg {

    Vector operator*(const Matrix& A, const Vector& b) {
        Vector c(A.r_size());
        for (size_t i = 0; i < A.r_size(); i++) {
            double sum = 0;
            for (size_t j = 0; j < A.c_size(); j++) {
                sum += A.get(i, j) * b.get(j);
            }
            c.set(i, sum);
        }
        return c;
    }

    Vector operator*(const Vector& b, const Matrix& A) {
        // Row-vector × matrix: result length = A cols
        Vector c(A.c_size());
        for (size_t j = 0; j < A.c_size(); j++) {
            double sum = 0;
            for (size_t i = 0; i < A.r_size(); i++) {
                sum += b.get(i) * A.get(i, j);
            }
            c.set(j, sum);
        }
        return c;
    }

    Matrix operator*(const Matrix& A, const Matrix& B) {
        Matrix C(A.r_size(), B.c_size());
        for (size_t i = 0; i < C.r_size(); i++) {
            for (size_t j = 0; j < C.c_size(); j++) {
                double sum = 0;
                for (size_t k = 0; k < A.c_size(); k++) {
                    sum += A.get(i, k) * B.get(k, j);
                }
                C.set(i, j, sum);
            }
        }
        return C;
    }

    Vector operator*(const double& scalar, const Vector& v) {
        Vector new_v(v.size());
        for (size_t i = 0; i < v.size(); i++) {
            new_v.set(i, scalar * v.get(i));
        }
        return new_v;
    }

    Vector operator*(const Vector& v, const double& scalar) {
        Vector new_v(v.size());
        for (size_t i = 0; i < v.size(); i++) {
            new_v.set(i, scalar * v.get(i));
        }
        return new_v;
    }

    Matrix operator*(const double& scalar, const Matrix& mat) {
        Matrix new_mat(mat.r_size(), mat.c_size());
        for (size_t i = 0; i < mat.r_size(); i++) {
            for (size_t j = 0; j < mat.c_size(); j++) {
                new_mat.set(i, j, scalar * mat.get(i, j));
            }
        }
        return new_mat;
    }

    Matrix operator*(const Matrix& mat, const double& scalar) {
        Matrix new_mat(mat.r_size(), mat.c_size());
        for (size_t i = 0; i < mat.r_size(); i++) {
            for (size_t j = 0; j < mat.c_size(); j++) {
                new_mat.set(i, j, scalar * mat.get(i, j));
            }
        }
        return new_mat;
    }

    Vector operator+(const Vector& a, const Vector& b) {
        Vector c(a.size());
        for (size_t i = 0; i < c.size(); i++) {
            c.set(i, a.get(i) + b.get(i));
        }
        return c;
    }

    Matrix operator+(const Matrix& A, const Matrix& B) {
        Matrix C(A.r_size(), A.c_size());
        for (size_t i = 0; i < C.r_size(); i++) {
            for (size_t j = 0; j < C.c_size(); j++) {
                C.set(i, j, A.get(i, j) + B.get(i, j));
            }
        }
        return C;
    }

    double dot(const Vector& a, const Vector& b) {
        if (a.size() != b.size()) {

        }
        double sum = 0;
        for (size_t i = 0; i < b.size(); i++) {
            sum += a.get(i) * b.get(i);
        }
        return sum;
    }

    Matrix transpose(const Matrix& A) {
        Matrix At(A.c_size(), A.r_size());
        for (size_t i = 0; i < A.r_size(); i++) {
            for (size_t j = 0; j < A.c_size(); j++) {
                At.set(j, i, A.get(i, j));
            }
        }
        return At;
    }
}
