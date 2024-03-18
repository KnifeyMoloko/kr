#include <stdio.h>


int main() {
    char c;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n'&& c != '\t') {
            putchar(c);
        } else {
            putchar('\n');
        }

    }

    printf("\n***\nBye!\n***\n");
    return 0;
}

