#include <stdio.h>
#define NTAB 3 // a tab is NTAB spaces
#define IN 1
#define OUT 0

// Exercise 1.21: Write a program entab that replaces strings of blanks by the
//                minimum number of tabs and blanks to achieve the same spacing.

int main()
{
    int c;
    int state = OUT;
    int cnt_spaces = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            state = IN;
            cnt_spaces++;
        } else if (state == IN && cnt_spaces == NTAB) {
            putchar('\t');
            putchar(c);
            state = OUT;
            cnt_spaces = 0;
        } else if (state == IN) {
            for (int i = 0; i < cnt_spaces; i++)
                putchar(' ');
            cnt_spaces = 0;
            state = OUT;
            putchar(c);
        }

        else
            putchar(c);
    }
}
