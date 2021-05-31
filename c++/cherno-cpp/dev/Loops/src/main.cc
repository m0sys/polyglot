#include <iostream>

int main () 
{

    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            continue;
        }
        std::cout << "Hello, World!" << std::endl;
    }
    int i = 0;
    while (i < 5) {
        //std::cout << "Hello, World!" << std::endl;
        i++;
    }

    i = 5;
    do 
    {
        // std::cout << "Hello, World!" << std::endl;
    } while (i < 5);

    std::cin.get();
}
