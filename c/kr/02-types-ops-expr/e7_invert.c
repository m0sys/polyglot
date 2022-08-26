#include <stdio.h>

// Exercise 2.7: Write a function invert(x,p,n) that returns x with the n
// bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
// leaving the others unchanged.

unsigned invert(unsigned x, int p, int n);
unsigned getbits(unsigned x, int p, int n);

int main()
{
    // 3 2 1 0
    // 1 0 0 0
    printf("invert(8, 2, 3) = %d\n", invert(8, 2, 3));
    // 3 2 1 0
    // 1 0 1 1
    printf("invert(11, 1, 2) = %d\n", invert(11, 1, 2));
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned set_on = getbits(x, p, n);
    set_on = ~set_on;
    return x | ~getbits(x, p, n);
}

/* getbits:  get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    //
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
