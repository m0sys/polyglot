#include "vector.h"
#include <iostream>
#include <stdexcept>

template <typename T>
Vector<T>::Vector(int s)
{
    if (s < 0)
        throw std::length_error("Vector::Vector");
    elem = new double[s];
    sz = s;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> lst)
    : elem { new double[lst.size()] }
    , sz { (int)lst.size() }
{
    std::copy(lst.begin(), lst.end(), elem);
}

template <typename T>
Vector<T>::~Vector() { delete[] elem; }

// Copy constructor for Vector.
template <typename T>
Vector<T>::Vector(const Vector& a)
    : elem(new T[a.sz])
    , sz(a.sz)
{
    for (int i = 0; i < sz; i++)
        elem[i] = a.elem[i];
}

// Copy assignment for Vector.
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
    T* p = new T[a.sz];
    for (int i = 0; i < a.sz; i++)
        p[i] = a.elem[i];
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}

// Move constructor for Vector.
template <typename T>
Vector<T>::Vector(Vector<T>&& a)
    : elem(a.elem)
    , sz(a.sz)
{
    a.elem = nullptr;
    a.sz = 0;
}

// Move assignment for Vector.
// template <typename T>
// Vector<T>& Vector<T>::operator=(Vector<T>&& a)
// {
//     return nullptr;
// }

template <typename T>
T& Vector<T>::operator[](int i)
{
    if (i < 0 || size() <= i)
        throw std::out_of_range("Vector::operator[]");
    return elem[i];
}

template <typename T>
int Vector<T>::size() const { return sz; }

template <typename T>
void Vector<T>::print()
{
    for (int i = 0; i < sz; i++)
        std::cout << elem[i] << " ";

    std::cout << std::endl;
}

template class Vector<double>;
