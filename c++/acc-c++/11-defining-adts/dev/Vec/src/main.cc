#include "vec/vec.h"
#include <iostream>

int main()
{
    std::cout << "Hello, World!\n";
    Vec<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back((i + 1) * 10);

    std::cout << "\nIterate using for-range loop.\n";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << "\n";

    std::cout << "\nIterate using raw iterator loop.\n";
    for (auto it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cin.get();
}
