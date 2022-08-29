#include <stdio.h>

// Exercise 5.9: Rewrite the routines day_of_year and month_day with pointers
// instead of indexing.

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int* pmonth, int* pday);
char* month_name(int n);

int main()
{
    printf("y2k day of year: %d\n", day_of_year(1900, 1, 1));
    int month;
    int day;
    month_day(1900, day_of_year(1900, 1, 1), &month, &day);
    printf("y2k month day: %s %d, %d\n", month_name(month), day, 1900);
}

static char month_no_leap[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static char month_leap[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static char* daytab[2] = { month_no_leap, month_leap };

int is_leap(int year);

/* day_of_year:  set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    char* ptr = daytab[0];
    leap = is_leap(year);

    for (i = 1; i < month; i++)
        day += *(ptr + 13 * leap + i);
    return day;
}

/* month_day:  set month, day from day of year */
void month_day(int year, int yearday, int* pmonth, int* pday)
{
    int i, leap;
    char* ptr = daytab[0];
    leap = is_leap(year);

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= *(ptr + 13 * leap + i);
    *pmonth = i;
    *pday = yearday;
}

/* month_name:  return name of n-th month */
char* month_name(int n)
{
    static char* name[] = { "Illegal month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"

    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}

int is_leap(int year) { return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0); }
