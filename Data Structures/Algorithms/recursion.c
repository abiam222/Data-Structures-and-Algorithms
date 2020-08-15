// Arup Guha for COP 3502
// Examples of functions using recursion

#include <stdio.h>
#include <time.h>

int fact(int n);
int sumsq(int start, int end);
int ArrayOdd(int A[], int n);
void print_reverse(char string[], int n);

int powerA(int base, int exp);
int powerB(int base, int exp);
int slowModPow(int base, int exp, int n);
int modPow(int base, int exp, int n);

int Rbinary(int target, int A[], int left, int right);
void dectobin(int n);
int check(char str[], int len);
int fibonacci(int n);

int main() {
    
    // Very basic, NOT comprensive, tests of the recursive methods.
    
    int vals[4];
    printf("7! = %d\n", fact(7));
    printf("31^2 + 32^2 + ... + 200^2 = %d\n", sumsq(31, 200));
    
    vals[0] = 37; vals[1] = 48; vals[2] = 56; vals[3] = 63;
    printf("vals has %d Odd values.\n", ArrayOdd(vals, 4));
    
    print_reverse("writethisbackwards", 18);
    printf("\n");
    printf("3^10 = %d\n", powerA(3,10));
    printf("3^11 = %d\n", powerB(3,11));
     
    if (Rbinary(33, vals, 0, 3) == -1)
        printf("33 was not found in vals.\n");
        
    dectobin(179);
    printf("\n");
    
    if (check("madamimadam", 11))
        printf("madamimadam is a palindrome.\n");
        
    printf("The 27th Fibonacci number is %d\n", fibonacci(27)); 
    
    // Test of fast exponentiation vs. regular version
    
    int start = time(0);
    int ans1 = slowModPow(6874, 1000000000, 13713);
    int end1 = time(0);
    int ans2 = modPow(6874, 1000000000, 13713);
    int end2 = time(0);
    
    printf("ans1 = %d, ans2 = %d.\n", ans1, ans2);
    printf("slowModExp took %d sec.\n", end1-start);
    printf("modPow took %d sec.\n", end2-end1);
    
    system("PAUSE");
    return 0;
}

// Pre-condition: n is a non-negative integer less than 13.
// Post-condition: returns the value of n!
int fact(int n) {
    
    // This is the "base case" that can be solved without recursion.
    if (n == 0)
        return 1;
        
    // Here is the standard recursive solution to this problem.
    else
        return n*fact(n-1);
}

// Pre-condition: start <= end
// Post-condition: Returns the sum of the squares of the integers starting from
//                 start and ending at end.
int sumsq(int start, int end) {
       
    // Base case were one value is being summed. 
    if (start == end)
       return start*start;
 
    // This is the recursive solution for larger cases.      
    return start*start + sumsq(start+1, end);
}

// Pre-condition: Array A is at least of size n.
// Post-condition: Returns the number of values in A that are odd from index 0
//                 to index n-1, inclusive.
int ArrayOdd(int A[], int n) {

    // No elements to search.
    if (n < 1)
       return 0;
       
    // Implement the recursive solution. A[n-1]%2 is equal to 1 iff A[n-1] is
    // odd. So we are adding 1 to our return value if the last value in our
    // search space is odd, zero otherwise, and then we search the array except
    // for this last value.
    else
       return A[n-1]%2 + ArrayOdd(A, n-1);    
}

// Pre-condition: string is a string of length n or greater.
// Post-condition: Prints out the first n characters of string in reverse order.
void print_reverse(char string[], int n) {
     
     // Only one character to print, so print it!
     if (n == 1)
         printf("%c", string[0]);
         
     // Solve the problem recursively: print the last character, then reverse
     // the substring without that last character.
     else {
         printf("%c", string[n-1]);
         print_reverse(string, n-1);
     }
} 

// Pre-condition: base raised to the power exp is not greater than 2^31-1, and
//                exp is non-negative.
// Post-condition: base raised to the power exp is returned.
int powerA(int base, int exp) {
    
    // Everything raised to the 0 power is 1.
    if (exp == 0)
        return 1;
        
    // Apply the recursive algorithm to solve the problem.
    else
        return base*powerA(base, exp-1);
}

// Pre-condition: base raised to the power exp is not greater than 2^31-1, and
//                exp is non-negative.
// Post-condition: base raised to the power exp is returned.
int powerB(int base, int exp) {

    // Everything raised to the 0 power is 1.
    if (exp == 0)
        return 1;
        
    // Anything raised to the 1st power is itself.
    else if (exp == 1)
        return base;
        
    // Utlize the even powered exponent and the rules of exponentiation.
    else if (exp%2 == 0)
        return powerB(base*base, exp/2);
    
    // If we can't, then just use our regular solution.
    else
        return base*powerB(base, exp-1);    
}


// Pre-condition: base^2 < 2^31, n < sqrt(2^31), 0 <= exp < 2^31.
// Post-condition: base raised to the power exp mod n is returned.
int slowModPow(int base, int exp, int n) {
    
    // Note: This is written iteratively because the recursive version
    //       uses up the call stack relatively quickly. Thus, in order
    //       to show the advantage of fast exponentiation, the iterative
    //       version has to be used so that the test can be run on a high
    //       enough base.
    
    int i, ans=1;
    
    // Calculate iteratively.
    for (i=0; i<exp; i++)
        ans = ans*base%n;
        
    return ans;
}

// Pre-condition: base^2 < 2^31, n < sqrt(2^31), 0 <= exp < 2^31.
// Post-condition: base raised to the power exp mod n is returned.
int modPow(int base, int exp, int n) {
    
    // Just in case we are passed in a base that is too big.
    base = base%n;
    
    // Everything raised to the 0 power is 1.
    if (exp == 0)
        return 1;
        
    // Anything raised to the 1st power is itself.
    else if (exp == 1)
        return base;
        
    // Utlize the even powered exponent and the rules of exponentiation.
    else if (exp%2 == 0)
        return modPow(base*base%n, exp/2, n);
    
    // If we can't, then just use our regular solution.
    else
        return base*modPow(base, exp-1, n)%n; 
    
}

// Pre-condition: left and right are valid indices into the array A, and A is
//                arranged in non-descending numerical order.
// Post-condition: If the value target is stored in A in between the indices
//                 left and right, then the index in which target is stored is
//                 returned. Otherwise, -1 is returned.
int Rbinary(int target, int A[], int left, int right) {
    
    int mid;
    
    // There is no search space so target isn't found.
    if (left > right)
       return -1;
    
    // Calculate the middle of the search space.
    mid = (left + right)/2;
    
    // Target might be in the left half of the search space.
    if (target < A[mid])
        return Rbinary(target, A, left, mid-1);
        
    // We found target!
    else if (target == A[mid])
        return mid;
        
    // Otherwise, target must be in the right half of the search space.
    else
        return Rbinary(target, A, mid+1, right);
}

// Pre-condition: n is non-negative.
// Post-condition: The binary representation of n is printed.
void dectobin(int n) {
     
     // One digit to print only, so do it.
     if (n < 2) 
         printf("%d", n);
         
     // Solve the problem recursively, print out num/2 in binary, and THEN
     // print the last digit.
     else {
         dectobin(n/2);
         printf("%d", n%2);
     }
}

// Pre-condition: str is at least of length len.
// Post-condition: 1 is returned iff the characters from str[0] to
//                 str[len-1] form a palindrome.
int check(char str[], int len) {
    
    // Base case of 0 or 1 characters.
    if (len <= 1)
        return 1;
        
    // Lots going on here. We first check if the first and last letters
    // match. If they do, then we recursively call the method on the
    // string that starts at the "second" letter of the original string
    // of length 2 less than the original string. Since str is nothing
    // but a pointer, str+1 refers to the string that starts at the
    // second character of the original string.
    else
        return (str[0] == str[len-1]) && check(str+1, len-2);

}

// Pre-condition: n is non-negative and less than 47.
// Post-condition: The nth Fibonacci number is returned.
int fibonacci(int n) {
    
    // Works for F(0) and F(1).
    if (n < 2)
       return n;
       
    // This is how the numbers are defined.
    else
       return fibonacci(n-1)+fibonacci(n-2);
}

