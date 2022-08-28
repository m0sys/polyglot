#include <stdio.h>
#include <string.h>

// Exercise 4.13: Write a recursive version of the function reverse(s),
// which reverses the string s in place.

void rreverse(char s[]);
void rec_reverse(char s[], int i, int j);

int main()
{
    char str[] = "Hello, world!";
    rreverse(str);
    printf("Reverse 'Hello, World!': %s\n", str);
}

void rreverse(char s[]) { rec_reverse(s, 0, strlen(s) - 1); }

/* rec_reverse:  reverse string s in place */
void rec_reverse(char s[], int i, int j)
{
    // Base case.
    if (i >= j)
        return;

    int tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    rec_reverse(s, ++i, --j);
}
