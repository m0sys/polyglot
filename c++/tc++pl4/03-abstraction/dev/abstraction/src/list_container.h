#pragma once
#include "container.h"
#include "iostream"
#include <list>

class List_container : public Container {
    std::list<double> ld;

public:
    List_container() { }
    List_container(std::initializer_list<double> il);

    double& operator[](int i);
    int size() const;
};
