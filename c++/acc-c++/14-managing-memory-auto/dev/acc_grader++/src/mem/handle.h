#pragma once
// Basically unique_pointers.

#include <stdexcept>

template <typename T> class Handle {
public:
    Handle()
        : p(nullptr)
    {
    }

    Handle(const Handle& s)
        : p(nullptr)
    {
        if (s.p)
            p = s.p->clone();
    }

    Handle& operator=(const Handle&);
    ~Handle() { delete p; }

    Handle(T* t)
        : p(t)
    {
    }

    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;

private:
    T* p;
};

template <typename T> Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
    if (&rhs != this) {
        delete p;
        p = rhs.p ? rhs.p->clone() : nullptr;
    }
    return *this;
}

template <typename T> T& Handle<T>::operator*() const
{
    if (p)
        return *p;
    throw std::runtime_error("unbound Handle");
}

template <typename T> T* Handle<T>::operator->() const
{
    if (p)
        return p;
    throw std::runtime_error("unbound Handle");
}
