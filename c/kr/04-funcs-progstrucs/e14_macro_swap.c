#include <stdio.h>

// Exercise 4.14: Define a macro swap(t,x,y) that interchanges two arguments of type t.
// (Block structure will help.)

// clang-format off
#define swap(t, x, y) {t tmp = x; x = y; y = tmp;}
// clang-format on

int main()
{
    int a = 10;
    int b = 20;
    swap(int, a, b);
    printf("a = %d, b = %d\n", a, b);
}
