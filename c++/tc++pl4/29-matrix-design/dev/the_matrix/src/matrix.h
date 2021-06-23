#include <array>
#include <cstdio>
#include <initializer_list>
#include <vector>

#pragma once

// 29.4.3. Matrix Slices.

template <size_t N> struct Matrix_slice {
    Matrix_slice() = default;

    // Extents.
    Matrix_slice(size_t s, std::initializer_list<size_t> exts);

    // Extents and strides.
    Matrix_slice(size_t s, std::initializer_list<size_t> exts, std::initializer_list<size_t> strs);

    // N extents.
    template <typename... Dims> Matrix_slice(Dims... dims);

    // Calc index from a set of subscripts.
    template <typename... Dims, typename = Enable_if<All(Convertible<Dims, size_t>()...)>> size_t operator()(Dims... dims) const;

    size_t size;                   // total number of elements
    size_t start;                  // starting offset
    std::array<size_t, N> extents; // number of elements in each dimension
    std::array<size_t, N> strides; // offsets between elements in each dimension
};

// 29.4.3. Matrix_ref.

template <typename T, size_t N> class Matrix_ref {
public:
    Matrix_ref(const Matrix_slice<N>& s, T* p)
        : desc { s }
        , ptr { p }
    {
    }

    // ... mostly like Matrix ...

private:
    Matrix_slice<N> desc; // the shape of the matrix
    T* ptr;               // the first element in the matrix
};

// 29.4.4. Matrix List Initialization.

template <typename T, size_t N> using Matrix_initializer = typename Matrix_impl::Matrix_init<T, N>::type;

// General N-dimensional matrix.
template <typename T, size_t N> class Matrix {
public:
    static constexpr size_t order = N;
    using T::value_type;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    Matrix() = default;
    Matrix(Matrix&&) = default; // move
    Matrix& operator=(Matrix&&) = default;
    Matrix(Matrix const&) = default; // copy
    Matrix& operator=(Matrix const&) = default;
    ~Matrix() = default;

    // Constructor from Matrix_ref.
    template <typename U> Matrix(const Matrix_ref<U, N>&);
    // Assign from Matrix_ref
    template <typename U> Matrix& operator=(const Matrix_ref<U, N>&);

    template <typename... Exts> // specify the extents
    explicit Matrix(Exts... exts);

    // Init from lst.
    Matrix(Matrix_initializer<T, N>);
    // Assign from lst.
    Matrix& operator=(Matrix_initializer<T, N>);

    // Don't use {} except for elems.
    template <typename U> Matrix(std::initializer_list<U>) = delete;
    template <typename U> Matrix& operator=(std::initializer_list<U>) = delete;

    // Number of dimensions.
    static constexpr size_t get_order() { return N; }
    // #elems in the nth dimension.
    size_t extent(size_t n) const { return desc.extents[n]; }
    // Total number of elems.
    size_t size() const { return elems.size(); }
    // The slice defining subscripting.
    const Matrix_slice<N>& descriptor() const { return desc; }

    // "Flat" element access.
    T* data() { return elems.data(); }
    const T* data() const { return elems.data(); }

    // 29.2.2. Subscripting and Slicing.

    // Subscripting with integers. I.e. m(i, j, k)
    template <typename... Args> Enable_if<Matrix_impl::Requesting_element<Args...>(), T&> operator()(Args... args) const;

    template <typename... Args> Enable_if<Matrix_impl::Requesting_element<Args...>(), const T&> operator()(Args... args) const;

    // Subscripting with slices. I.e. m(s1, s2, s3)
    template <typename... Args> Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<T, N>> operator()(const Args&... args);

    template <typename... Args> Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<T, N>> operator()(const Args&... args) const;

    // Row access. I.e. m[i]
    Matrix_ref<T, N - 1> operator[](size_t i) { return row(i); }

    Matrix_ref<const T, N - 1> operator[](size_t i) const { return row(i); }

    // Column access.
    Matrix_ref<T, N - 1> col(size_t n);
    Matrix_ref<const T, N - 1> col(size_t n) const;

    // 29.3. Matrix Arithmetic Operations.

    // Apply 'f' for every element x.
    template <typename F> Matrix& apply(F f);

    // Apply 'f' for corresponding elements f(x, mx).
    template <typename M, typename F> Matrix& apply(const M& m, F f);

    // Assignment with scalar.
    Matrix& operator=(const T& value);

    // Matrix scalar ops.
    Matrix& operator+=(const T& value);
    Matrix& operator-=(const T& value);
    Matrix& operator*=(const T& value);
    Matrix& operator/=(const T& value);
    Matrix& operator%=(const T& value);

    // Matrix addition.
    template <typename M> Matrix& operator+=(const M& x);

    // Matrix subtraction.
    template <typename M> Matrix& operator-=(const M& x);

private:
    Matrix_slice<N> desc;
    std::vector<T> elems;
};
