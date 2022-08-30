// Exercise 2.1: Add a retrieve function to the counting example from Listing
// 2-6 to retrieve the current value of counter.

#include <stdio.h>
#include <stdlib.h>

int retrieve(unsigned int cnt);
void incr(void)
{
    static unsigned int cnt = 0;
    cnt++;
    printf("%d ", cnt);
    retrieve(cnt);
}

int retrieve(unsigned int cnt)
{
    static unsigned int rcnt = 0;
    unsigned old_rcnt = rcnt;
    rcnt = cnt;
    return old_rcnt;
}

int main(void)
{
    for (int i = 0; i < 5; i++)
        incr();

    printf("\nRetrieved: %d\n", retrieve(0));
    return EXIT_SUCCESS;
}
