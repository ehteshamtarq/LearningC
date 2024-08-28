#include <stdio.h>

int main() {
    int c;
    c = getchar();  // Read the first character
    
    while (c != EOF) {  // Continue until EOF is encountered
        putchar(c);  // Print the ASCII value of the character
        c = getchar();  // Read the next character
    }
    
    printf("\nEOF encountered, exiting.\n");
    return 0;
}
