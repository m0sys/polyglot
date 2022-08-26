#include <stdio.h>
/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

// Exercise 1.4
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   // lower limit of temperatuire scale
    upper = 300; // upper limit
    step = 20;   // step size

    celsius = lower;
    printf("Cels| Fahr\n");
    while (celsius <= upper) {
        fahr = celsius * 1.8000 + 32.00;
        printf("%3.0f %6.1f\n", fahr, celsius);
        celsius += step;
    }
}
