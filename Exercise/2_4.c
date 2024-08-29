#include <stdio.h>

#define MAXLINE 1000

int mgetline(char s[], int lim);

void squeeze(char s1[], const char s2[]);

int main(void) {
    char s1[MAXLINE], s2[MAXLINE];
    mgetline(s1, MAXLINE);
    mgetline(s2, MAXLINE);

    squeeze(s1, s2);

    printf("\n%s\n", s1);

    return 0;
}

int mgetline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    s[i] = '\0';

    return i;
}

void squeeze(char s1[], const char s2[]) {
    int i, j, k;
    k = 0;

    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; (s1[i] != s2[j]) && s2[j] != '\0'; ++j)
            ;
        if (s2[j] == '\0')
            s1[k++] = s1[i];
    }

    s1[k] = '\0';
}