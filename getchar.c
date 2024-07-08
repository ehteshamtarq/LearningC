#include <stdio.h>
#include <string.h>
// #define EOF -1
main(){
    // char ch = 'H';
    // int length = strlen(ch);

    // for(int i = 0; i < length / 2; i++){
    //     char temp = ch[i];
    //     ch[i] = ch[length-i-1];
    //     ch[length-i-1] = temp;
    // }

    // float f = 3.2;
    // printf("%.3f", f);

    int c = getchar();
    while ( c != -1){
        putchar(c);
        c = getchar();
    }
}
