// 1.3 - The for statement.
#include<stdio.h>

// Exercise 1.5.

/* print Fahrenheit -> Celsius table */
int main() {
    for (int fahr = 300; fahr >= 0; fahr-= 20)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}
