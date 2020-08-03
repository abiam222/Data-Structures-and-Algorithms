//comporator, comparable, serialize

class Node { 
    // constructor 
    constructor(element) 
    { 
        this.element = element; 
        this.next = null
    } 
} 

mainLL()

function mainLL() {
    //5->8->2->13
    let head = new Node();
    head.element = 5
    head.next = new Node();
    head.next.element = 8;
    head.next.next = new Node();
    head.next.next.element = 2;
    head.next.next.next = new Node();
    head.next.next.next.element = 13;
    head.next.next.next.next = null;//don't have to do this because its set in the constructor
    //console.log(head)

    //head = insertNodeHead(head, 4);
    //head = reverseLL(head);
    head = deleteNode(head, 2);
    printLLIterative(head);
    //printLLRecursive(head);
   // printInReverse(head);
}


//iterative vs recursive
function printLLIterative(node) {
    if (node == null) return node;
   
    while (node != null) {
        console.log(node.element);
        node = node.next;
    }
}

//this is technically a DFS solution
function printLLRecursive(node) {
    if (node == null) return;
    console.log(node.element);
    printLLRecursive(node.next);
}
//
//head curr nextNULL
//prev 13->2-> 8->5->NULL
function reverseLL(curr) { //head or just have curr = head
    let prev = null;
    //let curr = head;
    let next = curr.next;

    while (curr != null) {
        next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}


function inserNodeAtTail(head, elem) {

}

//
//newNode 4->(head)5->8->2->13
function insertNodeHead(head, elem) {
    if (head == null) return head;

    let newNode = new Node(elem);
    newNode.next = null;

    newNode.next = head;
    return newNode;
}

function insertNodeAtPosition() {

}

function printInReverse(head) {
    if (head != null){
    printInReverse(head.next);
    console.log(head.element);
    }
    return;
}

//headtmp5->8->13->NULL
function deleteNode(head, elem) {
    let tmp = head;
    //if head == null
    if (head == null) return head;
    
    //delete head
    if (head.element == elem) {
        head = head.next;
        //free pointer
        tmp = null;
        return head;
    }
   
    //delete non head
    while (tmp != null) {
        if (tmp.next.element == elem) {
            let tmp2 = tmp.next;
            tmp.next = tmp.next.next;
            //free pointer 
            tmp2 = free;
            return head;
        }
        tmp = tmp.next;
    }
    return head;
}

//compare two ll
//merge two sorted ll
//cycle detection
//merge points of two ll
//doubly LL
//reverse doubly LL