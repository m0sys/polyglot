#pragma once

// Basically shared_pointers.

#include <cstddef>
#include <stdexcept>

template <typename T> class Ref_handle {
public:
    Ref_handle()
        : refptr(new size_t(1))
        , p(nullptr)
    {
    }

    Ref_handle(T* t)
        : refptr(new size_t(1))
        , p(t)
    {
    }

    Ref_handle(const Ref_handle& h)
        : refptr(h.refptr)
        , p(h.p)
    {
        ++*refptr;
    }

    Ref_handle& operator=(const Ref_handle&);
    ~Ref_handle();

    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;

private:
    T* p;
    size_t* refptr;
};

template <typename T> T& Ref_handle<T>::operator*() const
{
    if (p)
        return *p;
    throw std::runtime_error("unbound Handle");
}

template <typename T> T* Ref_handle<T>::operator->() const
{
    if (p)
        return p;
    throw std::runtime_error("unbound Handle");
}

template <typename T> Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs)
{
    ++*rhs.refptr;

    // Free the lhs, destroying pointers if appropriate.
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }

    // Copy vals from rhs.
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}

template <typename T> Ref_handle<T>::~Ref_handle()
{

    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}
