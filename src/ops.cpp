#include "linalg/ops.hpp"
#include <stdexcept>
#include <string>

namespace linalg {

namespace {

std::string size_mismatch(const std::string& op, const std::string& lhs,
                          size_t lhs_n, const std::string& rhs, size_t rhs_n) {
    return op + ": " + lhs + " (" + std::to_string(lhs_n) + ") != " + rhs +
           " (" + std::to_string(rhs_n) + ")";
}

}  // namespace

Vector operator*(const Matrix& A, const Vector& b) {
    if (A.c_size() != b.size()) {
        throw std::invalid_argument(size_mismatch(
            "matrix-vector multiply", "A cols", A.c_size(), "b size", b.size()));
    }
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
    // Row-vector × matrix: b length must equal A rows
    if (b.size() != A.r_size()) {
        throw std::invalid_argument(size_mismatch(
            "vector-matrix multiply", "b size", b.size(), "A rows", A.r_size()));
    }
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
    if (A.c_size() != B.r_size()) {
        throw std::invalid_argument(size_mismatch(
            "matrix-matrix multiply", "A cols", A.c_size(), "B rows", B.r_size()));
    }
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
    if (a.size() != b.size()) {
        throw std::invalid_argument(size_mismatch(
            "vector add", "a size", a.size(), "b size", b.size()));
    }
    Vector c(a.size());
    for (size_t i = 0; i < c.size(); i++) {
        c.set(i, a.get(i) + b.get(i));
    }
    return c;
}

Matrix operator+(const Matrix& A, const Matrix& B) {
    if (A.r_size() != B.r_size() || A.c_size() != B.c_size()) {
        throw std::invalid_argument(
            "matrix add: A is " + std::to_string(A.r_size()) + "x" +
            std::to_string(A.c_size()) + ", B is " + std::to_string(B.r_size()) +
            "x" + std::to_string(B.c_size()));
    }
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
        throw std::invalid_argument(size_mismatch(
            "dot product", "a size", a.size(), "b size", b.size()));
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

}  // namespace linalg
