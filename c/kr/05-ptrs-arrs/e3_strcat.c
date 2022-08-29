#include <stdio.h>
#define MAXLINE 1000

// Exercise 5.3: Write a pointer version of the function strcat that we showed
// in Chapter 2: strcat(s,t) copies the string t to the end of s.

void strcat0(char s[], char t[]);
void strcat1(char* s, char* t);

int main()
{
    char s1[MAXLINE] = "Hello, ";
    char s2[MAXLINE] = "World!";
    strcat0(s1, s2);
    printf("%s\n", s1);

    char s3[MAXLINE] = "My, ";
    char s4[MAXLINE] = "World!";
    strcat1(s3, s4);
    printf("%s\n", s3);
}

/* strcat:  concatenate t to end of s; s must be big enough */
void strcat0(char s[], char t[])
{

    int i, j;
    i = j = 0;
    while (s[i] != '\0') /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}

void strcat1(char* s, char* t)
{
    // Find end of 's'.
    while (*s++)
        ;
    s--;

    while ((*s++ = *t++))
        ;
}
