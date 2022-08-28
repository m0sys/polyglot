#include <ctype.h>
#include <stdio.h>

// Exercise 5.2: Write getfloat, the floating-point analog of getint.
// What type does getfloat return as its function value?

#define SIZE 1000

int getfloat(float* pn);

int main()
{
    int n;
    float arr[SIZE];
    for (n = 0; n < SIZE && getfloat(&arr[n]) != EOF; n++)
        ;

    for (int i = 0; i < n; i++)
        printf("%d: %.2f\n", i, arr[i]);
}

int getch(void);
void ungetch(int);

/* getfloat:  get next float from input into *pn */
int getfloat(float* pn)
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

    // Calc floating point part.
    float power = 1.0;
    if (c == '.')
        c = getch();
    for (; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
        power *= 10;
    }

    *pn /= power;
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
