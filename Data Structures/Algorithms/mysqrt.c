// Arup Guha
// 6/11/07 - Written in COP 3502 as an example of recursion
// The function below uses a form of bisection to determine the square root
// of a number.

#include <stdio.h>

// A small value!
#define EPSILON 0.000001

double mysqrt(double n);
double sqrthelp(double n, double guess);

int main() {
    
    // Just a small test - prints out the square root of some integers.
    int i;
    for (i=4; i<100; i+=3)
       printf("%d %lf\n", i, mysqrt(i));
   
    system("PAUSE");
    return 0;   
}

// Pre-condition: n is positive.
// Post-condition: Returns an approximation to the square root of n.
double mysqrt(double n) {

    // Takes care of the illegal case.
    if (n < 0) return -1;
    
    // Calls the recursive method with an initial guess for the square root of n.
    return sqrthelp(n, (1+n)/2);       
}

// Pre-condition: n is positive, and guess is in between 1 and n.
// Post-condition: Returns an approximation to the square root of n.
double sqrthelp(double n, double guess) {

    // If our guess is very close to the square root of n, return it!
    if (fabs(guess*guess-n) < EPSILON)
        return guess;
        
    // Otherwise, try again, this time with a guess that is sure to be closer.
    else
        return sqrthelp(n, (guess + n/guess)/2);     
       
}
