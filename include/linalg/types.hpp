#pragma once
#include <initializer_list>
#include <vector>
#include <cstddef>

namespace linalg {
    class Matrix;
    class Vector;
    class SquareMatrix;

    SquareMatrix Identity(size_t);

    class Vector {
    private:
        size_t m;
        std::vector<double> data;
    public:
        
        Vector(size_t);
        Vector(size_t, std::initializer_list<double>);
        size_t size() const;
        double get(size_t) const;
        void set(size_t, double);  
    };

    class Matrix {
    private:
        size_t m, n;
        std::vector<std::vector<double>> data;
    public:
        Matrix(size_t, size_t);
        Matrix(size_t, size_t, std::initializer_list<std::initializer_list<double>>);
        size_t r_size() const;
        size_t c_size() const;
        double get(size_t, size_t) const;
        Vector get_row(size_t) const;
        void set(size_t, size_t, double);
        void set_row(size_t, const Vector&);
    };

    class SquareMatrix: public Matrix {
    private:

    public:
        using Matrix::Matrix;
        SquareMatrix(size_t);
        SquareMatrix(size_t, std::initializer_list<std::initializer_list<double>>);
        size_t size() const;
        

        // Deleted
        size_t r_size() = delete;
        size_t c_size() = delete;
        SquareMatrix(size_t, size_t) = delete;
        SquareMatrix(size_t, size_t, std::initializer_list<std::initializer_list<double>>) = delete;
    };

}