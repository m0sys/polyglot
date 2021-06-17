#include "log.h"
#include <iostream>

struct Entity {
    int x, y;
};

int main()
{
    // This will read memory that is not ours.
    int a = 50;
    double value = *(double*)&a;
    LOG(value);

    // Converting struct into array.
    Entity e = { 5, 8 };
    int* pos = (int*)&e;
    LOG(pos[0] << ", " << pos[1]);

    int y = *(int*)((char*)&e + sizeof(int));
    LOG("y: " << y);

    std::cin.get();
}
