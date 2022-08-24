// 1.2 - Variables and Arithmetic Expressions.

#include<stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */

int main() {
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0;      /* lower limit of temp scale */
    upper = 300;    
    step = 20;      

    printf("Fahrenheit -> Celsius\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr-32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += step;
    }
}
