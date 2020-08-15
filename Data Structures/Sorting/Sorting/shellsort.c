// Arup Guha
// 4/7/2011
// Illustrates a version of shell sort

#include <stdio.h>

#define 	SIZE	1000000
#define     FACTOR  2.2
#define     MAXVAL  100000000

#define     DEBUG   0

void Print_Array(int values[], int length);
void Fill_Array(int values[], int length, int max);
int Is_Sorted(int values[], int length);

void Shell_Sort(int values[], int length);
void All_Insert_Sorts(int values[], int length, int gap);
void Insert_Sort(int values[], int length, int gap, int start);
void swap(int *ptrA, int *ptrB);

int main() {
    
    int *val;
    val = (int*)(malloc(sizeof(int)*SIZE));
    srand(time(NULL));

    // Let's look at the random array values.
    Fill_Array(val, SIZE, MAXVAL);
    if (DEBUG) Print_Array(val, SIZE);
    
    int start = time(0);

    // And now, the sorted ones.
    Shell_Sort(val, SIZE);
    if (DEBUG) Print_Array(val, SIZE);

    int end = time(0);
    
    // Check if it's sorted.
    if (Is_Sorted(val, SIZE))
        printf("Sorted correctly in %d seconds.\n", end-start);
        
    free(val);
    system("PAUSE");
  
    return 0;    
    
    
    
    
}

void Shell_Sort(int values[], int length) {
    
    // Reduce the gap in each successive sort by the given factor.
    int gap = (int)length/FACTOR;
    while (gap > 1) {
        All_Insert_Sorts(values, length, gap);
        gap = (int)gap/FACTOR;
    }
    
    // Guarantees the whole list is sorted!!!
    All_Insert_Sorts(values, length, 1);
}

void All_Insert_Sorts(int values[], int length, int gap) {
    
    // Run an insertion sort on each of gap number of sets of numbers.
    int i;
    for (i=0; i<gap; i++)
        Insert_Sort(values, length, gap, i);
}   

void Insert_Sort(int values[], int length, int gap, int start) {
    
    int i;
    
    // Go through each item to insert.
    for (i=start+gap; i<length; i+=gap) {
        
        // Insert this item into place.
        int position = i;
        while (position > start && values[position] < values[position-gap]) {
            swap(values+position, values+position-gap);
            position -= gap;
        }
    }    
}

// Swaps the variables pointed to by ptrA and ptrB.
void swap(int *ptrA, int *ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}


// Pre-condition: length is the length of the array values.
// Post-condition: all the numbers stored in values will be printed out,
//                 from the values stored in index 0 to index length-1.
void Print_Array(int values[], int length) {

    int i;
    for (i=0; i<length; i++)
        printf("%d ", values[i]);
    printf("\n");
}

// Pre-condition: length is the length of the array values and max<32767.
// Post-condition: the array values will be initialized with random values
//                 in between 1 and max.
void Fill_Array(int values[], int length, int max) {

    int i;
    for (i=0; i<length; i++)
        values[i] = (rand()<<15 + rand())%max + 1;
}

// Pre-condition: values is of length length.
// Post-condition: Returns 1, iff values is in non-decreasing order.
int Is_Sorted(int values[], int length) {
    
    int i;
    
    // Return false if any adjacent pair is out of order.
    for (i=0; i<length-1; i++)
        if (values[i] > values[i+1])
            return 0;
            
    return 1;
}
