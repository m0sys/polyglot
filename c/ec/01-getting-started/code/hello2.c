#include <stdio.h>
#include <stdlib.h>

// Proper way to write "Hello, world!" without any bugs.
int main(void)
{
    if (puts("Hello, world!") == EOF)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
