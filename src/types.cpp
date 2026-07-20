#include <initializer_list>
#include <vector>
#include <cstddef>
#include "linalg/types.hpp"

namespace linalg 
{

    Vector::Vector(size_t size) {
        m = size;
        data = std::vector<double>(m, 0);
    }

    Vector::Vector(size_t size, std::initializer_list<double> list) {
        m = size;
        data.assign(list);
    }

    size_t Vector::size() const {
        return m;
    }

    double Vector::get(size_t i) const {
        return data[i];
    }

    void Vector::set(size_t i, double val) {
        data[i] = val;
    }

    Matrix::Matrix(size_t r_size, size_t c_size) {
        m = r_size;
        n = c_size;
        data = std::vector<std::vector<double>>(m, std::vector<double>(n));
    }

    Matrix::Matrix(size_t r_size, size_t c_size, std::initializer_list<std::initializer_list<double>> list) 
        : m(r_size), n(c_size), data(r_size) {
        size_t i = 0;
        for (const auto& row : list) {
            if (i >= m) break;
            data[i].assign(row);
            i++;
        }
    }

    size_t Matrix::r_size() const {
        return m;
    }

    size_t Matrix::c_size() const {
        return n;
    }

    double Matrix::get(size_t i, size_t j) const {
        return data[i][j];
    }

    void Matrix::set(size_t i, size_t j, double val) {
        data[i][j] = val;
    }

    // Strictly Matrix times Vector, not the other way around
    Vector operator*(const Matrix& A, const Vector& b) {
        if (A.c_size() != b.size()) return Vector(0);
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

    Matrix operator*(const Matrix& A, const Matrix& B) {
        if (A.c_size() != B.r_size()) return Matrix(0, 0);
        Matrix C(A.c_size(), B.r_size());
        for (size_t i = 0; i < C.r_size(); i++) {
            for (size_t j = 0; j < C.c_size(); j++) {
                double sum = 0;
                for (size_t k = 0; k < A.r_size(); k++) {
                    sum += A.get(i, j) * B.get(j, k);
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

}