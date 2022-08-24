#include <stdio.h>

// Exercise 1.9
int main()
{
    int c;
    int have_space = 0;

    // Copy input to output without any double spaces.
    while ((c = getchar()) != EOF) {
        if (c == ' ' && have_space)
            continue;
        else if (c == ' ' && !have_space) {
            have_space = 1;
            putchar(c);
        } else {
            have_space = 0;
            putchar(c);
        }
    }
}
