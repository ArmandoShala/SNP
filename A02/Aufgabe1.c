//
// Created by armandoshala on 03.03.22.
//

#include <stdio.h>
#include <malloc.h>


enum month_t {
    JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ
};

int gibIntWert(char type, int min, int max);

int istSchaltjahr(int jahr);

int tageProMonat();

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
    char *input = (char *) malloc(sizeof(char) * 10);
    int value;
    printf("%s: ", type);
    fgets(input, 10, stdin);
    value = atoi(input);
    if (value < min || value > max) {
        printf("%s muss zwischen %d und %d liegen.\n", type, min, max);
        return gibIntWert(type, min, max);
    }
    return value;
}

int istSchaltjahr(int jahr) {
    int isSchaltjahr = 0;
    // leap jahr if perfectly divisible by 400
    if (jahr % 400 == 0) {
        isSchaltjahr = 1;
    }
        // not a leap year if divisible by 100
        // but not divisible by 400
    else if (jahr % 100 == 0) {
        int isSchaltjahr = 0;
    }
        // leap year if not divisible by 100
        // but divisible by 4
    else if (jahr % 4 == 0) {
        isSchaltjahr = 1;
    }
        // all other years are not leap years
    else {
        int isSchaltjahr = 0;
    }

    return 0;
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
    return 1599 <= jahr || jahr < 10000 ? 1 : 0;
}

int validMonthRange(int month) {
    return 1 <= month || month < 13 ? 1 : 0;
}