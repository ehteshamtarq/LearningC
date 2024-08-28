#include <stdio.h>
#include <ctype.h>
int main(){
    int guess;
    while(scanf("%d", &guess) != EOF){
        // if(!isdigit(guess)){
        //     printf("Not Number");
        //     break;
        // }
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

// When you enter -1 as input in your program, it’s treated as a regular integer rather than the special EOF indicator. 
// Therefore, scanf will successfully read -1 and not interpret it as the end of input.
// EOF is a special condition that scanf detects automatically when input ends (for example, with Ctrl+D on Linux or Ctrl+Z on Windows). 
// Inputting -1 does not trigger EOF, so you need to explicitly check for -1 in your code.



