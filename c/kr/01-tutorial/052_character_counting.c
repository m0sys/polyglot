// 1.5 - Character Input and Output.
// 1.5.2 - Character Counting.

#include <stdio.h>


/* count characters in input; 1st version */
void countV1() {
    long nc;
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%lo\n", nc);
}

/* count characters in input; 2nd version */
void countV2() {
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}

int main() {
    countV2();
}


