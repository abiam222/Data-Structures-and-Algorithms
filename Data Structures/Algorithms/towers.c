// Arup Guha
// 6/11/07
// Demonstration of the Towers of Hanoi solution.

#include <stdio.h>

void towers(int n, int start, int end);

int main() {

    // This just tests a single function call.    
    towers(5, 1, 3);
    system("PAUSE");
    return 0;
}

// Pre-condition: n is non-negative, start and end are distinct and in between
//                1 and 3, inclusive.
// Post-condition: The sequence of moves to solve the Towers of Hanoi problem
//                 with n disks to be moved in between tower number start and
//                 tower number end are printed out. The tower numbers are 
//                 assumed to be 1, 2 and 3.
void towers(int n, int start, int end) {
 
    // Compute the "middle" tower number.
    int mid = 6 - start - end;
     
    // We only have work to do if there is a positive number of disks.
    if (n > 0) {
     
        // Move all but the bottom disk to the "middle" tower.
        towers(n-1, start, mid);
        
        // Now, move that bottom disk to the place it needs to be.
        printf("Move disk #%d from tower #%d to tower #%d.\n", n, start, end);
        
        // Move the rest of the disks that are now sitting on the middle tower
        // over to the ending tower on top of the bottom disk.
        towers(n-1, mid, end);
    }
}    
