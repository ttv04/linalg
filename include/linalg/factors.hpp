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
        Matrix L();
        Matrix U();
    };
}