#pragma once
#include <iostream>

template <typename T> class Vector {
public:
    Vector(int s);
    Vector(std::initializer_list<T> lst);
    ~Vector();
    Vector(const Vector& a);            // copy constructor
    Vector& operator=(const Vector& a); // copy assignment
    Vector(Vector&& a);                 // move constructor
    Vector& operator=(Vector&& a);      // move assignment

    T& operator[](int i);
    const T& operator[](int i) const;

    int size() const;
    void print();

private:
    T* elem;
    int sz;
};

double read_and_sum(int s);
