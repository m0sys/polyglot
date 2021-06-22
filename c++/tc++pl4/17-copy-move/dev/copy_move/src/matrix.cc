#include "matrix.h"
#include <memory>
#include <stdexcept>
#include <utility>

// 17.5.1. Copy

template <class T>
Matrix<T>::Matrix(const Matrix& m)
    : dim { m.dim }
    , elem { new T[m.size] }
{
    std::uninitialized_copy(m.elem, m.elem + m.size(), elem);
}

template <class T> Matrix<T>& Matrix<T>::operator=(const Matrix& m)
{
    if (dim[0] != m.dim[0] || dim[1] != m.dim[1])
        throw std::runtime_error("bad size in Matrix =");
    copy(m.elem, m.elem + m.size(), elem);
}

// 17.5.2. Move

template <class T>
Matrix<T>::Matrix(Matrix&& a)
    : dim { a.dim }
    , elem { a.elem } // grap a's representation
{
    // Clear a's representation.
    a.dim = { 0, 0 };
    a.elem = nullptr;
}

// NOTE: This is similar to Rust's transfer of Ownership in a sense.
//       Hence, further study of Rust can make me a better C++ programmer.
template <class T> Matrix<T>& Matrix<T>::operator=(Matrix&& a)
{
    // Swap the representations.
    using std::swap;
    swap(dim, a.dim);
    swap(elem, a.elem);
    return *this;
}
