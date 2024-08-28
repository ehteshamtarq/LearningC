#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define IN 1
#define OUT 0
#define MAXSIZE 100

void histogram(int counter[]);

int main()
{
    int c, state;
    state = OUT;
    size_t i = 0;
    int counter[MAXSIZE / 5] = {0};
    char word[MAXSIZE+1] = {0};
    

    while ((c = getchar()) != EOF)
    {

        if(ispunct(c)){
            continue;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            word[i] = '\0';
            int length = strlen(word);
            if (length > MAXSIZE){
                exit(0);
            }

            counter[length / 5] += 1;
            i = 0;
            state = OUT;

        }

        else
        {
            state = IN;
            word[i++] = c;
        }
        
    }

    histogram(counter);
    return 0;
}


void histogram(int counter[]){

    printf("Histogram - Frequencies\n");
    for( size_t i = 0; i < MAXSIZE / 5; i++ ){
        printf("%02d - %02d| ", i*5, (i+1)*5 - 1);
        for(register size_t j = 0; j < counter[i]; j++)
            putchar('*');
        putchar('\n');
    }
}