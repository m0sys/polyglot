// Exercise 7.4: Write a private version of scanf analogous to minprintf from
// the previous section.

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int minscanf(char* fmt, ...);

int main()
{

    float sum, v;
    sum = 0;
    while (minscanf("%f", &v) == 1)
        printf("\t%.2f\n", sum += v);
}

/* minprintf: minimal printf with variable argument list */
int minscanf(char* fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int* iptr;
    unsigned int* uptr;
    float* fptr;
    int cnt = 0;
    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            int c = getchar();
            if (c != *p)
                printf("error: literal does not match input.");
            continue;
        }
        switch (*++p) {
        case 'd':
            iptr = va_arg(ap, int*);
            scanf("%d", iptr);
            cnt++;
            break;
        case 'o':
            uptr = va_arg(ap, unsigned int*);
            scanf("%o", uptr);
            cnt++;
        case 'f':
            fptr = va_arg(ap, float*);
            scanf("%f", fptr);
            cnt++;
            break;
        case 's':
            for (sval = va_arg(ap, char*); *sval; sval++)
                *sval = getchar();
            cnt++;
            break;
        default:
            // putchar(*p);
            // cnt++;
            break;
        }
    }
    va_end(ap); /* clean up when done */
    return cnt;
}
