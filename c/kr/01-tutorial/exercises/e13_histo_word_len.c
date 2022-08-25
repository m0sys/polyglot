#include <stdio.h>

#define LEN 11

int main()
{
    int c;

    // Init bins arr.
    int bins[LEN];
    for (int i = 0; i < LEN; i++)
        bins[i] = 0;

    int curr_word_len = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (curr_word_len > LEN - 2)
                bins[10]++;
            else
                bins[curr_word_len]++;
            curr_word_len = 0;
        }

        else
            curr_word_len++;
    }

    // Print histogram.
    for (int i = 0; i < LEN; i++) {
        printf("%d: ", i);
        for (int j = 0; j < bins[i]; j++)
            putchar('#');
        putchar('\n');
    }
}
