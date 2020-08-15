// Arup Guha
// 1/29/2010
// In-class Example COP 3502
// Recursive functions related to base conversion.

#include <stdio.h>

int sumdigits(int n);
int sumdigitsinbase(int n, int b);
void printbaseconv(int n, int b);

int main() {

    // Test sum digits function.
    printf("Sum of the digits of 175 in base 10 is %d\n", sumdigits(175));
      
    // Test sum digits in a different base function.
    printf("sum of digits of 175 in base 3 is %d\n", sumdigitsinbase(175,3));
    
    // Test printing out base conversion
    printf("175 in base 3 is ");
    printbaseconv(175, 3);
    printf("\n");
    
    system("PAUSE");
    return 0;
}

// Pre-condition: n >= 0
// Post-condition: Returns the sum of the digits of n.
int sumdigits(int n) {
    
    if (n < 10)
        return n;
        
    // Here, we isolate the last digit (n%10), and add it to the sum of
    // the rest of the digits, n/10.
    else
        return n%10 + sumdigits(n/10);
    
}

// Pre-condition: n >= 0, 2 <= b <= 9
// Post-condition: Returns the sum of the digits of n's representation in
//                 base b.
int sumdigitsinbase(int n, int b) {
    
    if (n < b)
        return n;
    
    // Same exact idea as before, but adjusted for the different base.
    else
        return n%b + sumdigitsinbase(n/b, b);
    
}

// Pre-condition: n >= 0, 2 <= b <= 9
// Post-condition: Prints out the value of n converted to base b.
void printbaseconv(int n, int b) {
     
     if (n < b)
         printf("%d", n);
     
     // First we print the rest of the number converted.
     // We end by printing the last digit.
     else {
         printbaseconv(n/b, b);
         printf("%d", n%b);     
     }
}
