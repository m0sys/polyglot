// Exercise 7.1: Write a program that converts upper case to lower or lower
// case to upper, depending on the name it is invoked with, as found in argv[0].

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int is_lower = 0;
    if (strcmp(argv[0], "./lower") == 0)
        is_lower = 1;

    for (int i = 0; i < argc; i++)
        printf("%d: %s\n", i, argv[i]);

    int c;
    while ((c = getchar()) != EOF)
        putchar(is_lower ? tolower(c) : toupper(c));
}
