#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define IN 1
#define OUT 0
#define MAXSIZE 100

void histogram(int counter[], int max);

int main()
{
    int c, state;
    state = OUT;
    size_t i = 0;
    size_t max = 0;
    int counter[MAXSIZE+1] = {0};
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

            if(length > max){
                max = length;
            }
            counter[length] += 1;
            i = 0;
            state = OUT;

        }

        else
        {
            state = IN;
            word[i++] = c;
        }
        
    }

    histogram(counter, max);
    return 0;
}


void histogram(int counter[], int max){

    printf("Histogram - Horizontal\n");
    for( size_t i = 1; i < max; i++ ){
        printf("%02d| ", i);
        for(register size_t j = 0; j < counter[i]; j++)
            putchar('*');
        putchar('\n');
    }
}