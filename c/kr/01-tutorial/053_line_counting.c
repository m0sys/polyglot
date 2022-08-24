// 1.5 - Character Input and Output.
// 1.5.3 - Line Counting.

#include <stdio.h>

/*  count lines in input */
void countLines() {
    int c, n1;
    n1 = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++n1;
    printf("%d\n", n1);

}

// Exercise 1.8
void countWhitescape() {
    int c, b1, t1, n1;
    b1 = 0;
    t1 = 0;
    n1 = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++b1;
        if (c == '\t')
            ++t1;

        if (c == '\n')
            ++n1;
    }

    printf("blanks = %d, tabs = %d, newlines = %d\n", b1, t1, n1);
}

int main () {
    countWhitescape();
}


