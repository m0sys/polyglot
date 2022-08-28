#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itoa(int n, char s[]);
void rec_itoa2(int n, char s[], int digits);
void rec_itoa(int n, char s[]);

// Exercise 4.12: Adapt the ideas of printd to write a recursive version of itoa;
// that is, convert an integer into a string by calling a recursive routine.

int main(void)
{
    char line[MAXLINE];
    itoa(100, line);
    printf("100: %s\n", line);

    rec_itoa2(100, line, 3);
    printf("100: %s\n", line);

    rec_itoa2(2045, line, 4);
    printf("2045: %s\n", line);

    rec_itoa(2045, line);
    printf("2045: %s\n", line);
}

void rec_itoa2(int n, char s[], int digits)
{
    if (n < 0) {
        s[0] = '-';
        n = -n;
        digits++;
    }

    // Recursive case.
    if (n / 10)
        rec_itoa2(n / 10, s, digits - 1);

    // Base case.
    s[digits - 1] = n % 10 + '0';
    s[digits] = '\0';
}

void rec_itoa(int n, char s[])
{
    static int i = 0;

    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }

    if (n / 10)
        rec_itoa(n / 10, s);

    s[i++] = n % 10 + '0';
    s[i] = '\0';
}

/* printd:  print n in decimal */
void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

/* reverse:  reverse string s in place */
void rreverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */
    i = 0;
    do {                       /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /*getnextdigit*/
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    rreverse(s);
}
