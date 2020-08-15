#include <stdio.h>

struct test{
    int data;
    int number;
    struct test *next;
};



int main(){
    
    struct test okay;
    okay.data = 5;
    printf("\nOur data = %d\n", okay.data);
    
    return 0;
}
