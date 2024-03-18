# include <stdio.h>

int main() {
    long blanks = 0;
    long tabs = 0;
    long newlines = 0;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        }

        if (c == '\t') {
            ++tabs;
        }

        if (c == '\n') {
            ++newlines;
        }
    }

    printf("Blanks: %ld\nTabs: %ld\nNewlines: %ld\n", blanks, tabs, newlines);
    printf("END\n");
    return 0;
}
