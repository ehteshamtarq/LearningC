#include <stdio.h>
#include <string.h>
int main(){
    int c, nl;
    nl = 0;

    while((c = getchar()) != EOF){
        printf("%c", &c);
        if (c == '\n')
            nl++;
    }

    printf("%d\n", nl);
}
