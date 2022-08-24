#include <stdio.h>

// Exercise 1.8
int main()
{
    int cnt_nls = 0;
    int cnt_tabs = 0;
    int cnt_spaces = 0;
    for (int c; (c = getchar()) != EOF;)
        if (c == '\n')
            cnt_nls++;
        else if (c == '\t')
            cnt_tabs++;
        else if (c == ' ')
            cnt_spaces++;

    printf("nls: %d, tabs: %d, spaces, %d\n", cnt_nls, cnt_tabs, cnt_spaces);
}
