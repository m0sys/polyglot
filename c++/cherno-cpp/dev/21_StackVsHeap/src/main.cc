#include <iostream>
#include <string>

struct Vector3 {
    float x, y, z;

    Vector3()
        : x(10)
        , y(11)
        , z(12)
    {
    }
};

int main()
{
    // The stack memory allocates bytes for each value on top of each other
    // like a stack. NOTE: the stack is usually filled backwards. So "value"
    // will be in front of "array" - and "array" will be in front of "vect".
    int value = 5;
    int array[5];
    Vector3 vect;

    int* hvalue = new int;
    *hvalue = 5;
    int* harray = new int[5];
    Vector3* hvect = new Vector3();

    delete hvalue;
    delete[] harray;
    delete hvect;

    std::cin.get();
}
