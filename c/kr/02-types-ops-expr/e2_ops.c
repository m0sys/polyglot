#include <stdio.h>
#define MAX_LEN 1000

// Exercise 2.2:
// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//        s[i] = c;
//
// Write a loop equivalent to the for loop above without using && or ||.

int my_getline(char s[], int lim);
void put_line(char s[]);

int main()
{

    char line[MAX_LEN];
    int len = my_getline(line, MAX_LEN);

    printf("%d: ", len);
    put_line(line);
    printf("\n");
}

int my_getline(char s[], int lim)
{
    int c, i;
    int run_loop = 1;
    i = 0;
    while (run_loop) {
        if (i >= lim - 1)
            run_loop = 0;
        else if ((c = getchar()) == EOF)
            run_loop = 0;
        else if (c == '\n')
            run_loop = 0;

        else
            s[i] = c;
        i++;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void put_line(char s[])
{
    int i = 0;
    while (s[i] != '\0') {
        putchar(s[i]);
        i++;
    }
}
