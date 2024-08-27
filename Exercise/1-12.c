#include <stdio.h>
#include <string.h>
#define IN 1
#define OUT 0
int main()
{
    int c, state, word_size = 0;
    state = OUT;
    char character[100];
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            char word[word_size+1];
            strncpy(word, character, word_size);
            word[word_size] = '\0';
            word_size = 0;
            printf("%s\n", word);

        }

        else if (state == OUT)
        {
            state = IN;
            character[word_size++] = c;
        }
        else
        {
            character[word_size++] = c;
        }
    }
    printf("\n");
    return 0;
}