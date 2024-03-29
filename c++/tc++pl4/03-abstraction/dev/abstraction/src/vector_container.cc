#include "vector_container.h"

Vector_container::Vector_container(int s)
    : v(s)
{
}

Vector_container::Vector_container(std::initializer_list<double> il)
    : v(il)
{
}

double& Vector_container::operator[](int i) { return v[i]; }

int Vector_container::size() const { return v.size(); }
