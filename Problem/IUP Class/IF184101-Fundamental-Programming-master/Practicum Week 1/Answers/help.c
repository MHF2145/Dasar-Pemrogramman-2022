#include <stdio.h>

int main() {
    int date, month, year;
    scanf("%d %d %d", &date, &month, &year);
    
    // list each month's day count
    int jan = 31, feb = 28, mar = 31, apr = 30, may = 31, jun = 30, jul = 31, aug = 31, sep = 30, oct = 31, nov = 30, dec = 31;

    // check if leap year
    if (year % 4 == 0) {
        printf("it is a leap year.");
    } else if (date > 31 || date < 0 || month > 12 || month < 0 || year > 2080 || year < 0) {
        printf("invalid date or month!!!");
    } else if (month == 1 && date > 31) {
        printf("invalid date or month!!!");
    } else if (month == 2 && date > 28) {
        printf("invalid date or month!!!");
    } else if (month == 3 && date > 31) {
        printf("invalid date or month!!!");
    } else if (month == 4 && date > 30) {
        printf("invalid date or month!!!");
    } else if (month == 5 && date > 31) {
        printf("invalid date or month!!!");
    } else if (month == 6 && date > 30) {
        printf("invalid date or month!!!");
    } else if (month == 7 && date > 31) {
        printf("invalid date or month!!!");
    } else if (month == 8 && date > 31) {
        printf("invalid date or month!!!");
    } else if (month == 9 && date > 30) {
        printf("invalid date or month!!!");
    } else if (month == 10 && date > 31) {
        printf("invalid date or month!!!");
    } else if (month == 11 && date > 30) {
        printf("invalid date or month!!!");
    } else if (month == 12 && date > 31) {
        printf("invalid date or month!!!");
    } else {
        // valid
        // get day number from 1 to 365
        switch (month)
        {
        case 1:
            printf("Day number: %d", date);
            break;
        case 2:
            printf("Day number: %d", date + jan);
            break;
        case 3:
            printf("Day number: %d", date + jan + feb);
            break;
        case 4:
            printf("Day number: %d", date + jan + feb + mar);
            break;
        case 5:
            printf("Day number: %d", date + jan + feb + mar + apr);
            break;
        case 6:
            printf("Day number: %d", date + jan + feb + mar + apr + may);
            break;
        case 7:
            printf("Day number: %d", date + jan + feb + mar + apr + may + jun);
            break;
        case 8:
            printf("Day number: %d", date + jan + feb + mar + apr + may + jun + jul);
            break;
        case 9:
            printf("Day number: %d", date + jan + feb + mar + apr + may + jun + jul + aug);
            break;
        case 10:
            printf("Day number: %d", date + jan + feb + mar + apr + may + jun + jul + aug + sep);
            break;
        case 11:
            printf("Day number: %d", date + jan + feb + mar + apr + may + jun + jul + aug + sep + oct);
            break;
        case 12:
            printf("Day number: %d", date + jan + feb + mar + apr + may + jun + jul + aug + sep + oct + nov);
            break;
        
        default:
            break;
        }
    }

    return 0;
}