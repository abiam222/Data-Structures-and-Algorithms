/* Kanad Biswas

   To create a linked list by adding elements at the rear, and to print the list
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* Addrear(struct node *list, int d) ;
void PrintList(struct node *list);

int main( ) {
  
    int number = 0;
    struct node *pList=NULL;   

    // Let users add number into list until they enter a -1.
    while(number!= -1) {
                    
        // Get the next number.
        printf("enter data for next node\n");
        scanf("%d", &number);
  
        // Add it if it's not -1.
        if (number !=-1) {
            pList = Addrear( pList, number );
        }
    }
   
    // Print everything out.
    printf("items in linked list\n");
    PrintList (pList);
    system("PAUSE");
    return 1;
}


// Pre-condition: list points to the head of a linked list.
// Post-condition: returns a pointer to the new head of a linked list that
//                 adds a node with d to the end of the original list.
struct node* Addrear(struct node *list, int d) {
  
    struct node *pNew = NULL;
    struct node *current = NULL;

    // Create the new node.
    pNew = (struct node*)malloc(sizeof(struct node));
    pNew->data = d;
    pNew->next = NULL;
        
    // Store front of the linked list
    current = list;
              
    // if list is empty then this becomes the first node.
    if (list == NULL)
        return pNew;

    // Iterate so that current points to the last node in the list.
    while (current ->next != NULL)
        current = current->next;

    // Link the last node to the new node.
    current->next = pNew;

    // Return a pointer to the edited list.
    return list;
}

// Pre-condition: list points to the head of a linked list.
// Post-condition: Prints out each item in the list pointed to by list, in order.
void PrintList( struct node *list) {
     
    // Iterate through each item and print it!
    while (list != NULL) {
        printf("-->%d", list->data);
        list = list->next;
    }
    
    printf("\n");
}

