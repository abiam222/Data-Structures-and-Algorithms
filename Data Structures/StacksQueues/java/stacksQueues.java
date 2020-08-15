import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;
import java.util.LinkedList;
import java.util.Queue;

class stacksQueues {

    public static void main(String[] args){
        
    }

}

/*
https://www.callicoder.com/java-stack/

STACK
import java.util.Stack;
Stack<String> myStack = new Stack<>();

CREATE
push(x) => x(value)

READ
peek() => peek item from top of the stack 

DELETE
pop() => //pop item from the top of the stack 

SEARCH / ITERATION
search(x) => x(value to search for)
forEach()
iterator()
forEachRemainint()
listIterator()

OTHER
isEmpty()
size()


Queue
Queue<String> myQueue = new LinkedList<>();

CREATE
add(x) => x(value)

READ
element() //get elem at the front of the Queue, w/out removing
peek() //same as element(), just returns null if empty queue unlike element() throws exception

DELETE
remove() //remove first elem from queue 
poll() //same as remove but throws null if queue empty unlike remove which throws exception


SEARCH / ITERATION
contains(x) => x (value to search for)
forEach()
iterator()
forEachRemaining()
for-each

OTHER
isEmpty()
size()


PRIORITY QUEUE
Same as queue but puts everything in oder (technically a HEAP)
PriorityQueue<Integer> numbers = new PriorityQueue<>()

CREATE
add(x) => x(value)

READ


DELETE
remove() //remove first elem from queue 

SEARCH / ITERATION

OTHER
isEmpty()




*/