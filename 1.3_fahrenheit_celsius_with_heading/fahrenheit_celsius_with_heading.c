#include <stdio.h>
#define HIGH 300.0
#define LOW 0.0
#define STEP 20.0

int main() {
    printf("Fahrenheit to Celsius Convertion Table\n");
    printf("\tFahrenheit\tCelsius\n");
    for (double i = LOW; i < HIGH; i+=STEP) {
        printf("\t%3.2f\t\t%3.3f\n", i, (5.0 / 9.0) * (i - 32.0));
    }
    printf("**************************\n");
}
