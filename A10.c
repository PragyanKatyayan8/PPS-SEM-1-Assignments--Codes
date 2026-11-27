#include <stdio.h>

int main() {
    int year, month, day, days, i, j;
    int firstDay;
    char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    int monthDays[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    printf("Enter year: ");
    scanf("%d", &year);

    if (year < 1) {
        printf("Invalid year!\n");
        return 1;
    }

    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
        monthDays[1] = 29;

    firstDay = (year - 1 + (year - 1) / 4
                - (year - 1) / 100
                + (year - 1) / 400 + 1) % 7;

    printf("\n          CALENDAR %d\n", year);

    for (i = 0; i < 12; i++) {
        printf("\n       %s\n", months[i]);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        days = monthDays[i];

        for (j = 0; j < firstDay; j++)
            printf("    ");

        for (day = 1; day <= days; day++) {
            printf("%4d", day);

            if ((firstDay + day) % 7 == 0)
                printf("\n");
        }

        printf("\n");
        firstDay = (firstDay + days) % 7;
    }

    return 0;
}