#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[], int maxline);
void remove_trailing_blanks_tabs(char line[]);
void remove_internal_tabs(char line[]);

int main() {
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        remove_trailing_blanks_tabs(line);
        remove_internal_tabs(line);
        if (line[0] != '\0') { // if the line is not entirely blank
            printf("%s", line);
        }
    }

    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* remove_trailing_blanks_tabs: remove trailing blanks and tabs from a line */
void remove_trailing_blanks_tabs(char s[]) {
    int i = 0;

    while (s[i] != '\0') {
        ++i;
    }

    --i; // back off from '\0'
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) {
        s[i] = '\0';
        --i;
    }

    if (i >= 0) {
        s[++i] = '\n';
        s[++i] = '\0';
    }
}

/* remove_internal_tabs: remove tabs from within a line */
void remove_internal_tabs(char s[]) {
    int i, j;
    i = j = 0;

    while (s[i] != '\0') {
        if (s[i] != '\t') {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
}
