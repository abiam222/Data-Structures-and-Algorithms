// Arup Guha
// 2/26/08
// Solves the Eight Queens problem using backtracking.

#include <stdio.h>

#define SIZE 4

void solveIt();
void solveItRec(int perm[], int location, int usedList[]);
int conflict(int perm[], int location, int row);
void printSol(int perm[]);

int main() {
    solveIt();
    system("PAUSE");
    return 0;
}

// Solves the 8-Queens problem for SIZE number of queens. This is just a 
// wrapper function.
void solveIt() {
     
     int i;
     int perm[SIZE];
     int usedList[SIZE];
     
     // Initialize the permutation to hold nothing useful.
     for (i=0; i<SIZE; i++) {
         perm[i] = -1;
         usedList[i] = 0;
     }
     
     // Call the recursive function.
     solveItRec(perm, 0, usedList); 
}

// Pre-condition: perm stores a permutation of queens from index 0 to location-1
//                that is valid for a set of location number of non-conflicting
//                queens. location represents the column we are placing the next
//                queen, and usedList keeps track of the rows in which queens
//                have already been placed.
void solveItRec(int perm[], int location, int usedList[]) {
     
    int i;
    
    // We've found a solution to the problem, so print it!
    if (location == SIZE) {
        printSol(perm);
    }
    
    // Loop through possible locations for the next queen to place.
    for (i=0; i<SIZE; i++) {
        
        // Only try this row if it hasn't already been used.
        if (usedList[i] == 0) {
            
            // We can actually place this particular queen without conflict!                     
            if (!conflict(perm, location, i)) {
                                
                // Place the new queen!                
                perm[location] = i;
                
                // We've used this row now, so mark that.
                usedList[i] = 1;
                
                // Recursively solve this board.
                solveItRec(perm, location+1, usedList);
                
                // Unselect this square, so that we can continue trying to
                // fill it with the next possible choice.
                usedList[i] = 0;
            }                         
                                 
        }    
    }
     
} 

int conflict(int perm[], int location, int row) {
    
    int i;
    
    // See if the grid spot (location, row) shares a diagonal with any of
    // the previously placed queens.
    for (i=0; i<location; i++)
    
        // Diagonals have equal distance in the x and y axes.
        if (abs(location - i) == abs(perm[i] - row))
            return 1;
            
    // No conflict, so we could place a queen there.
    return 0;    
}

// Prints a two-dimensional representation of the solution stored in perm for
// the eight queens problem. 
void printSol(int perm[]) {
     
     int i,j;
          
     printf("Here is a solution:\n\n");
     
     // Loop through each row.
     for (i=0; i<SIZE; i++) {
         
         // Go through each column in row i.
         for (j=0; j<SIZE; j++) {
         
             // This means that the queen in column j resides in row i.
             if (perm[j] == i)     
                 printf("Q ");
                 
             // No queen here, so print a blank.
             else
                 printf("_ ");
         }
         printf("\n\n");
     }
}
