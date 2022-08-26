#include <stdio.h>

// Exercise 3.1: Our binary search makes two tests inside the loop, when one
// would suffice (at the price of more tests outside.) Write a version with
// only one test inside the loop and measure the difference in run-time.

int binsearch(int x, int v[], int n);
int fast_binsearch(int x, int v[], int n);

int main()
{
    //
    int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printf("slow: %d\n", binsearch(5, v, 10));
    printf("fast: %d\n", fast_binsearch(5, v, 10));
}

/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

int fast_binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (v[high] != x && low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid - 1;
    }

    if (v[high] != x)
        return -1; /* no match */
    return high;
}
