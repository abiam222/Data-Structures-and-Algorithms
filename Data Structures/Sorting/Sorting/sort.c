// Arup Guha & Kanad Biswas
// 5/17/07
// A slight adaptation of the code shown in COP 3502 on 5/16/07
// A full program has been created and some print statements have been added
// to aid the understanding of both the Binary Search and the Selection Sort.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NOT_FOUND -1

int LinearSearch(int A[], int n, int TARGET);
int BinarySearch(int A[], int n, int TARGET);
void printArray(int A[], int n);
void randArray(int A[], int size, int maxval);
void selectionSort(int A[], int n);
void insertionSort(int A[], int n);
void bubbleSort(int A[], int n);
void swap(int *a, int *b);

int main() {
     
    int myArray[10], val, answer;
    srand(time(0));
    
    // Fill the array randomly, then sort. 
    randArray(myArray, 10, 100);
    
    // Print out the original contents.
    printf("Here are the values in your array: ");
    printArray(myArray, 10);
    
    bubbleSort(myArray, 10);
        
    // Print out the contents after the sort.
    printf("Here are the values in your array: ");
    printArray(myArray, 10);
    
    // Ask the user for an element for which to search.
    printf("For which element would you like to search?");
    scanf("%d", &val);
    
    // Perform a binary search.
    answer = BinarySearch(myArray, 10, val);
    
    // Print out the results!
    if (answer != NOT_FOUND)
       printf("Your value was found in index %d of the array.\n", answer);
    else
       printf("Your value wasn't found.\n");
        
    system("PAUSE");
    return 0;
}

// Pre-condition: A is an array of size greater than or equal to n.
// Post-condition: If TARGET is stored in A in an index in between 0 and n-1,
//                 then an index in which TARGET is stored is returned. 
//                 Otherwise, -1 is returned.
int LinearSearch(int A[], int n, int TARGET) {
    
    int i;
    
    // Try to find TARGET in each array slot.
    for (i=0; i<n; i++) {
        if (A[i] == TARGET)
           return i;
    }
    return NOT_FOUND; // We never found TARGET.
}

// Pre-condition: A is an array sorted in ascending order of size greater than
//                or equal to n.
// Post-condition: If TARGET is stored in A in an index in between 0 and n-1,
//                 then an index in which TARGET is stored is returned. 
//                 Otherwise, -1 is returned.
int BinarySearch(int A[], int n, int TARGET) {
 
    // Set the left and rightmost boundaries in which to search.   
    int L = 0, Mid, R = n-1;
 
    printf("We are searching for %d.\n", TARGET);
    printf("Here is the array: ");
    printArray(A, n);
    
    // Keep on looking so long as there is a search space.
    while (L <= R) {
    
    
        // Find the element in the middle of the search space.
        Mid = (L+R)/2;
    
        printf("Search between indexes %d and %d.\n", L, R);
        printf("Looking at middle value A[%d]=%d.\n",Mid, A[Mid]);
            
        // We got a direct hit.
        if (TARGET == A[Mid]) {
            printf("Found it!\n");
            return Mid;
        }
        
        // We know that if TARGET is in A, then it will be located
        // to the right of A[Mid].
        else if (TARGET > A[Mid]) {
            
            L = Mid + 1;
            printf("Our value is bigger than %d, so we will change our left index to %d.\n",A[Mid],L);
        }
        
        // We know that if TARGET is in A, then it will be located
        // to the left of A[Mid].
        else {
            R = Mid - 1;
            printf("Our value is smaller than %d, so we will change our right index to %d.\n",A[Mid],R);
        }
        printf("\n");
    }
    
    return NOT_FOUND;
}

// Pre-condition: A is an array of size greater than or equal to n.
// Post-condition: The contents of A from index 0 to index n-1 are printed
//                 to the screen separated by spaces followed by a newline.
void printArray(int A[], int n) {
     
     int i;
     // Go through each array element one by one.
     for (i = 0; i<n; i++)
         printf("%4d", A[i]);
     printf("\n");
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

// Pre-condition: A is an array of size greater than or equal to n.
// Post-condition: Elements in A from index 0 to index n-1 will be
//                 rearranged in non-decreasing order.
void selectionSort(int A[], int n) {
     
     int cur, j, smallest;
     
     // Loop through each index of the array. At each loop iteration
     // we will be placing the smallest unplaced item left in this
     // location of the array.
     for (cur = 0; cur <n; cur++) {
         
         // At first, the smallest unplaced element is stored in the
         //index cur.
         smallest = cur;
         
         // Look through the other indices to find a value SMALLER than
         // list[cur]. If we find one, update WHERE it is located.
         for (j=cur+1; j<n; j++)
         
             // We found a smaller element!
             if (A[j] < A[smallest])
                 smallest = j;
         
         // Now, swap the smallest element left, list[smallest] 
         // into it's correctly sorted location, list[cur].
         swap(&A[cur], &A[smallest]);
         
         printf("Here is the array now: ");
         printArray(A, n);
     }
     printf("\n");
}

// Sorts the first length elements of vals in ascending order.
void insertionSort(int A[], int n) {

     int i,j;

     // Loop through each element to insert.
     for (i=1; i<n; i++) {

         j=i;

         // Continue swapping the element until it hits the correct location.
         while (j > 0 && A[j] < A[j-1]) {
               swap(A+j, A+j-1); // Example of pointer arithmetic.
               j--; // Don't forget to change j!!!
         }
         
         printf("Here is the array now: ");
         printArray(A, n);
     }
}

// Sorts the first length elements of vals in ascending order.
void bubbleSort(int A[], int n) {

     int i,j;

     // Loop through each element to insert.
     for (i=n-2; i>=0; i--) {

         for (j=0; j<=i; j++) 
             if (A[j] > A[j+1])
                swap(&A[j], &A[j+1]);
         
         printf("Here is the array now: ");
         printArray(A, n);
     }
}

// Swaps the integers pointed to by a and b.
void swap(int *a, int *b) {
     int temp = *a;
     *a = *b;
     *b = temp;
}
