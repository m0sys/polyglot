/*
 * Exercise 6.1: Repair the use-after-free defect from Listing 6-4.
 */

#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
int closedir(DIR* dirp)
{
    free(dirp->d_buf);
    dirp->d_buf = NULL;
    free(dirp);
    dirp = NULL;
    return close(dirp->d_fd); // dirp has already been freed
                              //
}
