#include <iostream>
#include "log.h"

int main()
{
    int a = 8;
    a++;
    const char* str = "Hello";
    
    for (int i = 0; i < 5; i++) 
    {
        const char chr = str[i];
        std::cout << chr << std::endl;
    }

    // Branching.
    int x = 6;
    if (x == 5) 
        Log("Hello World!");

    const char* ptr = nullptr;
    if (ptr)
        Log(ptr);
    else
        Log("Ptr is null!");

    // NOTE: else if (condition) {} === else { if (condition) {} }

    std::cin.get();
}
