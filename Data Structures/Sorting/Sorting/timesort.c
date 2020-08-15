// Arup Guha
// 2/9/09
// Short example to illustrate how to time a function and utilize it to
// predict run-times for different input sizes.

#include <stdio.h>

#define MAXVAL 1000000

void randArray(int A[], int size, int maxval);
void bubbleSort(int A[], int n);
void swap(int *a, int *b);

int main() {
    
    // Different sizes to test the sort.
    int sizes[] = {100, 1000, 10000, 20000, 40000, 50000, 100000};
    
    int* values; 
    int i;
    
    // Loop through trying each size.
    for (i=0; i<7; i++) {
        
        // Allocate the space for the array and fill it.
        values = (int*)malloc(sizeof(int)*sizes[i]);    
        randArray(values, sizes[i], MAXVAL);
    
        // Time and sort.
        int start = time(0);
        bubbleSort(values, sizes[i]);
        int end = time(0);
        
        // Print out the time and free the array.
        printf("Sorting %d values took %d seconds.\n", sizes[i], end-start);
        free(values);
    }
    
    system("PAUSE");
    return 0;
}

// Pre-condition: A is an array of size greater than or equal to size and
//                maxval is positive.
// Post-condition: A is filled with random integers in the range [1,maxval] 
//                 from index 0 to index size-1.
void randArray(int A[], int size, int maxval) {

     int i;
     // Fill each array slot in question with a random value in the designated range.     
     for (i=0; i<size; i++) 
         A[i] = rand()%maxval + 1;
}

// Sorts the first length elements of vals in ascending order.
void bubbleSort(int A[], int n) {

     int i,j;

     // Loop through each element to insert.
     for (i=n-2; i>=0; i--) {

         for (j=0; j<=i; j++) 
             if (A[j] > A[j+1])
                swap(&A[j], &A[j+1]);
     }
}

// Swaps the integers pointed to by a and b.
void swap(int *a, int *b) {
     int temp = *a;
     *a = *b;
     *b = temp;
}
