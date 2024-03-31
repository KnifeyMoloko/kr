#include <stdio.h>
#define WORD_LIMIT 1000000
#define HISTOGRAM_BARS 50 // the longest word in English is 45 chars, we round up to 50
#define X_AXIS_SIZE 50.0 // size of the X axis for the output
#define Y_AXIS_SIZE 50.0 // size of the Y axis for the output
#define WORD_IN 1
#define WORD_OUT 0

int main() {
    char c;
    int prevState = WORD_OUT;
    long wordLengths[WORD_LIMIT];
    long histogramBars[HISTOGRAM_BARS];
    long index = 0;
    long max = 0;
    double ratio = 0.0;

    for (long i = 0; i < WORD_LIMIT; i++) {
        wordLengths[i] = 0;
    }

    for (long j = 0; j < HISTOGRAM_BARS; j++) {
       histogramBars[j] = 0; 
    }
    
    while ((c = getchar()) != EOF) {
            if ((c < 65) || (c > 122)) {
            if (prevState == WORD_IN) {
                index++;
                prevState = WORD_OUT;
            }
        } else {
            prevState = WORD_IN;
            wordLengths[index]++;
        }
    }

    for (long i = 0; i < WORD_LIMIT; i++) {
        if (wordLengths[i] > 0) {
            histogramBars[wordLengths[i]]++;
        }  
    }

    printf("Histogram array values:\n");

    for (int k = 1; k < HISTOGRAM_BARS; k++) {
        printf("%lu, ", histogramBars[k]);
    }
    putchar('\n');

    for (long i = 0; i < HISTOGRAM_BARS; i++) {
        if (histogramBars[i] > max) {
            max = histogramBars[i];
        }
    }

    ratio = max / X_AXIS_SIZE;

    // check if ratio is non-zero. If it's zero, we default to using 
    // the as-is values
    if (ratio) {
        long normalized[HISTOGRAM_BARS];

        for (long i = 0; i < HISTOGRAM_BARS; i++) {
        normalized[i] = 0;
        }

        for (long j = 1; j < HISTOGRAM_BARS; j++) {
            if (histogramBars[j] > 0 && (histogramBars[j] / ratio) < 1) {
                normalized[j] = 1;
            }
            else {
                normalized[j] = histogramBars[j] / ratio;}
        }

        printf("Normalized array (as pairs of original : normalized values:\n");

        for (long k = 1; k < HISTOGRAM_BARS; k++) {
            printf("%lu : %lu, ", histogramBars[k], normalized[k]);
        }
        putchar('\n');

        printf("\n\nHistogram:\n(Using normalized values to scale output)\n");
        printf("=======================================\n");

        for (int i = Y_AXIS_SIZE; i > 0; i--) {
            printf("%4d|", i);
            for (int j = 0; j < X_AXIS_SIZE; j++) {
                if (normalized[j] >= i) {
                    printf("|*|");
                } else {
                    printf("| |");
                }
            }
            putchar('\n');
        }

        printf("     ");
        for (int n = 0; n < X_AXIS_SIZE; n++) {
            printf("===");
        }
        putchar('\n');

        printf("     ");
        for (int k = 0; k < X_AXIS_SIZE; k++) {
            printf("%2d ", k);
        }
        putchar('\n');

    } else {
        printf("\nHistogram:\n(Using non-normalized, as-is values)\n\n");
        printf("=======================================\n");

        for (int i = Y_AXIS_SIZE; i > 0; i--) {
            printf("%4d|", i);
            for (int j = 0; j < X_AXIS_SIZE; j++) {
                if (histogramBars[j] >= i) {
                    printf("|*|");
                } else {
                    printf("| |");
                }
            }
            putchar('\n');
        }

        printf("     ");
        for (int k = 0; k < X_AXIS_SIZE; k++) {
            printf("%2d ", k);
        }
        putchar('\n');

        printf("     ");
        for (int n = 0; n < X_AXIS_SIZE; n++) {
            printf("===");
        }
        putchar('\n');

        printf("     ");
        for (int k = 0; k < X_AXIS_SIZE; k++) {
            printf("%2d ", k);
        }
        putchar('\n');
    }

    printf("\n****\nBye!\n****\n");

    return 0;
}
