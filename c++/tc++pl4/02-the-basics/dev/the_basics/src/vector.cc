#include "vector.h"
#include <iostream>
#include <stdexcept>

Vector::Vector(int s)
{
    if (s < 0)
        throw std::length_error("Vector::Vector");
    elem = new double[s];
    sz = s;
}

double& Vector::operator[](int i)
{
    if (i < 0 || size() <= i)
        throw std::out_of_range("Vector::operator[]");
    return elem[i];
}

int Vector::size() { return sz; }

// NOTE: violates SRP.
double read_and_sum(int s)
{
    Vector v(s);
    for (int i = 0; i < v.size(); i++)
        std::cin >> v[i];

    double sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += v[i];
    return sum;
}
