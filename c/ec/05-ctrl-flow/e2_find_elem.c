/*
 * Change the find_element function from Listing 5-13 to return the position
 * of the key in a.
 * Don’t forget to return an error indication if the key is not found.
 */
#include <stdio.h>
#include <stdlib.h>

size_t find_elem(size_t len, int arr[len], int key)
{
    for (size_t i = 0; i < len; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return EXIT_FAILURE;
}
