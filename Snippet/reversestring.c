#include <stdio.h>
#include <string.h>
int main(){
    char ch[] = "Hello";
    int length = strlen(ch);

    for(int i = 0; i < length / 2; i++){
        char temp = ch[i];
        ch[i] = ch[length-i-1];
        ch[length-i-1] = temp;
    }
    printf("%s", ch);

    // float f = 3.2;
    // printf("%.3f", f);
}
