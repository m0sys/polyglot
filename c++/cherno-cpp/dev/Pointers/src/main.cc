#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void Incr(int& value) // this is `pass by reference`
{
    value++;
}

void Incr(int* value)
{
    (*value)++;
}

int main ()
{
    LOG("Hello, Pointers!");

    // NOTE: A pointer is just an integer that denotes the address in memory. It has nothing to do with types.
    void* ptr = 0; // zero means no-valid location in memory
    ptr = NULL; // #define NULL 0 - so NULL === 0
    ptr = nullptr; // same as 0 or NULL

    int var = 8;
    ptr = &var;
    LOG(ptr);

    // Variable on the heap.
    // char* buffer = new char[8]; // buffer is a pointer to the beginning of the 8 bytes of memory
    // memset(buffer, 0, 8); // fill memory starting at location `buffer` with 0 for the 8 bytes following the location
    // delete[] buffer;
    
    LOG("Hello, References!");

    // NOTE: Pointers and references are the same in the eye of the computer.
    int a = 5;
    int& ref = a; // alias for var a.
    ref = 2;
    LOG(a);

    Incr(a);
    LOG(a);

    Incr(&a);
    LOG(a);

    std::cin.get();
}

