// 1.3 - The for statement.
#include<stdio.h>

/* print Fahrenheit -> Celsius table */
int main() {
    for (int fahr = 0; fahr <= 300; fahr+= 20)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}
