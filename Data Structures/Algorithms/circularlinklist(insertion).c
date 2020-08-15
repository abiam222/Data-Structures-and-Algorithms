// Arup Guha
// 10/24/01 edited 2/24/04 for COP 3502 Lecture
// Linked List Example

// Edited in class on 1/28/08 to show how to insert into a circularly linked
// list.

#include <stdio.h>

// Struct used to form a linked list of integers.
struct ll {

  int data;
  struct ll *next;
};

void print(struct ll *front);

struct ll* insert_front(struct ll *front, int num);
struct ll* insert_inorder(struct ll *front, int num);
struct ll* insert_back(struct ll *front, int num);

int main() {

  struct ll *randlist=NULL;
  struct ll *inorderlist=NULL;
  
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
   
  // Test out some functions on inorderlist.
  inorderlist = insert_inorder(inorderlist, 4);
  inorderlist = insert_inorder(inorderlist, 2);
  inorderlist = insert_inorder(inorderlist, 9);
  print(inorderlist);
  inorderlist = insert_inorder(inorderlist, 1);
  inorderlist = insert_inorder(inorderlist, 7);
  print(inorderlist);
  
  system("PAUSE");
  return 0;
}

// Pre-condition: front points to the head of a circular linked list structure.
// Post-condition: each value in the list will be printed, in order.
void print(struct ll *front) {
     
  struct ll* iter = front;

  // If the list is empty just print a blank line.
  if (front == NULL) {
    printf("\n");
    return;
  }

  // Now, iterate through each element, printing.
  do {
    printf("%d ", iter->data);
    iter = iter -> next;
    
  // Here we check if the next element is back to the front, if so, we stop!
  } while (iter != front);
  
  // Go to the next line.
  printf("\n");
}


// Pre-condition: front points to the head of a circular linked list structure.
// Post-condition: a new node storing num will be inserted to the front of
//                 this list and a pointer to this node will be returned.
struct ll* insert_front(struct ll *front, int num) {

  struct ll *temp, *iter;

  // Create temp node and store the value.
  temp = (struct ll*)malloc(sizeof(struct ll));
  temp->data = num;
  
  // We are adding to an empty list.
  if (front == NULL) {
  
     // In a circular list, this means link to yourself...
     temp->next = temp;
  }
  
  // Here we add to an existing list.
  else {
      
     // Link our new node to the first element in the old list.  
     temp->next = front;
     
     // Iterate to the last element in the old list.
     iter = front;
     while (iter->next != front)
       iter = iter->next;
       
     // Now, this needs to relink to our new first element, temp. 
     iter->next = temp;
  }
       
  // Return the new front of the list.
  return temp;
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: a new node containing num will be created and added
//                 to the end of the linked listed pointed to by front.
struct ll* insert_back(struct ll *front, int num) {
       
  struct ll *temp, *iter;

  // Create temp node and store the value.
  temp = (struct ll*)malloc(sizeof(struct ll));
  temp->data = num;
  
  // We are adding to an empty list.
  if (front == NULL) {
  
     // In a circular list, this means link to yourself...
     temp->next = temp;
     
     // Return the new front of the list.
     return temp;
  }
  
  // Here we add to an existing list.
  else {
      
     // Link our new node to the first element in the old list.  
     temp->next = front;
     
     // Iterate to the last element in the old list.
     iter = front;
     while (iter->next != front)
       iter = iter->next;
       
     // Now, this needs to relink to our new first element, temp. 
     iter->next = temp;
     
     // This STAYS as the front of our list!
     return front;
  }
       
}


// Pre-condition: front points to the head of a linked list structure that
//                has its nodes arranged in ascending numerical order.
// Post-condition: a new node containing num will be created and added
//                 into the appropriate position in the linked list
//                 front and a pointer to the front of this new linked
//                 list will be returned.
struct ll* insert_inorder(struct ll *front, int num) {

  struct ll *temp;
  struct ll *iter;
  struct ll *savelink;

  // Take care of the case where we insert into the front of the list.
  if (front == NULL || num < front->data) {
    return insert_front(front, num);
  }
  
  // Create the new node.
  temp = (struct ll*)malloc(sizeof(struct ll));
  temp->data = num;
  temp->next = NULL;

  // Start iter at the front of the linked list.
  iter = front;

  // Use iter to iterate to the right spot to insert temp.
  // We stop if the node after iter is pointing back to the front of the list.
  while (iter->next != front && iter->next->data < num)
    iter = iter->next;

  // Save the node to patch to.
  savelink = iter->next;

  // Insert temp.
  iter->next = temp;
  temp->next = savelink;
  
  // Return a pointer to the front of the list.
  return front;
}
