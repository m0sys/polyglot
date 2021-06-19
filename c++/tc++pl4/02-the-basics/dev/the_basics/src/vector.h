#pragma once

class Vector {
public:
    Vector(int s);

    double& operator[](int i);
    int size();

private:
    double* elem;
    int sz;
};

double read_and_sum(int s);
