#pragma once
#include "container.h"
#include "vector.h"
#include <iostream>

class Vector_container : public Container {
    Vector<double> v;

public:
    Vector_container(int s);
    Vector_container(std::initializer_list<double> il);

    // NOTE: will implcitly call ~Vector.
    ~Vector_container() { }
    double& operator[](int i);
    int size() const;
};
