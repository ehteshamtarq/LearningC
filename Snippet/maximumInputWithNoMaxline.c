#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line size */

int get_line(char **line, int *limit);
void copy(char *from, char *to);

int main() /* find longest line */
{
    int len;             /* current line length */
    int max;             /* maximum length seen so far */
    char *line;          /* current input line */
    char *save;          /* longest line, saved */
    int limit = MAXLINE; /* initial limit for line length */

    line = (char *)malloc(limit * sizeof(char));
    save = (char *)malloc(limit * sizeof(char));
    if (line == NULL || save == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    max = 0;
    while ((len = get_line(&line, &limit)) > 0)
    {
        if (len > max)
        {
            max = len;
            free(save);                                      // Free the previous longest line
            save = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the new longest line
            if (save == NULL)
            {
                printf("Memory allocation failed\n");
                return 1;
            }
            copy(line, save);
        }
    }
    if (max > 0) /* there was a line */
        printf("Longest line length: %d\n%s", max, save);

    free(line);
    free(save);
    return 0;
}

int get_line(char **line, int *limit) /* get line into s, return length */
{
    int c, i;
    int current_limit = *limit;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i >= current_limit - 1)
        {
            current_limit *= 2; // Double the size
            *line = (char *)realloc(*line, current_limit * sizeof(char));
            if (*line == NULL)
            {
                printf("Memory allocation failed\n");
                exit(1);
            }
        }
        (*line)[i] = c;
    }
    if (c == '\n')
    {
        (*line)[i] = c;
        ++i;
    }
    (*line)[i] = '\0';
    *limit = current_limit;
    return i;
}

void copy(char *from, char *to) /* copy s1 to s2; assume s2 big enough */
{
    while ((*to++ = *from++) != '\0')
        ;
}
