//
// Created by armandoshala on 03.03.22.
//

#include <stdio.h>

#define MIN_YEAR 1599
#define MAX_YEAR 10000

enum month_t {
    JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ
};

int gibIntWert(char type, int min, int max);

int istSchaltjahr(int jahr);

int tageProMonat(int jahr, int month);

int validYearRange(int jahr);

int validMonthRange(int month);

int maina2_1(int argc, char *argv[]) {

    int monat, jahr;

    //  Monat einlesen und Bereich ueberpruefen
    monat = gibIntWert("Monat", 1, 12);
    jahr = gibIntWert("Jahr", 1600, 9999);

    //  Ausgabe zum Test
    printf("Monat: %d, Jahr: %d \n", monat, jahr);

    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

    // Ausgabe
    printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(jahr, monat));

    return 0;
}


int gibIntWert(char type, int min, int max) {
    int retVal = 0;
    switch (type) {
        case 'M':
            retVal = 3;
            break;
        case 'J':
            retVal = 2022;
            break;
    }
    return retVal;

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
        case APR:
        case JUN:
        case SEP:
        case NOV:
        default:
            break;
    }

    return tageProMt;
}

int validYearRange(int jahr) {
    return MIN_YEAR <= jahr || jahr < MAX_YEAR ? 1 : 0;
}

int validMonthRange(int month) {
    return 1 <= month || month < 13 ? 1 : 0;
}