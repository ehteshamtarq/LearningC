#include <stdio.h>

int mymult(int a, int b);

int main(){
    int retval;
    retval = mymult(6,7);
    printf("Answer: %d\n", retval);
}

int mymult(int a, int b)
    {
        int c = a * b;
        return c;
    }