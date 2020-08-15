const Queue = require('../StacksQueues/queues.js')
var total=0; 

class Tree { 
    // constructor 
    constructor(val) 
    { 
        this.left = null; //set so we don't have to
        this.right = null; 
        this.data = 0;//if we put val we don't have to do root.data = ... below
    } 
} 

main()

function main() {
    /*
        5
       / \
      3   8
     / \   \ 
    2  7    13
            /
           4

    */
    let root = new Tree();
    
    root.left = new Tree();
    root.right = new Tree();
    root.data = 5;
    
    root.left.left = new Tree();
    root.left.right = new Tree();
    root.left.data = 3;
    
    root.left.left.data = 2;
    
    root.left.right.data = 7;

    root.right.right = new Tree();
    root.right.data = 8;
    
    root.right.right.left = new Tree();
    root.right.right.data = 13;
    
    root.right.right.left.data = 4;
    
    //console.log(root.right.right.left.data)
    //console.log(root)
    //preorder(root)
    //postorder(root)
    //BFS(root)
    //InvertBT(root)

    //let height = height1(root)
    //let height = height2(root)
    //console.log(height)
  
   // countTotalNodes(root)
   // console.log(total)

   let count = countTotalNodes2(root)
   console.log(count)
}

//preorder, postorder, and inorder are DFS solutions
function preorder(root) {
    if (root != null) {
        console.log(root.data);
        preorder(root.left);
        preorder(root.right);
    }

    //iteratively?
}

function postorder(root) {
    if (root != null) {
        postorder(root.left);
        postorder(root.right);
        console.log(root.data);
    }
}

function inorder(root) {
    if (root != null) {
        inorder(root.left);
        console.log(root.data);
        inorder(root.right);
    }
}

//BFS explores nearest root before exploring other nodes
//AKA level order traversal
//enqueue root node
//while (more nodes still in queue)
    //deque node at front (of queu)
    //print this node
    //enquee its childiren
    //continue till no more nodes in queue

//queue<Node*> myQueue;

function BFS(root) {
    let myQueue = new Queue();

    if (root != null ){
        myQueue.push(root);
        console.log(root.data);
    }
    
    while(!myQueue.isEmpty()) {
        let tmp = myQueue.front();
        myQueue.pop();
        
        if (tmp.left) {
            console.log(tmp.left.data);
            myQueue.push(tmp.left);
        }
        
        if (tmp.right) {
            console.log(tmp.right.data);
            myQueue.push(tmp.right);
        }
    }
}

//invert binary tree
function InvertBT(root) {
    if (root == null) return null;
    
    let queue = new Queue();
    queue.push(root);

    while (!queue.isEmpty()) {
        let current = queue.front();
        queue.pop();
        
        let temp = current.left;
        current.left = current.right;
        current.right = temp;
        
        if (current.left != null) queue.push(current.left);
        if (current.right != null) queue.push(current.right);
    }

    //console.log(root)
    BFS(root)
}

/*
java

Invert Binary Tree 

public TreeNode invertTree(TreeNode root) {
    if (root == null) return null;
    Queue<TreeNode> queue = new LinkedList<TreeNode>();
    queue.add(root);
    while (!queue.isEmpty()) {
        TreeNode current = queue.poll();
        TreeNode temp = current.left;
        current.left = current.right;
        current.right = temp;
        if (current.left != null) queue.add(current.left);
        if (current.right != null) queue.add(current.right);
    }

*/

function height1(root) {
    if (root == null) return 0;
    return 1 + Math.max(height1(root.left), height1(root.right));
}

function height2(root) {
    let leftHeight, rightHeight;

    if (root == null) return 0;

    leftHeight = height2(root.left);
    rightHeight = height2(root.right);

    if (leftHeight > rightHeight) 
        return leftHeight + 1;

    return rightHeight + 1;
}

//find largest node in a BST
//the BST will have the largest all the way to the right 
function largestNodeBST(root) {
    if (root == null) return null;
    else if (root.right == null) return root;
    else return largestNodeBST(root.right)
}

//count and return the num of nodes in a BT

function countTotalNodes(root) {
    if (root != null) {
        total += 1;
        countTotalNodes(root.left);
        countTotalNodes(root.right);
    }
}

function countTotalNodes2(root) {
    if (root != null) {
        return 1 + countTotalNodes2(root.left) + countTotalNodes2(root.right); 
    }
    return 0;
}