#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Exercise 5.13: Write the program tail, which prints the last n lines of its input.
// By default, n is set to 10, let us say, but it can be changed by an optional
// argument so that
//   tail -n
// prints the last n lines. The program should behave rationally no matter
// how unreasonable the input or the value of n. Write the program so it makes the best use of available storage;
// lines should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed size.

#define MAXLINES 5000
char* lineptrs[MAXLINES];
int readlines(char* lineptr[], int maxlines);

int main(int argc, char* argv[])
{
    printf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++)
        printf("%d: %s\n", i, argv[i]);

    int tailcnt = 10;
    if (argc > 2 && strcmp(argv[1], "-n") == 0)
        tailcnt = atoi(argv[2]);

    int nlines = readlines(lineptrs, MAXLINES);

    printf("tailcnt: %d\n", tailcnt);
    printf("nlines: %d\n", nlines);
    if (nlines <= tailcnt) {
        for (int i = 0; i < nlines; i++)
            printf("%s\n", lineptrs[i]);
    } else {
        for (int i = 1; i <= tailcnt; i++)
            printf("%s\n", lineptrs[nlines - i]);
    }
}

#define MAXLEN 1000
int my_getline(char s[], int lim);
char* alloc(int n);

/* readlines:  read input lines */
int readlines(char* lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* my_getline:  get line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

char* alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return 0;
}

void afree(char* p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
