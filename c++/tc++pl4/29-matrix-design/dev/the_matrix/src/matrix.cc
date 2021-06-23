#include "matrix.h"
#include <initializer_list>
#include <numeric>
#include <utility>

/*
 * Well Bjarne - you just made me realize that I don't know much about C++ - yet. :D
 *
 * I think I finally understand what it is that you mean by "C++ is a general purpose
 * programming language for serious programmers."
 */

template <typename T, size_t N>
template <typename... Exts>
Matrix<T, N>::Matrix(Exts... exts)
    : desc(exts...)
    , elems(desc.size)
{
}

template <typename T, size_t N> Matrix<T, N>::Matrix(Matrix_initializer<T, N> init)
{
    Matrix_impl::derive_extents(init, desc.extents);
    elems.reserve(desc.size);
    Matrix_impl::insert_flat(init, elems);
    assert(elems.size() == desc.size);
}

template <typename T, size_t N>
template <typename U>
Matrix<T, N>::Matrix(const Matrix_ref<U, N>& x)
    : desc { x.desc }
    , elems { x.begin(), x.end() }
{
    static_assert(Convertible<U, T>(), "Matrix constructor: incompatible element types");
}

template <typename T, size_t N> template <typename U> Matrix<T, N>& Matrix<T, N>::operator=(const Matrix_ref<U, N>& x)
{
    static_assert(Convertible<U, T>(), "Matrix =: incompatible element types");

    desc = x.desc;
    elems.assign(x.begin(), x.end());
    return *this;
}

// 29.2.2. Subscripting and Slicing.

template <typename T, size_t N> Matrix_ref<T, N - 1> Matrix<T, N>::operator[](size_t n) { return row(n); }

// 29.3.1. Scalar Operations.

template <typename T, size_t N> Matrix<T, N>& Matrix<T, N>::operator+=(const T& val)
{
    return apply([&](T& a) { a += val; });
}

template <typename T, size_t N> template <typename F> Matrix<T, N>& Matrix<T, N>::apply(F f)
{
    for (auto& x : elems) // this loop uses stride iterators
        f(x);
    return *this;
}

template <typename T, size_t N> Matrix<T, N> operator+(const Matrix<T, N>& m, const T& val)
{
    Matrix<T, N> res = m;
    res += val;
    return res;
}

// 29.3.2. Addition.

template <typename T, size_t N> template <typename M> Enable_if<Matrix_type<M>(), Matrix<T, N>&> Matrix<T, N>::operator+=(const M& m)
{
    static_assert(m.order() == N, "+=: mismatched Matrix dimensions");
    assert(same_extents(desc, m.descriptor()));
    return apply(m, [](T& a, Value_type<M>& b) { a += b; });
}

template <typename T, size_t N> template <typename M, typename F> Enable_if<Matrix_type<M>(), Matrix<T, N>&> Matrix<T, N>::apply(M& m, F f)
{
    assert(same_extents(desc, m.descriptor()));
    for (auto i = begin(), j = m.begin(); i != end(); ++i, ++j)
        f(*i, *j);
    return *this;
}

template <typename T, size_t N> Matrix<T, N> operator+(const Matrix<T, N>& a, const Matrix<T, N>& b)
{
    Matrix<T, N> res = a;
    res += b;
    return res;
}

// TODO: figure out what 'Common_type' is.
template <typename T, typename T2, size_t N, typename RT = Matrix<Common_type<Value_type<T>, Value_type<T2>>, N> Matrix<RT, N> operator+(const Matrix<T, N> a, const Matrix<T2, N>& b)
{
    Matrix<RT, N> res = a;
    res += b;
    return res;
}

template <typename T, size_t N> Matrix<T, N> operator+(const Matrix_ref<T, N>& x, const T& n)
{
    Matrix<T, N> res = x;
    res += n;
    return res;
}

/*
 * Matrix multiplication.
 *
 * NOTE: these following methods only handles one and two dimensions. For generalization see [Kolecki, 2002]
 *       on tensors.
 */
template <typename T> Matrix<T, 2> operator*(const Matrix<T, 1>& u, const Matrix<T, 1>& v)
{
    const size_t n = u.extent(0);
    const size_t m = v.extent(0);

    Matrix<T, 2> res(n, m);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            res(i, j) = u[i] * v[j];

    return res;
}

template <typename T> Matrix<T, 1> operator*(const Matrix<T, 2>& m, const Matrix<T, 1>& v)
{
    assert(m.extent(1) == v.extent(0));

    const size_t n = m.extent(0);
    Matrix<T, 1> res(n);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            res(i) += m(i, j) * v(j);
    return res;
}

template <typename T> Matrix<T, 2> operator*(const Matrix<T, 2>& m1, const Matrix<T, 2>& m2)
{
    const size_t n = m1.extent(0);
    const size_t m = m1.extent(1);
    assert(m == m2.extent(0)); // cols must match rows

    const size_t p = m2.extent(1);
    Matrix<T, 2> res(n, p);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            // NOTE: you can replace this following loop with a dot-product op.
            for (size_t k = 0; k < p; k++)
                res(i, j) = m1(i, k) * m2(k, j);
    return res;
}

// 29.4.2. Matrix Slices.

template <size_t N> template <typename... Dims> size_t Matrix_slice<N>::operator()(Dims... dims) const
{
    static_assert(sizeof...(Dims) == N, "");
    size_t args[N] { size_t(dims)... };
    return std::inner_product(args, args + N, strides.begin(), size_t(0));
}
