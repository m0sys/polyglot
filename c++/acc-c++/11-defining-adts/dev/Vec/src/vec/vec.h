#pragma once
#include <cstddef>
#include <memory>
#include <utility>

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

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    void push_back(const T& val)
    {
        if (avail == limit)
            grow();

        unchecked_append(val);
    }

    iterator erase(const_iterator position);
    iterator erase(const_iterator first, const_iterator last);
    void clear();

private:
    // Allocate and init the underlying array.
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    // Destroy the elems in the array and free the memory.
    void uncreate();
    iterator uncreate(const_iterator pos);
    iterator uncreate(const_iterator first, const_iterator last);

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

template <typename T> typename Vec<T>::iterator Vec<T>::erase(const_iterator position) { return uncreate(position); }

template <typename T> typename Vec<T>::iterator Vec<T>::erase(const_iterator first, const_iterator last) { return uncreate(first, last); }

template <typename T> void Vec<T>::clear() { uncreate(); }

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

template <typename T> typename Vec<T>::iterator Vec<T>::uncreate(const_iterator pos)
{
    if (data) {
        iterator found;
        iterator cur = begin();

        while (cur != end() && cur != pos)
            cur++;
        found = cur;
        if (cur == avail)
            // NOTE: probably better to return an error code.
            throw std::domain_error("Position not found!\n");

        while (cur != avail - 1) {
            alloc.construct(cur, *(cur + 1));
            cur++;
        }
        avail--;
        return found++;

    } else {
        throw std::logic_error("Cannot erase element from empty Vec!\n");
    }
}

template <typename T> typename Vec<T>::iterator Vec<T>::uncreate(const_iterator first, const_iterator last)
{
    if (data) {
        iterator ffirst;
        iterator flast;
        iterator cur = begin();

        // Find first.
        while (cur != end() && cur != first)
            cur++;
        ffirst = cur;
        if (cur == avail)
            throw std::domain_error("First not found!\n");

        // Find last.
        while (cur != end() && cur != last)
            cur++;
        flast = cur;
        if (cur == avail)
            throw std::domain_error("Last not found!\n");

        // Destroy elems in range of [first, last).
        cur = ffirst;
        while (cur != flast)
            alloc.destroy(cur++);

        // Shift elements into sequence.
        cur = ffirst;
        iterator cur_end = flast;
        while (cur_end != avail) {
            alloc.construct(cur, *cur_end);
            cur++;
            cur_end++;
        }

        avail -= (last - first);
        return ffirst;

    } else {
        throw std::logic_error("Cannot erase elements from empty Vec!\n");
    }
}

template <typename T> void Vec<T>::grow()
{
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

// Precondition: avail points at allocated, but uninitialized space.
template <typename T> void Vec<T>::unchecked_append(const T& val) { alloc.construct(avail++, val); }
