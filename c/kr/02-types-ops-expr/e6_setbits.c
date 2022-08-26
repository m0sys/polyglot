#include <stdio.h>

// Exercise 2.6: Write a function setbits(x, p, n, y) that returns x with the
// n bits that begin at position p set to the rightmost n bits of y, leaving
// the other bits unchanged.

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(int x, int p, int n, unsigned y);

int main()
{
    // 3 2 1 0
    // 1 0 0 1
    printf("setbits(9, 2, 2, 3) = %d\n", setbits(9, 2, 2, 3));
    // 3 2 1 0
    // 1 0 0 0
    printf("setbits(8, 2, 3, 7) = %d\n", setbits(8, 2, 3, 7));
    // 3 2 1 0
    // 0 0 0 1
    printf("setbits(1, 3, 3, 7) = %d\n", setbits(1, 3, 3, 7));
    // 3 2 1 0
    // 0 0 1 0
    printf("setbits(2, 3, 2, 3) = %d\n", setbits(2, 3, 2, 3));
}

unsigned setbits(int x, int p, int n, unsigned y)
{
    // 3 2 1 0
    // 0 0 1 1
    unsigned set_on = getbits(y, n - 1, n);
    set_on <<= (p + 1 - n);
    return x | set_on;
}

/* getbits:  get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    //
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
