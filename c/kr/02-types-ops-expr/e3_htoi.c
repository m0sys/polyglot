#include <ctype.h>
#include <stdio.h>

// Exercise 2.3: Write a function htoi(s), which converts a string of
// hexadecimal digits (including an optional 0x or 0X) into its equivalent
// integer value. The allowable digits are 0 through 9, a through f,
// and A through F.
int htoi(char s[]);

int main()
{
    printf("0xA = %d\n", htoi("0xA"));
    printf("0xFF = %d\n", htoi("0xFF"));
    printf("FF = %d\n", htoi("FF"));
}

int htoi(char s[])
{
    int i = 0;
    int n = 0;

    if (s[0] == '0' && tolower(s[1]) == 'x') {
        i = 2;
    }
    for (; isxdigit(s[i]); ++i) {
        if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f')
            n = 16 * n + (tolower(s[i]) - 'a' + 10);
        else
            n = 16 * n + (s[i] - '0');
    }

    return n;
}
