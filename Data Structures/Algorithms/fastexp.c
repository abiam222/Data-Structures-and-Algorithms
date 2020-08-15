// Arup Guha
// 5/29/2012
// Written in COP 3502 to illustrate Fast Modular Exponentiation

#include <stdio.h>
#include <time.h>

#define P 101
#define BASE 65

int myexp(int base, int exp);
int mymodexp(int base, int exp, int mod);
int recexp(int base, int exp);
int recmodexp(int base, int exp, int mod);
int fastmodexp(int base, int exp, int mod);

int main() {

    int start = time(0);
    printf("ans slow = %d\n",   mymodexp(BASE, 1000000007, P));
    int end1 = time(0);
    printf("ans fast = %d\n", fastmodexp(BASE, 1000000007, P));
    int end2 = time(0);
    printf("first call took %d\n", end1-start);
    printf("sec call took %d\n", end2 - end1);
    return 0;

}

// Regular iterative exponentiation
int myexp(int base, int exp) {

    int ans = 1;
    int i;

    for (i=0; i<exp; i++)
        ans = ans*base;

    return ans;

}

// Iterative Modular Exponentiation
int mymodexp(int base, int exp, int mod) {

    int ans = 1;
    int i;

    // It's safe to mod at each step.
    for (i=0; i<exp; i++)
        ans = (ans*base) % mod;

    return ans;

}

// Recursive Exponentiation
int recexp(int base, int exp) {

    if (exp == 0)
        return 1;
    else
        return base*recexp(base, exp-1);
}

// Recursive Modular Exponentiation
int recmodexp(int base, int exp, int mod) {

    if (exp == 0)
        return 1;
    else
        return (base*recmodexp(base, exp-1, mod))%mod;
}

// Fast Modular Exponentiation
int fastmodexp(int base, int exp, int mod) {

    if (exp == 0)
        return 1;

    // The key time savings is here! We can reuse the value
    // mysqrt without redoing the work to recalculate it.
    else if (exp%2 == 0) {
        int mysqrt = fastmodexp(base, exp/2, mod);
        return (mysqrt*mysqrt)%mod;
    }

    // This case runs at most every other time.
    else
        return (base*fastmodexp(base, exp-1, mod))%mod;
}
