#include "list_container.h"
#include <iostream>
#include <stdexcept>

List_container::List_container(std::initializer_list<double> il)
    : ld(il)
{
}

double& List_container::operator[](int i)
{
    for (auto& x : ld) {
        if (i == 0)
            return x;
        --i;
    }
    throw std::out_of_range("List container");
}

int List_container::size() const { return ld.size(); }
