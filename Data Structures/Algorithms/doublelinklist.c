// Arup Guha
// 10/24/01 edited 2/24/04 for COP 3502 Lecture
// Linked List Example

// Edited on 1/28/08 to illustrate inserting into a doubly linked list.

#include <stdio.h>

// Struct used to form a doubly linked list of integers.
struct dll {

  int data;
  struct dll *next;
  struct dll *prev;
};

void print(struct dll *front);
struct dll* insert_front(struct dll *front, int num);
struct dll* insert_back(struct dll *front, int num);

int main() {

  struct dll *randlist=NULL;
  
  // Test out some functions on randlist.
  randlist = insert_front(randlist,5);
  print(randlist);
  randlist = insert_back(randlist,2);
  print(randlist);
  
  randlist = insert_front(randlist, 1);
  print(randlist);
  randlist = insert_front(randlist, 6);
  randlist = insert_front(randlist, 9);
  randlist = insert_front(randlist, 8);
  randlist = insert_back(randlist, 7);
  print(randlist);
  
  system("PAUSE");
  return 0;
}

// Pre-condition: front points to the head of a doubly linked list structure.
// Post-condition: each value in the list will be printed, in order.
void print(struct dll *front) {

  while (front != NULL) {
    printf("%d ", front->data);
    front = front -> next;
  }
  printf("\n");
}


// Pre-condition: front points to the head of a doubly linked list structure.
// Post-condition: a new node storing num will be inserted to the front of
//                 this list and a pointer to this node will be returned.
struct dll* insert_front(struct dll *front, int num) {

  struct dll *temp;

  // Create temp node and link it to front.
  temp = (struct dll*)malloc(sizeof(struct dll));
  temp->data = num;
  temp->next = front;
  
  // Nothing comes before this node.
  temp->prev = NULL;
  
  // If front exists, we have to link its previous link to temp.
  if (front != NULL)
    front->prev = temp;

  // Return the new front of the list.
  return temp;
}

// Pre-condition: front points to the head of a doubly linked list structure.
// Post-condition: a new node containing num will be created and added
//                 to the end of the linked listed pointed to by front.
struct dll* insert_back(struct dll *front, int num) {
       
  struct dll *temp, *iter;

  // Create temp node and store the value.
  temp = (struct dll*)malloc(sizeof(struct dll));
  temp->data = num;
  temp->next = NULL;
  
  // We are adding to an empty list.
  if (front == NULL) {
  
     // In a doubly linked list, this means the previous pointer is to NULL.
     temp->prev = NULL;
     
     // Return the new front of the list.
     return temp;
  }
  
  // Here we add to an existing list.
  else {
     
     // Iterate to the last element in the old list.
     iter = front;
     while (iter->next != NULL)
       iter = iter->next;
       
     // Now, this needs to relink to our new first element, temp. 
     iter->next = temp;
     temp->prev = iter;
     
     // This STAYS as the front of our list!
     return front;
  }
       
}

