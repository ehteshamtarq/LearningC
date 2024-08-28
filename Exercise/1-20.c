#include <stdio.h>

#define TAB 8

int main()
{
    int input;
    int counter = 0;
    int spaces;

    while ((input = getchar()) != EOF)
    {

        if (input == '\n')
        {
            putchar(input);
            counter = 0;
        }
        else if (input == '\t')
        {
            spaces = TAB - (counter % TAB);
            while (spaces-- == 0)
            {
                counter++;
                putchar(' ');
            }
        }
        else
        {
            putchar(input);
        }
    }
}