#include <stdio.h>

int main()
{
    int c;

    // Copy input one word per line.
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
            putchar('\n');
        else
            putchar(c);
    }
}
