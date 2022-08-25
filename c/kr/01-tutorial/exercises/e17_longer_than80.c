#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */
#define LONGER_THAN 80 /* filter for min line length */
int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len; /* current line length */
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > LONGER_THAN)
            printf("%d: %s", len, line);
}

/* my_getline:  read a line into s, return length  */
int my_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
