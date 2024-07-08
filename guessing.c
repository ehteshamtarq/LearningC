#include <stdio.h>
#define EOF -1
int main(){
    int guess;
    while(scanf("%d", &guess) != EOF){
        if (guess == 42){
            printf("Nice work!\n");
            break;
        }
        else if (guess < 42)
            printf("Too low");
        else
            printf("Too high");
    }
}