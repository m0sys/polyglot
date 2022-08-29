#include <stdio.h>
#define MAXLINE 1000

// Exercise 5.5: Write versions of the library functions strncpy, strncat, and
// strncmp, which operate on at most the first n characters of their argument
// strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
// Full descriptions are in Appendix B.

int strlen0(char* s);
void strncpy0(char* s, char* t, int n);
void strncat0(char* s, char* t, int n);
int strncmp0(char* s, char* t, int n);

int main()
{
    char s1[MAXLINE] = "Hello, ";
    char s2[MAXLINE] = "World!";
    printf("len of s1: %d\n", strlen0(s1));
    printf("len of s2: %d\n", strlen0(s2));

    // Testing strncpy.
    printf("\n\nTesting strncpy!\n");
    char s0[MAXLINE];

    strncpy0(s0, s1, 2);
    printf("s0: %s\n", s0);
    printf("len of s0: %d\n", strlen0(s0));

    strncpy0(s0, s1, strlen0(s1) + 1);
    printf("s0: %s\n", s0);
    printf("len of s0: %d\n", strlen0(s0));

    strncpy0(s0, s1, 20);
    printf("s0: %s\n", s0);
    printf("len of s0: %d\n", strlen0(s0));

    // Testing strncat.
    printf("\n\nTesting strncat!\n");
    strncat0(s0, s2, strlen0(s2));
    printf("s0: %s\n", s0);
    printf("len of s0: %d\n", strlen0(s0));

    strncat0(s0, s1, 2);
    printf("s0: %s\n", s0);
    printf("len of s0: %d\n", strlen0(s0));

    // Testing strncmp.
    printf("\n\nTesting strncmp!\n");
    char s3[MAXLINE] = "Hello, World!";
    strncpy0(s0, s1, strlen0(s1) + 1);
    // printf("s0: %s\n", s0);
    strncat0(s0, s2, strlen0(s2));
    // printf("s0: %s\n", s0);
    printf("Is hello? %d\n", strncmp0(s0, s3, strlen0(s3)));
}

int strlen0(char* s)
{
    char* start = s;
    while (*s++)
        ;
    s--;

    return s - start;
}

/* strcmp:  return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp0(char* s, char* t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int strncmp0(char* s, char* t, int n)
{
    for (; n-- > 0 && *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

/* strcpy:  copy t to s; pointer version 3 */
void strcpy0(char* s, char* t)
{
    while ((*s++ = *t++))
        ;
}

void strncpy0(char* s, char* t, int n)
{
    while (n-- > 0 && (*s++ = *t++))
        ;

    while (n-- > 0)
        *s++ = '\0';
}

void strcat0(char* s, char* t)
{
    // Find end of 's'.
    while (*s++)
        ;
    s--;

    while ((*s++ = *t++))
        ;
}

void strncat0(char* s, char* t, int n)
{
    // Find end of 's'.
    while (*s++)
        ;
    s--;

    while (n-- > 0 && (*s++ = *t++))
        ;
    *s = '\0';
}
