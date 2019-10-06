// Arup Guha
// 6/26/07
// Example of how to implement a queue with an array.
#include <stdio.h>

#define EMPTY -1
#define INIT_SIZE 10

// Stores our queue.
struct queue {
    int* elements;
    int front;
    int numElements;
    int queueSize;
};

void init(struct queue* qPtr);
int enqueue(struct queue* qPtr, int val);
int dequeue(struct queue* qPtr);
int empty(struct queue* qPtr);
int front(struct queue* qPtr);

int main() {
     
     int i;
     
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
    
    // Try lots of enqueues to test the dynamic capability of the queue.
    for (i=30; i<60; i++)
        enqueue(MyQueuePtr, i);
        
    // Dequeue everything.
    while (!empty(MyQueuePtr))
        printf("Dequeue %d\n", dequeue(MyQueuePtr));
    
    system("PAUSE");
    return 0;
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: The struct that qPtr points to will be set up to represent an
//                 empty queue.
void init(struct queue* qPtr) {
     
     // The front index is 0, as is the number of elements.
     qPtr->elements = (int*)malloc(sizeof(int)*INIT_SIZE);
     qPtr->front = 0;
     qPtr->numElements = 0;
     qPtr->queueSize = INIT_SIZE;
}

// Pre-condition: qPtr points to a valid struct queue and val is the value to
//                enqueue into the queue pointed to by qPtr.
// Post-condition: If the operation is successful, 1 will be returned, otherwise
//                 no change will be made to the queue and 0 will be returned.

// Note: Right now, I don't know how to detect that the realloc failed, so 0
//       does not get returned.

int enqueue(struct queue* qPtr, int val) {

    int i;
    
    // Regular case where our queue isn't full.
    if (qPtr->numElements != qPtr->queueSize) {
             
        // Enqueue the current element. Note the use of mod for the wraparound
        // case. Edit the number of elements.
        qPtr->elements[(qPtr->front+qPtr->numElements)%qPtr->queueSize] = val;
        (qPtr->numElements)++;
         
        // Signifies a successful operation.
        return 1;
    }
    
    // Case where the queue is full, we must find more space before we enqueue.
    else {
         
         // Allocate more space!
         realloc(qPtr->elements, (qPtr->queueSize)*sizeof(int)*2);
         
         // Copy all of the items that are stored "before" front and copy them
         // into their new correct locations.
         for (i=0; i<=qPtr->front-1; i++)
             qPtr->elements[i+qPtr->queueSize] = qPtr->elements[i];     
         
         // Enqueue the new item, now that there is space. We are guaranteed that
         // no wraparound is necessary here.
         qPtr->elements[i+qPtr->queueSize] = val;    
         
         // More bookkeeping: The size of the queue as doubled and the number of
         // elements has increased by one.
         (qPtr->queueSize) *= 2;
         (qPtr->numElements)++;
         
         return 1;    
    }
        
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: If the queue pointed to by qPtr is non-empty, then the value
//                 at the front of the queue is deleted from the queue and 
//                 returned. Otherwise, -1 is returned to signify that the queue
//                 was already empty when the dequeue was attempted.
int dequeue(struct queue* qPtr) {
    
    int retval;
    
    // Empty case.
    if (qPtr->numElements == 0)
        return EMPTY;
        
    // Store the value that should be returned.
    retval = qPtr->elements[qPtr->front];
    
    // Adjust the index to the front of the queue accordingly.
    qPtr->front = (qPtr->front + 1)% qPtr->queueSize;
    
    // We have one fewer element in the queue.
    (qPtr->numElements)--;
    
    // Return the dequeued element.
    return retval;
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: returns true iff the queue pointed to by pPtr is empty.
int empty(struct queue* qPtr) {
    return qPtr->numElements == 0;
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: if the queue pointed to by qPtr is non-empty, the value 
//                 stored at the front of the queue is returned. Otherwise,
//                 -1 is returned to signify that this queue is empty.
int front(struct queue* qPtr) {
    if (qPtr->numElements != 0)
        return qPtr->elements[qPtr->front];
    else
        return EMPTY;
}
