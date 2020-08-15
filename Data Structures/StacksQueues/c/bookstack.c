// Arup Guha
// 6/19/2012
// Written in class (COP 3502) to illustrate an implementation of a stack of books.
#include <stdio.h>
#include <stdlib.h>

// Information to store a book.
struct book {
    char title[30];
    char author[30];
    int numpages;
};

// Stores one node in a linked list of books.
struct node {
    struct book* bookPtr;
    struct node* next;
};

// Here's what we need to store a stack (LL implementation).
struct stack {
    struct node* top;
};

void init(struct stack* s);
void push(struct stack* s, struct book* b);
void print_book(struct book* b);
void make_book(struct book* b) ;
void print_stack(struct stack* s);
struct book* pop(struct stack* s);
int empty(struct stack* s);

int main() {

    struct stack mystack;
    init(&mystack);
    struct book b1, b2, b3;

    // Make three books and push them onto the stack.
    make_book(&b1);
    push(&mystack, &b1);
    print_stack(&mystack);

    make_book(&b2);
    push(&mystack, &b2);
    print_stack(&mystack);

    make_book(&b3);
    push(&mystack, &b3);
    print_stack(&mystack);

    // Pop one book off and print.
    struct book* oldbook = pop(&mystack);
    printf("Just popped: ");
    print_book(oldbook);

    // Now look at the stack.
    printf("\n");
    printf("Now the stack has:\n");
    print_stack(&mystack);

    // Check our empty function.
    if (!empty(&mystack))
        printf("Stack has stuff in it.\n");

    // Really empty the stack.
    pop(&mystack);
    pop(&mystack);

    // Check again.
    if (empty(&mystack))
        printf("Finally done reading.\n");

    return 0;
}

// Beginning stack is empty.
void init(struct stack* s) {
    s->top = NULL;
}

// Push book pointed to by b onto the stack pointed to by s.
void push(struct stack* s, struct book* b) {

    // Create the new node in our list.
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->bookPtr = b;

    // Link this to the rest of the stack.
    newnode->next = s->top;

    // Reset the top of the stack to this new item pushed on.
    s->top = newnode;
}

// For checking our work.
void print_book(struct book* b) {
    printf("%s %s %d\n", b->title, b->author, b->numpages);
}

// Most stack implementations don't have this. This is so we can easily
// see whether or not our code is working.
void print_stack(struct stack* s) {

    struct node* temp = s->top;

    // Regular linked list print. Don't move top though!
    while (temp != NULL) {
        print_book(temp->bookPtr);
        printf("\n");
        temp = temp->next;
    }
}

// Helps for testing.
void make_book(struct book* b) {
    printf("Enter the author.\n");
    scanf("%s", b->author);
    printf("Enter the title.\n");
    scanf("%s", b->title);
    printf("How long is the book?\n");
    scanf("%d", &(b->numpages));
}

// Pops off the top item off the stack pointed to by s and
// returns a pointer to it.
struct book* pop(struct stack* s) {

    // Can't pop anything off an empty stack.
    if (empty(s))
        return NULL;

    // Save the top element.
    struct book* temp = s->top->bookPtr;

    // Set the new top.
    struct node* newtop = s->top->next;

    // Now free this node. It's no longer part of the stack.
    free(s->top);

    // Reset the top.
    s->top = newtop;

    // This is the book we want to return.
    return temp;
}

// Returns 1 iff the stack pointed to by s is empty.
int empty(struct stack* s) {
    return s->top == NULL;
}
