#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getline_clean(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE];
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = getline_clean(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 1) /* ignore blank lines*/
        printf("%d: %s", max, longest);
}

/* getline_clean:  read a line into s while removing trailing blanks/tabs, return length  */
int getline_clean(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (s[i - 1] == ' ' || s[i - 1] == '\t') {
        i = i - 1;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
