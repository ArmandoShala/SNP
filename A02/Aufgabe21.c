//
// Created by armandoshala on 03.03.22.
//

#include <stdio.h>
#include <stdlib.h>

#define MIN_YEAR 1599
#define MAX_YEAR 10000

typedef enum {
    JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ
} month_t;

typedef struct {
    int year;
    month_t month;
    int day;
} date_t;


int gibIntWert(char type, int min, int max);

int is_leap_year(date_t date);

int tageProMonat(int jahr, int month);

int checkRangeOfInput(int month, int min, int max);

int checkStartdateOfGregorianCalendar(int day, int month, int year);

int maina2_1(int argc, char *argv[]) {

    date_t datum;

    //  Monat einlesen und Bereich ueberpruefen
//    jahr = gibIntWert('J', 1600, 9999);
//    monat = gibIntWert('M', 1, 12);
//    tag = gibIntWert('D', 1, tageProMonat(jahr, monat));

    printf("Bite Datum angegeben (YYYY-MM-DD)\n");
    int amountUserArguments = scanf("%i-%i-%i", &datum.year, &datum.month, &datum.day);

    if (amountUserArguments != 3) {
        printf("Datum im falschen Vormat angegeben!\n");
        return EXIT_FAILURE;
    }

    if (!(checkRangeOfInput(datum.year, MIN_YEAR, MAX_YEAR)
          && checkRangeOfInput(datum.month, 1, 12)
          && checkRangeOfInput(datum.day, 1, tageProMonat(datum.year, datum.month)))) {
        printf("Datum ist nicht valid!\n");
        return EXIT_FAILURE;
    }

//    if (monat == -1 || jahr == -1) {
//        printf("Fehlerhafte Daten erhalten. Terminiere");
//        return EXIT_FAILURE;
//    }

    //  Ausgabe zum Test
    printf("Monat: %d, Jahr: %d \n", datum.month, datum.year);

    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    printf("%d ist %s Schaltjahr\n", datum.year, is_leap_year(datum) ? "ein" : "kein");

    // Ausgabe
    printf("Der Monat %02d-%d hat %d Tage.\n", datum.month, datum.year, tageProMonat(datum.year, datum.month));

    return EXIT_SUCCESS;
}


int gibIntWert(char type, int min, int max) {
    int userInput = 0;
    printf("Bitte %c angeben\n", type);
    scanf("%i", &userInput);
    if (checkRangeOfInput(userInput, min, max) == 0) {
        userInput = -1;
        printf("%c muss zwischen %i und %i liegen\n", type, min, max);
    }

    return userInput;
}

int is_leap_year(date_t date) {
    int isSchaltjahr = 0;
    if (date.year % 400 == 0) {
        // leap jahr if perfectly divisible by 400
        isSchaltjahr = 1;
    } else if (date.year % 100 == 0) {
        // not a leap year if divisible by 100
        // but not divisible by 400
        int isSchaltjahr = 0;
    } else if (date.year % 4 == 0) {
        // leap year if not divisible by 100
        // but divisible by 4
        isSchaltjahr = 1;
    } else {
        // all other years are not leap years
        int isSchaltjahr = 0;
    }

    return isSchaltjahr;
}

int get_month_length(date_t date) {
    int tageProMt = 30;
    switch (date.month) {
        case APR:
        case JUN:
        case SEP:
        case NOV:
            tageProMt = 30;
            break;
        case JAN:
        case MAR:
        case MAI:
        case JUL:
        case AUG:
        case OKT:
        case DEZ:
            tageProMt = 31;
            break;
        case FEB:
            tageProMt = 28 + (is_leap_year(date) ? 1 : 0);
            break;
        default:
            tageProMt = 0;
            break;
    }

    return tageProMt;
}

int checkRangeOfInput(int input, int min, int max) {
    return min <= input && input <= max;
}

int checkStartdateOfGregorianCalendar(int day, int month, int year) {
    return year == 1582 && month <= SEP && day <= 14;
}