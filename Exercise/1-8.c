#include <stdio.h>

int main() {
    int c, blank_count = 0, tab_count = 0, newline_count = 0;

    printf("Enter text:\n");

    // Read input character by character
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blank_count++;
        }else if(c == '\t'){
            tab_count++;
        }else if(c == '\n'){
            newline_count++;
        }
    }

    printf("Number of blanks: %d\n Number of tabs: %d\n Number of newlines: %d\n", blank_count, tab_count, newline_count);

    return 0;
}
