#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This file contains sln for exercises 4.3 - .

// Exercise 4.3: Add the modulus (%) operator and provisions for negative numbers.
//
// Exercise 4.4: Add the commands to print the top elements of the stack without popping,
// to duplicate it, and to swap the top two elements. Add a command to clear the stack.
//
// Exercise 4.5: Add access to library functions like sin, exp, and pow.

#define MAXOP 100    /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number was found */
#define LIB_FUNC '2' /* signal that a library functions was found */
int getop(char[]);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;

        case LIB_FUNC:
            if (strcmp("sin", s) == 0)
                push(sin(pop()));
            else if (strcmp("cos", s) == 0)
                push(cos(pop()));
            else if (strcmp("pow", s) == 0) {
                op2 = pop();
                push(pow(pop(), op2));
            } else
                printf("error: unknown command %s\n", s);

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
            printf("error: unknown command %s\n", s);
            break;
        }
    }
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

/* top: return top of the stack without popping it off */
double top(void)
{
    if (sp > 0)
        return val[sp - 1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void duplicate(void)
{
    if (sp > 0)
        push(top());
    else
        printf("error: stack empty\n");
}

void swap(void)
{
    if (sp > 1)
        val[sp - 1] = val[sp - 2], val[sp - 2] = val[sp - 1];
    else
        printf("error: stack doesn't contain enough elements\n");
}

int getch(void);
void ungetch(int);

/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-' && c != 's' && c != 'c' && c != 'p')
        return c; /* not a number */
    i = 0;
    if (c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            return '-';
        }
        /* collect sign */
        s[++i] = c;
    }

    // Handle lib functions.
    if (c == 's') {
        int c1 = getch();
        int c2 = getch();
        if (c1 != 'i' || c2 != 'n') {
            ungetch(c2);
            ungetch(c1);
            return c; /* unknown */
        }
        // collect func.
        s[i++] = c;
        s[i++] = c1;
        s[i++] = c2;
        s[i] = '\0';
        return LIB_FUNC;
    }

    if (c == 'c') {
        int c1 = getch();
        int c2 = getch();
        if (c1 != 'o' || c2 != 's') {
            ungetch(c2);
            ungetch(c1);
            return c; /* unknown */
        }
        // collect func.
        s[i++] = c;
        s[i++] = c1;
        s[i++] = c2;
        s[i] = '\0';
        return LIB_FUNC;
    }

    if (c == 'p') {
        int c1 = getch();
        int c2 = getch();
        if (c1 != 'o' || c2 != 'w') {
            ungetch(c2);
            ungetch(c1);
            return c; /* unknown */
        }
        // collect func.
        s[i++] = c;
        s[i++] = c1;
        s[i++] = c2;
        s[i] = '\0';
        return LIB_FUNC;
    }

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */ { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
