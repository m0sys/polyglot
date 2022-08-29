#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Exercise 5.10: Write the program expr, which evaluates a reverse Polish
// expression from the command line, where each operator or operand is a separate argument.
// For example, expr 2 3 4 + * evaluates 2 * (3+4)

#define MAXOP 100    /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number was found */
#define LIB_FUNC '2' /* signal that a library functions was found */
int getop(char s[]);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(int argc, char* argv[])
{
    int type;
    double op2;
    int op = 0;
    while (++op < argc) {
        type = getop(argv[op]);
        switch (type) {
        case NUMBER:
            push(atof(argv[op]));
            break;

        case LIB_FUNC:
            if (strcmp("sin", argv[op]) == 0)
                push(sin(pop()));
            else if (strcmp("cos", argv[op]) == 0)
                push(cos(pop()));
            else if (strcmp("pow", argv[op]) == 0) {
                op2 = pop();
                push(pow(pop(), op2));
            } else
                printf("error(1): unknown command %s\n", argv[op]);

            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error(2): unknown command %s\n", argv[op]);
            break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}

// Stack stuff.

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push:  push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop:  get next character or numeric operand */
int getop(char s[])
{
    // Handle lib functions.
    if (strcmp(s, "sin") == 0 || strcmp(s, "cos") == 0 || strcmp(s, "pow") == 0) {
        return LIB_FUNC;
    }

    if (isdigit(s[0]) || (s[0] == '-' && s[1] != '\0'))
        return NUMBER;
    return s[0]; /* not a number */
}
