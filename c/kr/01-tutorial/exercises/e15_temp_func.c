#include <stdio.h>

// Exercise 1.15
float fahr2cels(int fahr);

int main()
{
    float fahr;
    float lower, upper, step;
    lower = 0;   // lower limit of temperatuire scale
    upper = 300; // upper limit
    step = 20;   // step size

    fahr = lower;
    printf("Fahr| Cels\n");
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, fahr2cels(fahr));
        fahr = fahr + step;
    }
}

float fahr2cels(int fahr) { return (5.0 / 9.0) * (fahr - 32.0); }
