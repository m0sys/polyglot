#include <stdio.h>

#define LEN (1 << 7)

int main()
{
    int c;

    // Init bins arr.
    int bins[LEN];
    for (int i = 0; i < LEN; i++)
        bins[i] = 0;

    while ((c = getchar()) != EOF) {
        bins[c]++;
    }

    // Print histogram.
    printf("Char Histogram\n\n");
    for (int i = 0; i < LEN; i++) {
        printf("%c: ", i);
        for (int j = 0; j < bins[i]; j++)
            putchar('#');
        putchar('\n');
    }
}
