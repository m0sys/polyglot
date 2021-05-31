#include <array>
#include <iostream>

int main()
{
    int example[5]; // created on the stack.
    for (int i = 0; i < 5; i++) {
        example[i] = 2;
    }

    int* another = new int[5]; // created on the heap.
    for (int i = 0; i < 5; i++) {
        another[i] = 2;
    }
    delete[] another;

    std::array<int, 5> another2;
    for (int i = 0; i < another2.size(); i++) {
        another2[i] = 2;
    }

    int* ptr = example;
    example[0] = 2;
    example[4] = 4;

    example[2] = 5;
    *(int*)((char*)ptr + 8) = 6;

    std::cout << example[0] << std::endl;
    std::cout << example[2] << std::endl;
    std::cout << example << std::endl;

    std::cin.get();
}
