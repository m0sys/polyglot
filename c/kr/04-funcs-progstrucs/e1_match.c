#include <stdio.h>
#define MAXLINE 1000

int my_getline(char s[], int lim);
int strindex(char s[], char t[]);

// Exercise 4.1: Write the function strindex(s,t) which returns the position
// of the rightmost occurrence of t in s, or -1 if there is none

int main()
{
    //
    char pattern[] = "ould";
    char matchme[] = "You should, you could you WILL";
    printf("matched? %d\n", strindex(matchme, pattern));
}

int strindex(char s[], char t[])
{

    int rightmost = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        int j, k;
        for (j = i, k = 0; t[k] != '\0' && t[k] == s[j]; j++, k++)
            ;

        if (k > 0 && t[k] == '\0')
            rightmost = i;
    }
    return rightmost;
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
