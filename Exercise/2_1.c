#include <stdio.h>

int main(){
    int minimum =-(int)((unsigned int)~0 >> 1) - 1;
    printf("Minimum Signed INT %d\n",minimum );
}