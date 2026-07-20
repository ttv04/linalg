#include <initializer_list>
#include <vector>
#include <cstddef>

namespace linalg {
    class Matrix;
    class Vector;

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
        void set(size_t, size_t, double);
    };

    Vector operator*(const Matrix& A, const Vector& b);
    Matrix operator*(const Matrix& A, const Matrix& B);
    Vector operator*(const double& scalar, const Vector& v);
    Vector operator*(const Vector& v, const double& scalar);
    Matrix operator*(const double& scalar, const Matrix& mat);
    Matrix operator*(const Matrix& mat, const double& scalar);
    Vector operator+(const Vector& a, const Vector& b);
    Matrix operator+(const Matrix& A, const Matrix& B);

}