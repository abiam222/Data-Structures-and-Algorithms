// Arup Guha
// 4/16/2010
// For CS1 Bitwise Operator Lecture

#include <stdio.h>

int sumbits(int n);

int main() {
    
    
    int x, y;
    
    x = 47;
    y = 72;
    
    int xor  = x ^ y; // xor    
    int and = x & y; // and
    int or = x | y; // or
    int not = ~x;
    
    printf("%d %d %d %d\n", xor, and, or, not);
    
    int value = 0x13355777;
    printf("%d\n", value);
    
    int twopower = 1 << 10;
    int half = twopower >> 1;
    printf("%d\n", twopower);
    printf("%d\n", half);
    
    printf("sum of the bits of %d is %d\n", 47, sumbits(47)); 
    
    
    int i, j;
    int n = 5;
    int array[] = {9, 3, 4, 5, 12};
    int target = 22;
    
    for (i=0; i < (1 << n); i++) {
        
        int sum = 0;
        // loop through each location in the binary representation of i
        for (j=0; j < n; j++)
            if ( (i & (1 << j)) != 0 )
                sum += array[j];
                
        printf("%d sum = %d\n", i, sum);    
    }
    
    // Forming Color Information
    // Extracting Color Information
    
    system("PAUSE");
    return 0;
    
}

int sumbits(int n) {
    
    int sum = 0;
    while (n > 0) {
        sum += (n & 1);
        n = (n >> 1);
    }
    return sum;
}
