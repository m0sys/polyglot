#include <ctype.h>
#include <stdio.h>

// Exercise 5.1: As written, getint treats a + or - not followed by a digit
// as a valid representation of zero. Fix it to push such a character back on the input.

#define SIZE 1000

int getint(int* pn);

int main()
{
    int n;
    int arr[SIZE];
    for (n = 0; n < SIZE && getint(&arr[n]) != EOF; n++)
        ;

    for (int i = 0; i < n; i++)
        printf("%d: %d\n", i, arr[i]);
}

int getch(void);
void ungetch(int);

/* getint:  get next integer from input into *pn */
int getint(int* pn)
{
    int c, sign;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int tmp = c;
        c = getch();
        if (!isdigit(c)) { /* it is not a number */
            ungetch(c);
            ungetch(tmp);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

/* get a (possibly pushed-back) character */
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
