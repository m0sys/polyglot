#include <array>

// 17.5.1. Copy
template <class T> class Matrix {
    std::array<int, 2> dim;
    T* elem;

public:
    Matrix(int d1, int d2)
        : dim { d1, d2 }
        , elem { new T[d1 * d2] }
    {
    }

    int size() const { return dim[0] * dim[1]; }
    Matrix(const Matrix&);            // copy constructor
    Matrix& operator=(const Matrix&); // copy assignment

    Matrix(Matrix&&);            // move constructor
    Matrix& operator=(Matrix&&); // move assignment

    ~Matrix() { delete[] elem; }
};
