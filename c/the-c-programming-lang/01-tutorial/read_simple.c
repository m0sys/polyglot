// 1.5 - Character Input and Output.
// 1.5.1 - File Copying.

#include <stdio.h>
/* copy input to output; 1st version */

void fileCopyV1() {
    int c;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

/* copy input to output; 2nd version */
void fileCopyV2() {
    int c;
    while ((c = getchar()) != EOF) // this is what I love about these prog books! :D
        putchar(c);

}

// Exercise 1.6
void checkExpr() {
    printf("%d\n",getchar() != EOF);
}

// Exercise 1.7
void checkEOF() {
    printf("%d\n", EOF);
}

int main() {
    checkEOF();
}
