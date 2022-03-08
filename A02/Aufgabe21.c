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

int gibIntWert(char type, int min, int max);

int istSchaltjahr(int jahr);

int tageProMonat(int jahr, int monat);

int checkRangeOfInput(int month, int min, int max);

int is_valid_date(int month, int year);

char *getWeekDayname(int dayId);

int maina2_1(int argc, char *argv[]) {

    int monat, jahr = -1;

    //  Monat einlesen und Bereich ueberpruefen
    jahr = gibIntWert('J', 1600, 9999);
    monat = gibIntWert('M', 1, 12);

    if (!is_valid_date(monat, jahr)) {
        printf("Datum ist nicht valid!");
        return EXIT_FAILURE;
    }

    if (monat == -1 || jahr == -1) {
        printf("Fehlerhafte Daten erhalten. Terminiere");
        return EXIT_FAILURE;
    }

    //  Ausgabe zum Test
    printf("Monat: %d, Jahr: %d \n", monat, jahr);

    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

    // Ausgabe
    printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(jahr, monat));
    return EXIT_SUCCESS;
}


int gibIntWert(char type, int min, int max) {
    int userInput = 0;
    printf("Bitte %c angeben\n", type);
    scanf("%i", &userInput);
    if (checkRangeOfInput(userInput, min, max) == 0) {
        userInput = -1;
        printf("%c muss zwischen %i und %i liegen!!!\n", type, min, max);
        exit(EXIT_FAILURE);
    }

    return userInput;
}

int istSchaltjahr(int jahr) {
    int isSchaltjahr = 0;
    if (jahr % 400 == 0) {
        // leap jahr if perfectly divisible by 400
        isSchaltjahr = 1;
    } else if (jahr % 100 == 0) {
        // not a leap year if divisible by 100
        // but not divisible by 400
        int isSchaltjahr = 0;
    } else if (jahr % 4 == 0) {
        // leap year if not divisible by 100
        // but divisible by 4
        isSchaltjahr = 1;
    } else {
        // all other years are not leap years
        int isSchaltjahr = 0;
    }

    return isSchaltjahr;
}

int tageProMonat(int jahr, int monat) {
    int tageProMt = 30;
    switch (monat) {
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
            tageProMt = 28 + (istSchaltjahr(jahr) ? 1 : 0);
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


int is_valid_date(int month, int year) {
    return checkRangeOfInput(year, MIN_YEAR, MAX_YEAR)
           && checkRangeOfInput(month, 1, 12);
}
