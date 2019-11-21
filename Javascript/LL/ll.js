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
    head.next.next.next.next = null;
    //console.log(head)

    //head = reverseLL(head);
    printLLIterative(head);
    //printLLRecursive(head);
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