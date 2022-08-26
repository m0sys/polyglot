#include <stdio.h>

// Exercise 1.9
int main()
{
    int c;

    // Copy input to output without with visiable tab, backspace, and slash.
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            fputs("\\t", stdout);
        } else if (c == '\b') {
            fputs("\\b", stdout);
        } else if (c == '\\') {
            fputs("\\", stdout);

        } else {
            putchar(c);
        }
    }
}
