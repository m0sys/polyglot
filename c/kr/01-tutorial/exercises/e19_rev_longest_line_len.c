#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int my_getline(char line[], int maxline);
void copy(char to[], char from[]);
void rev_line(char s[], int len);

/* print the longest input line */
int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE];
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            rev_line(line, max);
            copy(longest, line);
        }
    if (max > 0) /*therewasaline*/
        printf("%d: %s", max, longest);
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

/* rev_line: reverses the line */
void rev_line(char s[], int len)
{
    for (int i = 0, j = len - 2; i < len && i < j; i++, j--) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
