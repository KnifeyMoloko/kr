#include <stdio.h>
#define REPLACE_BACKSLASH "//"
#define REPLACE_BACKSPACE "\\b"
#define REPLACE_TAB "\\t"

int main() {
    char ch;

    while ((ch = getchar()) != EOF) {
        if (ch == '\t') {
            printf("%s", REPLACE_TAB);
        } else if (ch == '\b') {
            printf("%s", REPLACE_BACKSPACE);
        } else if (ch == '\\') {
            printf("%s", REPLACE_BACKSLASH);
        } else {
            putchar(ch);
        }
    }
}
