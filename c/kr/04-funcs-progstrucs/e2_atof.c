#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

double my_atof(char s[]);
int my_getline(char line[], int lim);

// Exercise 4.2:  Extend atof to handle scientific notation of the form 123.45e-6
// where a floating-point number may be followed by e or E and an optionally signed exponent.

int main(void)
{
    char line[MAXLINE];
    double sum = 0;
    while (my_getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += my_atof(line));

    return EXIT_SUCCESS;
}

/* atof:  convert string s to double */
double my_atof(char s[])
{
    double val, power, expon;
    int i, sign, expsign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e')
        i++;

    expsign = (s[i] == '-') ? 1 : 0;
    if (s[i] == '-')
        i++;

    for (expon = 0.0; isdigit(s[i]); i++)
        expon = 10.0 * expon + (s[i] - '0');

    printf("expon = %g; expsign = %d\n", expon, expsign);

    if (expsign)
        for (int e = 0; e < expon; e++)
            power *= 10;
    else
        for (int e = 0; e < expon; e++)
            val *= 10;

    return sign * val / power;
}

int my_getline(char line[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';

    return i;
}
