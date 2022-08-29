#include <stdio.h>
#define MAXLINE 1000

// Exercise 5.4: Write the function strend(s,t), which returns 1 if the string
// t occurs at the end of the string s, and zero otherwise.

int strend(char* s, char* t);

int main()
{
    char s1[MAXLINE] = "Hello, ";
    char s2[MAXLINE] = "World!";
    printf("strend? %d\n", strend(s1, s2));

    char s3[MAXLINE] = "Hello, World!";
    char s4[MAXLINE] = "World!";
    printf("strend? %d\n", strend(s3, s4));
}

int strend(char* s, char* t)
{
    char* tstart = t;
    while (*s++)
        ;

    while (*t++)
        ;

    // printf("*s = %c\n", *s);
    // printf("*t = %c\n", *t);

    while (*s-- == *t--)
        ;

    // printf("*s = %c\n", *s);
    // printf("*t = %c\n", *t);
    // printf("*(s+1) = %c\n", *(s + 1));
    // printf("*(t+1) = %c\n", *(t + 1));
    // printf("*(s+2) = %c\n", *(s + 2));
    // printf("*(t+2) = %c\n", *(t + 2));
    // printf("*tstart = %c\n", *tstart);

    if (*(t + 2) == *tstart && *(t + 2) == *(s + 2))
        return 1;
    return 0;
}
