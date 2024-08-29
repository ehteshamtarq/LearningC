#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
#define BASE 16

int main(){
    char number[MAXLINE];
    int len, result = 0;
    int digit, power = 1;
    int c;

    for( int i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        number[i] = c;
        len = i;
    }

    if (number[0] == '0' && (number[1] == 'x' || number[1] == 'X'))
        ;
    else{
        printf("Not a hexa decimal");
        exit(0);
    }


    for( int i = len; i >= 2; i-- ){
        if (number[i] >= '0' && number[i] <= '9') {
            digit = (number[i] - '0');
        } else if (number[i] >= 'a' && number[i] <= 'f') {
            digit = (number[i] - 'a') + 10;
        } else if (number[i] >= 'A' && number[i] <= 'F') {
            digit = (number[i] - 'A') + 10;
        }
        result += digit * power;
        power *= BASE;
        
    }

    printf("Hexa to Decimal %d\n", result);
    return 0;


}