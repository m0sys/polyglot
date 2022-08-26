#include <stdio.h>

#define MAXLINE 10000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

// Exercise 3.2: Write a function escape(s,t) that converts characters like
// newline and tab into visible escape sequences like \n and \t as it copies
// the string t to s. Use a switch. Write a function for the other direction
// as well, converting escape sequences into the real characters.

int main()
{
    char s1[] = "Hello, World\n";
    char s2[MAXLINE];
    char s3[MAXLINE];
    escape(s1, s2);
    printf("Not Escaped: %s\n", s1);
    printf("Escaped: %s\n", s2);

    unescape(s2, s3);
    printf("Unescaped: %s\n", s3);
}

void escape(char s[], char t[])
{
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;

        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;

        default:
            t[j++] = s[i];
        }
    }

    t[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++) {

        if (s[i] == '\\') {
            switch (s[i + 1]) {
            case 'n':
                t[j++] = '\n';
                i++;
                break;

            case 't':
                t[j++] = '\t';
                i++;
                break;
            default:
                t[j++] = '\\';
                break;
            }
        } else {

            t[j++] = s[i];
        }
    }

    t[j] = '\0';
}
