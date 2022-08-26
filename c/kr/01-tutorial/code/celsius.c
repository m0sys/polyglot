// 1.2 - Variables and Arithmetic Expressions.

#include<stdio.h>

// Exercise 1.4.

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temp scale */
    upper = 300;    
    step = 20;      

    printf("Celsius -> Fahrenheit\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}
