#include <stdio.h>
#define NTAB 3 // a tab is NTAB spaces

// Exercise 1.20: Write a program detab that replaces tabs in the input with
//                the proper number of blanks to space to the next tab stop.

int main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            for (int i = 0; i < NTAB; i++)
                putchar(' ');
        else
            putchar(c);
    }
}
