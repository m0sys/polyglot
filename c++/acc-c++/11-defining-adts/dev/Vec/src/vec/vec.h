#pragma once
#include <cstddef>
#include <memory>

template <typename T> class Vec {
    // Class Invariants:
    //  - `data` points at initial data elem, if any, and is zero otherwise.
    //  - `data` <= `avail` <= `limit`.
    //  - Elements have been constructed in the range [data, avail).
    //  - Elements have not been constructed in the range [avail, limit).

public:
    using iterator = T*;
    using const_iterator = const iterator;
    using size_type = size_t;
    using value_type = T;

    Vec() { create(); }
    explicit Vec(size_type n, const T& val = T()) { create(n, val); }

    Vec(const Vec& v) { create(v.begin(), v.end()); } // copy constructor
    Vec& operator=(const Vec&);                       // copy assignment
    ~Vec() { uncreate(); }

    size_type size() const { return limit - data; }

    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return limit; }
    const_iterator end() const { return limit; }

    void push_back(const T& val)
    {
        if (avail == limit)
            grow();

        unchecked_append(val);
    }

private:
    // Allocate and init the underlying array.
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    // Destroy the elems in the array and free the memory.
    void uncreate();

    // Support functions for push_back.
    void grow();
    void unchecked_append(const T&);

private:
    iterator data;  // first elem in the Vec
    iterator avail; // pointer to (one past) the last constructed elem
    iterator limit; // pointer to (one past) the last available elem

    std::allocator<T> alloc; // object to handle mem allocation
};

template <typename T> Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    if (&rhs != this) {
        uncreate();

        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <typename T> void Vec<T>::create() { data = avail = limit = 0; }

template <typename T> void Vec<T>::create(size_type n, const T& val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <typename T> void Vec<T>::create(const_iterator i, const_iterator j)
{
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}

template <typename T> void Vec<T>::uncreate()
{
    if (data) {
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);
        alloc.deallocate(data, limit - data);
    }
    data = limit = avail = 0;
}

template <typename T> void Vec<T>::grow()
{
    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

// Precondition: avail points at allocated, but uninitialized space.
template <typename T> void Vec<T>::unchecked_append(const T& val) { alloc.construct(avail++, val); }
