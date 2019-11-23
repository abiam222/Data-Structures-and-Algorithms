// Arup Guha
// 6/26/07
// Example of how to implement a queue with a linked list.
#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1

// Stores one node of the linked list.
struct node {
    int data;
    struct node* next;
};

// Stores our queue.
struct queue {
    struct node* front;
    struct node* back;
};

void init(struct queue* qPtr);
int enqueue(struct queue* qPtr, int val);
int dequeue(struct queue* qPtr);
int empty(struct queue* qPtr);
int front(struct queue* qPtr);

int main() {
    
    // Allocate space for our queue and initialize it.
    struct queue* MyQueuePtr = (struct queue*)malloc(sizeof(struct queue));
    init(MyQueuePtr);
    
    // Enqueue some items.
    enqueue(MyQueuePtr, 3);
    enqueue(MyQueuePtr, 7);
    enqueue(MyQueuePtr, 4);
    
    // Try one dequeue.
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    
    // Enqueue one more item, then try several dequeues and one front.
    enqueue(MyQueuePtr, 2);
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    printf("At Front of Queue Now: %d\n", front(MyQueuePtr));
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    
    // See if we can detect an empty queue.
    printf("Is empty: %d\n", empty(MyQueuePtr));
    
    // Try enqueuing and dequeuing again to make sure that our previous
    // operations didn't "corrupt" the queue.
    enqueue(MyQueuePtr, 5);
    enqueue(MyQueuePtr, 9);
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    
    system("PAUSE");
    return 0;
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: The struct that qPtr points to will be set up to represent an
//                 empty queue.
void init(struct queue* qPtr) {
     
     // Just set both pointers to NULL!
     qPtr->front = NULL;
     qPtr->back = NULL;
}

// Pre-condition: qPtr points to a valid struct queue and val is the value to
//                enqueue into the queue pointed to by qPtr.
// Post-condition: If the operation is successful, 1 will be returned, otherwise
//                 no change will be made to the queue and 0 will be returned.
int enqueue(struct queue* qPtr, int val) {

    struct node* temp;
    
    // Allocate space for a new node to add into the queue.
    temp = (struct node*)malloc(sizeof(struct node));
    
    // This case checks to make sure our space got allocated.
    if (temp != NULL) {
             
        // Set up our node to enqueue into the back of the queue.
        temp->data = val;
        temp->next = NULL;
        
        // If the queue is NOT empty, we must set the old "last" node to point
        // to this newly created node.
        if (qPtr->back != NULL)
            qPtr->back->next = temp;
        
        // Now, we must reset the back of the queue to our newly created node.
        qPtr->back = temp;
        
        // If the queue was previously empty we must ALSO set the front of the
        // queue.
        if (qPtr->front == NULL)
            qPtr->front = temp;
        
        // Signifies a successful operation.
        return 1;
    }
    
    // No change to the queue was made because we couldn't find space for our
    // new enqueue.
    else
        return 0;   
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: If the queue pointed to by qPtr is non-empty, then the value
//                 at the front of the queue is deleted from the queue and 
//                 returned. Otherwise, -1 is returned to signify that the queue
//                 was already empty when the dequeue was attempted.
int dequeue(struct queue* qPtr) {
    
    struct node* tmp;
    int retval;
    
    // Check the empty case.
    if (qPtr->front == NULL)
        return EMPTY;
    
    // Store the front value to return.
    retval = qPtr->front->data;
        
    // Set up a temporary pointer to use to free the memory for this node.
    tmp = qPtr->front;
    
    // Make front point to the next node in the queue.
    qPtr->front = qPtr->front->next;
    
    // If deleting this node makes the queue empty, we have to change the back
    // pointer also!
    if (qPtr->front == NULL)
        qPtr->back = NULL;
        
    // Free our memory.
    free(tmp);
    
    // Return the value that just got dequeued.
    return retval;
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: returns true iff the queue pointed to by pPtr is empty.
int empty(struct queue* qPtr) {
    return qPtr->front == NULL;
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: if the queue pointed to by qPtr is non-empty, the value 
//                 stored at the front of the queue is returned. Otherwise,
//                 -1 is returned to signify that this queue is empty.
int front(struct queue* qPtr) {
    if (qPtr->front != NULL)
        return qPtr->front->data;
    else
        return EMPTY;
}
