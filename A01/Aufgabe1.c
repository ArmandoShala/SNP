//
// Created by armandoshala on 01.03.22.
//

#include <stdio.h>

#define NUM_ROWS 10

void helloWorld(void) {
    printf("Hello World");
}

void bitCoinCalc(void) {
    printf("Bitte Umrechnungsfaktor eingeben\n");
    double factor = 43158.47;
//    (void) scanf("%lf", &factor);

    int amount = 200;
    for (int i = 0; i < NUM_ROWS; ++i) {
        printf("%4.0d CHF\t<-->\t%4.5lf\n", amount, amount / factor);
        amount += 200;
    }
}

void countWords(void) {
//    fgets(singleChar, sizeof(singleChar), stdin);
    int charCount = 0;
    int wordCount = 1;
    char prevChar = ' ';
    char singleChar = ' ';
    printf("Enter a short singleChar to count words:\n");
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

}