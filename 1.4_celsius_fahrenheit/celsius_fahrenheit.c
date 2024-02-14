#include <stdio.h>
#define HIGH 300.0
#define LOW 0.0
#define STEP 20.0

int main() {
    printf("Celsius to Fahrenheit Convertion Table\n");
    printf("\tCelsius\t\tFahrenheit\n");
    for (double i = LOW; i < HIGH; i+=STEP) {
        printf("\t%3.2f\t\t%3.2f\n", i, (9.0 / 5.0) * i + 32);
    }
    printf("**************************\n");
}
