// 1.2 - Variables and Arithmetic Expressions.

#include<stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */

int main() {
    int fahr, celsius;
    int lower, upper, step;
    
    lower = 0;      /* lower limit of temp scale */
    upper = 300;    
    step = 20;      

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%3d\t%6d\n", fahr, celsius);
        fahr += step;
    }
}
