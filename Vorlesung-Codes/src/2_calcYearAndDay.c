#include <stdio.h>

struct date {
	int year;
    int day;
};

struct date calcYearAndDate(int days);
int isLeapYear(int year);
void fromConsole();
void testOnInfiniteLoops();

int main(int argc, char *argv[]) {
    // testOnInfiniteLoops();
    fromConsole();
    return 1;
}

void fromConsole() {
    int n;
    struct date result;
    printf("Enter days passed since 01.01.1980:\n> ");
    scanf ("%d",&n);
    result = calcYearAndDate(n);
    printf("\nYear: %d, Day: %d\n", result.year, result.day);
}

// test if infinite loop is happening here
void testOnInfiniteLoops() {
    int i;
    for (i=0;i<=1827;i++) {
        calcYearAndDate(i);
    }
    printf("\nSuccess: Infinite Loop Test");
}

struct date calcYearAndDate(int days) {
    int year = 1980;
    struct date result;
    while (days >= 365) {
        if (isLeapYear(year)) {
            if (days >= 366) {
                days -= 366;
                year += 1;
            } else if (days == 365) {
                break; // otherwise infinite loop
            }
        } else {
            days -= 365;
            year += 1;
        }
    }
    result.year = year;
    result.day = days;
    return result;
}

int isLeapYear(int year) {
    return ((year % 4) == 0);
}