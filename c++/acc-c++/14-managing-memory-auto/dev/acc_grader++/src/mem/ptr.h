#pragma once

// Basically shared_pointers while allowing cloning.

#include <cstddef>
#include <stdexcept>

template <typename T> class Ptr {
public:
    Ptr()
        : refptr(new size_t(1))
        , p(nullptr)
    {
    }

    Ptr(T* t)
        : refptr(new size_t(1))
        , p(t)
    {
    }

    Ptr(const Ptr& h)
        : refptr(h.refptr)
        , p(h.p)
    {
        ++*refptr;
    }

    Ptr& operator=(const Ptr&);
    ~Ptr();

    void make_unique();

    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;

private:
    T* p;
    size_t* refptr;
};

template <typename T> T& Ptr<T>::operator*() const
{
    if (p)
        return *p;
    throw std::runtime_error("unbound Handle");
}

template <typename T> T* Ptr<T>::operator->() const
{
    if (p)
        return p;
    throw std::runtime_error("unbound Handle");
}

template <typename T> Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
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

template <typename T> Ptr<T>::~Ptr()
{

    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}

template <typename T> void Ptr<T>::make_unique()
{
    if (*refptr != 1) {
        --*refptr;
        refptr = new size_t(1);
        p = p ? p->clone() : 0;
    }
}
