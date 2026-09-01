#pragma once
#include "types.hpp"

namespace linalg {
    class LU {
    private:
        SquareMatrix l;
        SquareMatrix u;
        void factor();
    public:
        LU(const SquareMatrix&);
        const SquareMatrix& L() const;
        const SquareMatrix& U() const;
    };
}