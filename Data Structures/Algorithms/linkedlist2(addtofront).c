/* Kanad Biswas

    To add elements at the front of a list and to print the contents. 
    Illustrates the use of double pointers.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
     int data;
     struct node  *next;
};

void Add_Front(struct node* *list,int d );
void PrintList( struct node *list);

int main( ) {
    
    int number = 0;
    struct node *pList=NULL;   

    // Let the user add values until they enter -1.
    while(number!= -1) {
                   
        // Get the number.           
        printf("enter data for next node\n");
        scanf("%d", &number);
  
        // Add it if it's not -1.
        if (number !=-1)
            Add_Front( &pList,number );
             
    }
   
    // Print out the resulting list.
    printf("items in linked list \n\n");
    PrintList (  pList  );
    printf("\n");
    system("PAUSE");
    return 0;
}

// Pre-conditions: list is a POINTER to the pointer that is the head of a linked list.
// Post-conditions: Adds a node storing d to the front of the list passed in and edits
//                  the pointer to the head of the list to point to this newly created
//                  node.
void Add_Front(struct node* *list,int d ) {

    // Create the new node.
    struct node * pNew=(struct node *) (malloc(sizeof(struct  node)));
    pNew->data =  d ;
    pNew->next = NULL ;
   
    // The original list is NULL, so now set the original pointer to point to
    // the new node.
    if(*list== NULL)
        *list = pNew;
   
    // In this case, *list is pointing to a non-empty list. 
    else {
    
        // Attach the new node to the rest of the list.     
        pNew->next  =  *list;
        
        // Reset the list pointer.
        *list  =  pNew ;
    }
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
