#include <stdio.h>

void removeComment(int c);
void removeQuote(int c);

int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '/')
            removeComment(c);
        else if (c == '\'' || c == '"')
            removeQuote(c);
        else
            putchar(c);
    }
    return 0;
}

void removeComment(int c)
{
    int d = getchar(); 

    if (d == '*') 
    {
        int prev = 0;
        while ((c = getchar()) != EOF)
        {
            if (prev == '*' && c == '/')
                return;
            prev = c;
        }
    }
    else if (d == '/') 
    {
        while ((c = getchar()) != EOF && c != '\n')
            ; 
    }
    else
    {
        putchar(c); 
        putchar(d); 
    }
}

void removeQuote(int c)
{
    int d;
    putchar(c);

    while ((d = getchar()) != c) 
    {
        putchar(d);
        if (d == '\\') 
            putchar(getchar());
    }
    putchar(d); 
}
