#include <stdio.h>

// Exercise 2.4: Write an alternative version of squeeze(s1,s2) that deletes
// each character in s1 that matches any character in the string s2.

void squeeze(char s[], int c);
void alt_squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "Hello, World";
    char s2[] = "Howdy, World";
    alt_squeeze(s1, s2);
    printf("%s\n", s1);
}

void alt_squeeze(char s1[], char s2[])
{
    for (int i = 0; s2[i] != '\0'; i++)
        squeeze(s1, s2[i]);
}

/* squeeze:  delete all c from s */
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}
