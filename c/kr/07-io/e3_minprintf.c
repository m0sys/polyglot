// Exercise 7.3: Revise minprintf to handle more of the other facilities of printf.

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define LUCK_NUMBER 7

void minprintf(char* fmt, ...);

int main()
{
    minprintf("Hello, World!\n");
    minprintf("My luck number is %d\n", LUCK_NUMBER);
    minprintf("My luck number is %o\n", LUCK_NUMBER);
    minprintf("My luck number is %.2f\n", LUCK_NUMBER);
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char* fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'o':
            ival = va_arg(ap, unsigned int);
            printf("%o", ival);
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char*); *sval; sval++)
                putchar(*sval);
            break;
            // case '.': {
            //     char dec = *++p;
            //     char type = *++p;
            //     // FIXME: needs malloc.
            //     char* fmt = '.' + dec + type + '\0';
            //     dval = va_arg(ap, double);
            //     printf(fmt, dval);
            //     break;
            // }

        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap); /* clean up when done */
}
