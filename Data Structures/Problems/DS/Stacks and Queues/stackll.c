// Arup Guha
// 11/7/01
// Small stack implementation
#include <stdio.h>

// Struct used to form a stack of integers.
struct stack {
  int data;
  struct stack *next;
};

int push(struct stack **front, int num);
struct stack* pop(struct stack **front);
int empty(struct stack *front);
int top(struct stack *front);
void init(struct stack **front);

int main() {
   
  struct stack *stack1, *temp;
  int tempval;

  init(&stack1);

  if (!push(&stack1, 3))
    printf("Push failed.\n");
  if (!push(&stack1, 5))
    printf("Push failed.\n");

  temp = pop(&stack1);
  if (temp !=NULL)  
    printf("Pop stack = %d\n", temp->data);

  if (empty(stack1))
    printf("Empty stack\n");
  else
    printf("Contains elements.\n");

  tempval = top(stack1);
  if (tempval != -1)
    printf("Top of Stack = %d\n", tempval);

  temp = pop(&stack1);
  temp = pop(&stack1);
  if (temp != NULL)
    printf("Top of Stack = %d\n", temp->data);
  else
    printf("Tried to pop an empty stack.\n");

  return 0;
}

void init(struct stack **front) {
  *front = NULL;
}

// Pre-condition: front points to the top of the stack.
// Post-condition: a new node storing num will be pushed on top of the
//                 stack if memory is available. In this case a 1 is 
//                 returned. If no memory is found, no push is executed
//                 and a 0 is returned.

int push(struct stack **front, int num) {

  struct stack *temp;
  // Create temp node and link it to front.
  temp = (struct stack *)malloc(sizeof(struct stack));
  
  if (temp != NULL) {
    temp->data = num;
    temp->next = *front;
    *front = temp;
    return 1;
  }
  else
    return 0;
}

// Pre-condition: front points to the top of a stack
// Post-condition: A pointer to a node storing the top value from the
//                 stack will be returned. If no value exists, the pointer
//                 returned will be pointing to null.

struct stack* pop(struct stack **front) {

  struct stack *temp;    
  temp = NULL;

  if (*front != NULL) {  
    temp = (*front);
    *front = (*front)->next;
    temp -> next = NULL;
  }
  return temp;  
}

// Pre-condition: front points to the top of a stack
// Post-condition: returns true if the stack is empty, false otherwise.
int empty(struct stack *front) {
  if (front == NULL)
    return 1;
  else
    return 0;
}

// Pre-condition: front points to the top of a stack
// Post-condition: returns the value stored at the top of the stack if the
//                 stack is non-empty, or -1 otherwise.
int top(struct stack *front) {

  if (front != NULL) {
    return front->data;
  }
  else
    return -1;
}
