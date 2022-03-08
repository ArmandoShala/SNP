//
// Created by armandoshala on 08.03.22.
//

#include "Aufgabe2_32.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// *** TASK1: typedef enum types for month_t (Jan=1,...Dec} ***
// BEGIN-STUDENTS-TO-ADD-CODE
typedef enum {
    JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ
} month_t;

// END-STUDENTS-TO-ADD-CODE



// *** TASK1: typedef struct for date_t ***
// BEGIN-STUDENTS-TO-ADD-CODE
typedef struct {
    int year;
    int month;
    int day;
} date_t;

// END-STUDENTS-TO-ADD-CODE



// *** TASK2: typedef enum weekday_t (Sun=0, Mon, ...Sat) ***
// BEGIN-STUDENTS-TO-ADD-CODE
typedef enum {
    Sun = 0, Mon, Tue, Wed, Thu, Fri, Sat
} weekday_t;

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is a leap year.
 * @returns 0 = is not leap year, 1 = is leap year
 */
// BEGIN-STUDENTS-TO-ADD-CODE
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

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Calculates the length of the month given by the data parameter
 * @returns 28, 29, 30, 31 if a valid month, else 0
 */
// BEGIN-STUDENTS-TO-ADD-CODE

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

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is in the gregorian date range
 * @returns 0 = no, 1 = yes
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int is_gregorian_date(date_t date) {
    int isDateInGregorianDateRange = 1583 <= date.year && date.year <= 9999;

    if (date.year < 1583 && date.month <= OKT && date.day <= 14) {
        isDateInGregorianDateRange = 0;
    }
    return isDateInGregorianDateRange;
}

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Checks if the given date is a valid date.
 * @returns 0 = is not valid date, 1 = is valid date
 */
// BEGIN-STUDENTS-TO-ADD-CODE
is_valid_date2(date_t
date){
return
is_gregorian_date(date)
&&
get_month_length(date);
}

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK2: calculated from a valid date the weekday
 * @returns returns a weekday in the range Sun...Sat
 */
// BEGIN-STUDENTS-TO-ADD-CODE
weekday_t calculate_weekday(date_t date) {
    assert(is_valid_date2(date));
    return (date.year + date.year / 4 - date.year / 100 + date.year / 400 + (13 * date.month + 8) / 5 + date.day) % 7;
}

// END-STUDENTS-TO-ADD-CODE



/**
 * @brief   TASK2: print weekday as 3-letter abreviated English day name
 */
// BEGIN-STUDENTS-TO-ADD-CODE
char *getWeekDayname(int dayId) {

    return dayId == 1
           ? "Mon" : dayId == 2
                     ? "Tue" : dayId == 3
                               ? "Wed" : dayId == 4
                                         ? "Thu" : dayId == 5
                                                   ? "Fri" : dayId == 6
                                                             ? "Sat" : "Sun";
}


// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   main function
 * @param   argc [in] number of entries in argv
 * @param   argv [in] program name plus command line arguments
 * @returns returns success if valid date is given, failure otherwise
 */
int main2_31(int argc, const char *argv[]) {
    // TASK1: parse the mandatory argument into a date_t variable and check if the date is valid
    // BEGIN-STUDENTS-TO-ADD-CODE
    date_t datum;
    int amountUserArguments = sscanf(argv[1], "%d-%d-%d", &datum.year, &datum.month, &datum.day);

    if (amountUserArguments != 3) {
        printf("Datum im falschen Vormat angegeben!\n");
        return EXIT_FAILURE;
    }
    // END-STUDENTS-TO-ADD-CODE


    // TASK2: calculate the weekday and print it in this format: "%04d-%02d-%02d is a %s\n"
    // BEGIN-STUDENTS-TO-ADD-CODE

    char weekday = calculate_weekday(datum);

    printf("%04d-%02d-%02d is a %s\n", datum.year, datum.month, datum.day, getWeekDayname(weekday));

    // END-STUDENTS-TO-ADD-CODE

    return EXIT_SUCCESS;
}

