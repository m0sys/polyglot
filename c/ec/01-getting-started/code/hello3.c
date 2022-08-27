#include <stdio.h>
#include <stdlib.h>

// Proper way to write "Hello, world!" without any bugs.
int main(void)
{
    if (printf("Hello, world!\n") == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
