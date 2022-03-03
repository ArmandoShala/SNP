//
// Created by armandoshala on 01.03.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_ROWS 8

int a3(double conversionRate);

int a4();

int maina2(void) {
    printf("Hello Word");

    double conversionRate = 1;
    (void) scanf("%lf", &conversionRate);

    a3(conversionRate);
    a3(43158.47); // for debugging purposes

    a4();

    return 0;
}


int a3(double conversionRate) {
    double chf = 200;
    for (int i = 0; i < NUM_ROWS; ++i) {
        printf("%5.0lf CHF\t<--->\t%5.5f BTC\n", chf, chf / conversionRate);
        chf += 200;
    }
    return EXIT_SUCCESS;
}

int a4() {
    int charCount = 0;
    int wordCount = 1;
    char prevChar = ' ';
    char singleChar = ' ';
    while (singleChar != '\n') {
        singleChar = getchar();
        charCount += 1;
        if (singleChar == ' ' || singleChar == '\t') {
            if (prevChar != ' ' && prevChar != '\t') {
                wordCount += 1;
            }
        }
        prevChar = singleChar;
    }

    printf("Char count is: %d\nWord count is: %d", --charCount, wordCount);

    return EXIT_SUCCESS;
}