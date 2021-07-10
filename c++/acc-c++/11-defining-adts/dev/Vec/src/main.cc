#include "vec/vec.h"
#include <iostream>
#include <stdexcept>

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

    vec.erase(vec.begin() + 5);
    std::cout << "\nIterate using for-range loop after erase.\n";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << "\n";

    try {
        vec.erase(vec.begin() + 10);
    } catch (std::domain_error& e) {
        std::cout << e.what();
    }

    Vec<int> vec2;
    try {
        vec2.erase(vec2.begin());
    } catch (std::logic_error& e) {
        std::cout << e.what();
    }

    vec.erase(vec.begin() + 2, vec.begin() + 4);
    std::cout << "\nIterate using for-range loop after ranged erase.\n";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << "\n";

    vec.clear();
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << "\n";
    std::cout << "All Clear!"
              << "\n";

    std::cin.get();
}
