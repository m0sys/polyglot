/* Exercise 5.1: Modify the function from Listing 5-11 to make it clear to the
 * caller which file could not be opened.
 */
#include <stdio.h>
#include <stdlib.h>

int do_something(void)
{
    FILE *file1, *file2;
    int* obj;
    int ret_val = 0;

    file1 = fopen("a_file", "r");
    if (file1 == NULL) {
        printf("\ndo_something: file 'a_file' could not open.\n");
        ret_val = -1;
        goto fail_file1;
    }

    file2 = fopen("another_file", "r");
    if (file1 == NULL) {
        printf("\ndo_something: file 'another_file' could not open.\n");
        ret_val = -1;
        goto fail_file2;
    }

    obj = malloc(sizeof(int));
    if (obj == NULL) {
        printf("\ndo_something: could not allocate memory for 'obj'.\n");
        ret_val = -1;
        goto fail_obj;
    }

    /* Clean up everything. */
    free(obj);

fail_obj:
    fclose(file2);

fail_file2:
    fclose(file1);

fail_file1:
    return ret_val;
}

int main()
{
    printf("Hello, world!");
    do_something();
}
