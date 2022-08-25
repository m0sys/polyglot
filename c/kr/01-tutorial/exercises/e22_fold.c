#include <stdio.h>

#define MAX_LINE_LEN 18
#define CHECK_MARGIN 5

// Exercise 1.22: Write a program to ``fold'' long input lines into two or
//                more shorter lines after the last non-blank character that
//                occurs before the n-th column of input.'

int main()
{
    int c;
    int curr_len = 0;
    while ((c = getchar()) != EOF) {
        if (curr_len > (MAX_LINE_LEN - CHECK_MARGIN)) {
            if (c == ' ') {
                putchar('\n');
                curr_len = 0;
            } else
                putchar(c);

        } else {
            putchar(c);
            curr_len++;
        }
    }
}
