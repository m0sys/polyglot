/*
 * Fix the remaining bug in the absolute_value function in Listing 5-14.
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int absolute_value(int a)
{
    if (a == INT_MIN) {
        printf("\nabsolute_value: cannot represent abs(%d) in 2c representation!\n", a);
        abort();
    }

    if (a < 0) {
        return -a;
    }
    return a;
}

int main()
{
    printf("-20: %d\n", absolute_value(-20));
    printf("INT_MIN: %d\n", absolute_value(INT_MIN));
    // printf("-INT_MIN: %d\n", -INT_MIN);
}
