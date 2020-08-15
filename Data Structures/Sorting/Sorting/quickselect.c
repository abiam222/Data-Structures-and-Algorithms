// Arup Guha
// 3/21/09
// Implementation of Quick-Select for COP 3502
// (Edited the posted quick-sort program.)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int quickselect(int* numbers, int low, int high, int rank);
int partition(int* vals, int low, int high);
void print(int* numbers, int length);
void swap(int *a, int *b);

const int SIZEOFLIST = 10;

int main() {
     
     srand(time(0));
     int *list;

     // Allocate space for our list.
     list = (int*)malloc(SIZEOFLIST*sizeof(int));

     // Fill it with random values.
     int i;
     for (i=0;i<SIZEOFLIST;i++) 
         list[i] = rand();

     // Print out the original values.
     print(list, SIZEOFLIST);
     
     // Get the rank of element they want.
     int rank;
     printf("Which ranked element do you want? (Please enter a 1-based number.)\n");
     scanf("%d", &rank);

     // Get the answer and print it out.
     int answer = quickselect(list,0,SIZEOFLIST-1, rank);
     printf("The %d smallest element is %d\n", rank, answer);
  
     free(list);  
     system("PAUSE");
     return 0;
}

// Prints all the numbers in the array numbers.
void print(int* numbers, int length) {

     int i;
     for (i=0;i<length;i++)
         printf("%d ", numbers[i]); 
     printf("\n");
}

// Pre-condition: low and high are valid indexes into numbers and rank is
//                in between 1 and high-low+1, inclusive.
// Post-condition: The rank smallest element within numbers[low...high]
//                 will be returned. Also, some elements within numbers may
//                 change positions.
int quickselect(int* numbers, int low, int high, int rank) {

     // Base case, this is the only number in the search range.     
     if (low == high) 
         return numbers[low];

     // Partition the array.
     int split = partition(numbers,low,high);

     // The partition element is the correct one, so return it!
     if (rank == split-low+1)
         return numbers[split];
         
     // We're looking for a smaller element than the partition element, so
     // just look to the left.
     else if (rank < split-low+1)
         return quickselect(numbers, low, split-1, rank);
     
     // We're looking for a larger element than the partition element, so
     // look to the right. Also, in our new array, the rank of the element
     // we are looking for has changed.
     else
         return quickselect(numbers, split+1, high, rank-(split-low+1));
        
}


// Pre-condition: low and high are valid indexes into values
// Post-condition: Returns the partition index such that all the values
//                 stored in vals from index low to until that index are
//                 less or equal to the value stored there and all the values
//                 after that index until index high are greater than that
//                 value.
int partition(int* vals, int low, int high) {

    int temp;
    int i, lowpos;
		
    // A base case that should never really occur.
    if (low == high) return low;
		
    // Pick a random partition element and swap it into index low.	
    i = low + rand()%(high-low+1);
    temp = vals[i];
    vals[i] = vals[low];
    vals[low] = temp;
	
	// Store the index of the partition element.
	lowpos = low;
		
	// Update our low pointer.
	low++;
		
	// Run the partition so long as the low and high counters don't cross.
	while (low <= high) {
		
		// Move the low pointer until we find a value too large for this side.
		while (low <= high && vals[low] <= vals[lowpos]) low++;
			
		// Move the high pointer until we find a value too small for this side.
		while (high >= low && vals[high] > vals[lowpos]) high--;
			
		// Now that we've identified two values on the wrong side, swap them.
		if (low < high) 
		   swap(&vals[low], &vals[high]);
	}
		
	// Swap the partition element into it's correct location.
	swap(&vals[lowpos], &vals[high]);
		
	return high; // Return the index of the partition element.
}
	
// Swaps the values pointed to by a and b.
void swap(int *a, int *b) {
     int temp = *a;
     *a = *b;
     *b = temp;     
}



