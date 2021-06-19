#include "container.h"
#include "list_container.h"
#include "log.h"
#include "vector.h"
#include "vector_container.h"
#include <iostream>

void display(Container& c)
{
    const int sz = c.size();
    for (int i = 0; i < sz; i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;
}

int main()
{
    LOG("Hello, World!");
    Vector<double> v1 = { 1, 2, 3, 4, 5 };
    v1.print();

    Vector<double> v2 = { 1.23, 3.45, 6.7, 8 };
    v2.print();

    // Container time.
    Vector_container vc = { 2, 4, 8, 16, 32, 64 };
    List_container lc = { 1, 2, 3, 4, 5, 6 };

    // Polymorphism bruh!
    display(vc);
    display(lc);
    std::cin.get();
}
