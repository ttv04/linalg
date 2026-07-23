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

    SquareMatrix::SquareMatrix(size_t size)
        : Matrix(size, size) {}

    SquareMatrix::SquareMatrix(size_t size, std::initializer_list<std::initializer_list<double>> list)
        : Matrix(size, size, list) {}

    size_t SquareMatrix::size() const {
        return Matrix::c_size();
    }

    SquareMatrix Identity(size_t size) {
        SquareMatrix I(size);
        for (size_t i = 0; i < size; i++) I.set(i, i, 1);
        return I;
    }
}