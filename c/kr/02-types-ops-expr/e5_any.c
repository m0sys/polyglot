#include <stdio.h>

// Exercise 2.5: Write the function any(s1,s2), which returns the first
// location in a string s1 where any character from the string s2 occurs,
// or -1 if s1 contains no characters from s2. (The standard library function
// strpbrk does the same job but returns a pointer to the location.)

int any(char s1[], char s2[]);

int main()
{
    char s1[] = "Hello, World";
    char s2[] = "Howdy, World";
    char s3[] = "";

    printf("Any(s1, s2): %d\n", any(s1, s2));
    printf("Any(s1, s3): %d\n", any(s1, s3));
}

int any(char s1[], char s2[])
{
    for (int j = 0; s2[j] != '\0'; j++)
        for (int i = 0; s1[i] != '\0'; i++)
            if (s1[i] == s2[j])
                return i;
    return -1;
}
