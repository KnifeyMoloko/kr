#include <stdio.h>


int main() {
    char current = 'a';
    char previous = 'a';
    char blank = ' ';

    while ((current = getchar()) != EOF) {
        if (previous == blank && current == blank) {
            previous = current;
            continue;   
        } else {
            putchar(current);
            previous = current;
        }
    }
}
