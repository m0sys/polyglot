// Exercise 2.2: Declare an array of three pointers to functions and invoke
// the appropriate function based on an index value passed in as an argument.

#include <stdio.h>
#define NUM_FUNC_PTRS 3

static unsigned int cnt = 0;

int incr(void)
{
    cnt++;
    return cnt;
}

int decr(void)
{
    cnt--;
    return cnt;
}
int plus2(void)
{
    cnt += 2;
    return cnt;
}

int main(void)
{
    int (*arr_func_ptrs[NUM_FUNC_PTRS])(void);
    arr_func_ptrs[0] = incr;
    arr_func_ptrs[1] = decr;
    arr_func_ptrs[2] = plus2;

    for (int i = 0; i < NUM_FUNC_PTRS; i++)
        printf("%d: %d\n", i, arr_func_ptrs[i]());
}
