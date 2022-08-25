#include <stdio.h>
#define HEX 16

// Exercise 2.3: Write a function htoi(s), which converts a string of
// hexadecimal digits (including an optional 0x or 0X) into its equivalent
// integer value. The allowable digits are 0 through 9, a through f,
// and A through F.

int main() { }

/* atoi:  convert s to integer */
int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

// TODO: figure out how to htoi
int htoi(char s[])
{
    int i = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
    }

    for (; s[i] >= '0' && (s[i] <= 'F' || s[i] <= 'f'); ++i) { }
    return 0;
}
