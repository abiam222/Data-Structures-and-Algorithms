// Arup Guha
// 10/24/01 edited 2/24/04 for COP 3502 Lecture
// Linked List Example

// Edited on 6/1/07 to include an example from Recitation Sheet #3 for COP 3502

// Edited on 2/3/09 to include two recursive functions: delete and reverse.

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

struct ll* delete(struct ll *front, int num);
struct ll* deleteRec(struct ll *front, int num); /*** JUST ADDED!!! ***/

struct ll* reverseRec(struct ll *front); /*** JUST ADDED!!! ***/
struct ll* reverse(struct ll *front);
struct ll* concat(struct ll *first, struct ll *second);
struct ll* maxlist(struct ll *first, struct ll *second);

struct ll* Add(struct ll* A, struct ll* B);
struct ll* RecAdd(struct ll* A, struct ll* B);

void dellist(struct ll *p);

int main() {

  struct ll *randlist=NULL;
  struct ll *inorderlist=NULL;
  struct ll *maximums=NULL;
  struct ll *final=NULL;
  struct ll *A = NULL, *B = NULL, *C, *D;
  
  // Test out some functions on randlist.
  randlist = insert_front(randlist,5);
  print(randlist);
  randlist = insert_back(randlist,2);
  print(randlist);
  randlist = delete(randlist, 3);
  print(randlist);
  randlist = insert_front(randlist, 1);
  print(randlist);
  randlist = delete(randlist, 2);
  print(randlist);
  randlist = insert_front(randlist, 6);
  randlist = insert_front(randlist, 9);
  randlist = insert_front(randlist, 8);
  
  // Create a new list that is the reverse of the old.
  struct ll* randlist2 = reverse(randlist);
  print(randlist);
  print(randlist2);
  
  // Now, reverse the original list.
  randlist = reverseRec(randlist);
  print(randlist);
  
   
  // Test out some functions on inorderlist.
  inorderlist = insert_inorder(inorderlist, 4);
  inorderlist = insert_inorder(inorderlist, 2);
  inorderlist = insert_inorder(inorderlist, 9);
  print(inorderlist);
  inorderlist = insert_inorder(inorderlist, 1);
  inorderlist = insert_inorder(inorderlist, 7);
  inorderlist = deleteRec(inorderlist, 4);
  print(inorderlist);
  inorderlist = deleteRec(inorderlist, 1);
  print(inorderlist);
  inorderlist = deleteRec(inorderlist, 9);
  print(inorderlist);

  // Create a new list with all the maximums of the two above.
  maximums = maxlist(randlist, inorderlist);
  print(maximums);

  // Concatenate the two lists above.
  final = concat(randlist, inorderlist);
  print(final);

  // Testing the Add and RecAdd functions.
  A = insert_front(A, 2);
  A = insert_front(A, 7);
  A = insert_front(A, 5);
  A = insert_front(A, 15);
  B = insert_front(B, 12);
  B = insert_front(B, 9);
  B = insert_front(B, 4);
  B = insert_front(B, 17);
  C = Add(A, B);
  print(C);
  D = RecAdd(A, B);
  print(D);
  
  system("PAUSE");
  return 0;
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: each value in the list will be printed, in order.
void print(struct ll *front) {

  while (front !=NULL) {
    printf("%d ", front->data);
    front = front -> next;
  }
  printf("\n");
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: if val is stored in the list, 1 will be returned,
//                 otherwise 0 will be.
int search(struct ll *front, int val) {
  while (front != NULL) {
 
    if (front->data == val)
      return 1;
    front = front->next;
  }
  return 0;

}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: a new node storing num will be inserted to the front of
//                 this list and a pointer to this node will be returned.
struct ll* insert_front(struct ll *front, int num) {

  struct ll *temp;

  // Create temp node and link it to front.
  temp = (struct ll*)malloc(sizeof(struct ll));
  temp->data = num;
  temp->next = front;

  // Return the new front of the list.
  return temp;
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: a new node containing num will be created and added
//                 to the end of the linked listed pointed to by front.
struct ll* insert_back(struct ll *front, int num) {

  struct ll *temp;
  struct ll *begin;

  // Create the new node.
  temp = (struct ll*)malloc(sizeof(struct ll));
  temp->data = num;
  temp->next = NULL;

  // Store front of the linked list
  begin = front;

  // Take care of case inserting into an empty list.
  if (front == NULL)
    return temp;

  // Use front to iterate to the right spot to insert temp.
  while (front->next != NULL)
    front = front->next;

  // Insert temp.
  front->next = temp;
  
  // Return a pointer to the front of the list.
  return begin;
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

  // Create the new node.
  temp = (struct ll*)malloc(sizeof(struct ll));
  temp->data = num;
  temp->next = NULL;

  // Take care of case inserting into an empty list.
  if (front == NULL)
    return temp;

  if (num < front->data) {
    temp->next = front;
    return temp;
  }

  // Start iter at the front of the linked list.
  iter = front;

  // Use front to iterate to the right spot to insert temp.
  while (iter->next != NULL && iter->next->data < num)
    iter = iter->next;

  // Save the node to patch to.
  savelink = iter->next;

  // Insert temp.
  iter->next = temp;
  temp->next = savelink;
  
  // Return a pointer to the front of the list.
  return front;
}


// Pre-condition: front points to the head of a linked list structure.
// Post-condition: The first node that contains the value num will be
//                 removed from the list. A pointer to the front of the
//                 list will be returned. If no such value is stored,
//                 the list will remain unchanged.
struct ll* delete(struct ll *front, int num) {

  struct ll *temp, *del;
  temp = front;

  // Only need to delete if the list is not null.
  if (temp != NULL) {
    
    // Take care of the case where first node needs to be deleted.
    if (temp->data == num) {
      del = temp -> next;
      free(temp);
      return del;
    }
    // Otherwise, loop until you find the node to delete and do so.
    while (temp->next != NULL) {
      if (temp ->next->data == num) {
        del = temp -> next;
        temp->next = temp ->next->next;
        free(del);   
        return front;
      }
      temp = temp -> next;
    }
    
  }
  return front;
}
// Pre-condition: front points to the head of a linked list structure.
// Post-condition: The first node that contains the value num will be
//                 removed from the list. A pointer to the front of the
//                 list will be returned. If no such value is stored,
//                 the list will remain unchanged.
struct ll* deleteRec(struct ll *front, int num) {

  // No item in list, no delete to do.
  if (front == NULL)
    return NULL;
    
  // Deleting the first item.
  if (front->data == num) {
    
    // This is the list to return.
    struct ll* retval = front->next;
    
    // Need to free the deleted node.
    free(front);
    
    return retval;
  } 
  
  // We can try to delete num from the rest of the list.
  struct ll* rest = delete(front->next, num);
  
  // Attach the rest of the list to what is returned from the recursive call.
  front->next = rest;
  
  return front; // This is unchanged.
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: A pointer will be returned to a newly formed list
//                 that contains all the elements of the old list,
//                 reversed.
struct ll* reverseRec(struct ll *front) {

  struct ll *temp;

  // Easy cases.
  if (front == NULL || front->next == NULL)
    return front;

  // Reverse the rest of the list, so if we had 1,2,3,4, temp->4,3,2.
  // Keep in mind that front is still pointing to 2 =)
  temp = reverseRec(front->next);
  
  // This is the bizarre line. front->next is 2, and we want to change 2's
  // next to 1 (or front).
  front->next->next = front;
  
  // This is important! Our new last node must point to NULL!!!
  front->next = NULL;

  return temp;

}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: A pointer will be returned to a newly formed list
//                 that contains all the elements of the old list,
//                 reversed.
struct ll* reverse(struct ll *front) {

  struct ll *temp;

  if (front == NULL)
    return front;

  // Store the front element of the linked list in a node.
  temp = (struct ll*)malloc(sizeof(struct ll));
  temp -> data = front -> data;
  temp -> next = NULL;

  // Recursively reverse the rest of the list and concatenate the
  // first element of the original list to this reversed list.
  return concat(reverse(front->next), temp);

}

// Pre-condition: first and second point to the head of a linked list
//                structure
// Post-condition: The last element in first will be linked to the first
//                 element in second. Then a pointer to the beginning of
//                 this concatenated list is returned. Note that the
//                 original lists will not truly exist after this
//                 operation.
struct ll* concat(struct ll *first, struct ll *second) {

  struct ll* temp;

  // Case where the first list is empty.
  if (first == NULL)
    return second;

  else {

    // Iterate to the end of the first list.
    temp = first;
    while (temp -> next != NULL)
      temp = temp -> next;

    // Attach this list to the beginning of the second.
    temp -> next = second; 
    return first;    
  }
  
}

// Pre-condition: first and second point to the head of a linked list
//                structure
// Post-condition: A new list will be created that stores the maximum 
//                 value in either list at each position. Thus, the kth
//                 value in the newly created list will be the maximum
//                 of the kth value in the first list and the kth value
//                 in the second list. If both values don't exist, the
//                 one that does will be taken. The length of this
//                 created list will be the maximum of the lengths of
//                 first and second. A pointer to this list will be 
//                 returned.
struct ll* maxlist(struct ll *first, struct ll *second) {

  struct ll *max, *temp;
  int tempmax;
  max = NULL;

  // Continue as long as either list has an element.
  while (first != NULL || second != NULL) {

    // Take care of the case where both lists still have elements.
    if ((first != NULL) && (second != NULL)) {

      // Find the maximum value stored in either element.
      tempmax = first -> data;
      if (second -> data > first -> data)
        tempmax = second -> data;

      // Advance both first and second.
      first = first -> next;
      second = second -> next;
    }

    // Automatically take the element stored in the first list.
    else if (first != NULL) {
      tempmax = first -> data;
      first = first -> next;
    }

    // Automatically take the element stored in the second list.
    else if (second != NULL) {
      tempmax = second -> data;
      second = second -> next;
    }

    // Create the new element and concatenate it to the end of the
    // already formed list.
    temp = (struct ll*)malloc(sizeof(struct ll));
    temp -> data = tempmax;
    temp -> next = NULL;
    max = concat(max, temp);
  }
 
  return max;
}

// Pre-condition: p points to a linked list.
// Post-condition: All the memory for the linked list pointed to by p is
//                 freed for use.
void dellist(struct ll *p) {

  struct ll *temp;

  // Recursively free each element in the list.
  if (p !=NULL) {
    temp = p -> next;
    dellist(temp);
    free(p);
  }
}

// Pre-condition: The linked lists pointed to by A and B are of the same length.
// Post-condition: A pointer to a new linked list will be returned where the
//                 new list stores the sums of the corresponding values of the
//                 two input lists.
struct ll* Add(struct ll* A, struct ll* B) {

	struct ll *curA = A, *curB = B, *curC, *C = NULL;
	struct ll *last;

    // Loop until list A is done. We don't check for B because it's the same length.
    while (curA != NULL) {

        // Create a new node that will store the sum of the two appropriate nodes.
        curC = (struct ll*)malloc(sizeof(struct ll));
        curC->data = curA->data + curB->data;

        // If this is the first node, we need to initialize C to point to it.
        if (C == NULL)
              C = curC;
        
        // In this case, we must attach the last node of the list we've constructed
        // so far to the newly created node.
        else
              last->next = curC;

        // Go to the next nodes in both A and B, and reset the last node of our list.
		curA = curA ->next;
		curB = curB ->next;
        last = curC;
	}

    // As long as we're not in the trivial case, we must set the last pointer of
    // the last node of the list to return to NULL.
    if (A != NULL) 
         curC->next = NULL;

    // Return the pointer to our new list.
	return C;
}

// Pre-condition: The linked lists pointed to by A and B are of the same length.
// Post-condition: A pointer to a new linked list will be returned where the
//                 new list stores the sums of the corresponding values of the
//                 two input lists.
struct ll* RecAdd(struct ll* A, struct ll* B) {

    struct ll* tmp;
    
    // Base case: There's no nodes to create.
	if (A == NULL) return NULL;
	
	// Create the first node of our list to return.
	tmp = (struct ll*)malloc(sizeof(struct ll));
    tmp->data = A->data + B->data;

    // Attach it to the rest of the list we must return. We can compute this
    // rest of the list recursively.
    tmp->next = RecAdd(A->next, B->next);
    
    // Return a pointer to the front of our newly created list.
    return tmp;
}


