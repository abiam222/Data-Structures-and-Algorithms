#include <iostream>

using namespace std;

struct DoublyLL {
    int data;
    struct DoublyLL *next;
    struct DoublyLL *prev;
};

struct LL {
    int data;
    struct LL *next;
    //LL(int x) {  data=x; next=NULL;}//if this is here you have to use it
};

class LList {
    public:
        int data;
        LList *next;
    
    LList() {}
    
    LList(int x) {
        data = x;
        next = NULL;
    }
};

struct LL *insertNodeTail(struct LL *root, int val);
void printLL(struct LL *root);
struct LL *reverseLL(struct LL *root);
struct LL *insertNodeHead(struct LL *root, int val);
struct LL *insertAtPosition(struct LL *root, int position, int val);
void printReverse(struct LL *root);
struct LL *mergeSortedLinkedList(struct LL *root, struct LL *root2);
struct DoublyLL *reverseDoublyLL(struct DoublyLL *root);


int main() {

    //struct LL *root = new LL(8); //struct <struct name> <name>
    //LList *head = new LList(6);//<class name> and <object name>
    //LList *start = new LList();//this pointer object will initialize point to new space in RAM
    //LList start(6) //an object that will use a special constructor (not a pointer)

    //root = new LL; //new <struct name>
    //head.data = 6;

    //cout << head->data << endl;
    //cout << root->data << endl;

    //my linked list 5->8->13->21->34
    struct LL *root = new LL;
    root->data = 5;
    root->next = new LL;
    root->next->data = 8;
    root->next->next = new LL;
    root->next->next->data = 13;
    root->next->next->next = new LL;
    root->next->next->next->data = 21;
    root->next->next->next->next = new LL;
    root->next->next->next->next->data = 34;
    root->next->next->next->next->next = NULL;

    struct LL *root2 = new LL;
    root2->data = 105;
    root2->next = new LL;
    root2->next->data = 108;
    root2->next->next = new LL;
    root2->next->next->data = 113;
    root2->next->next->next = new LL;
    root2->next->next->next->data =121;
    root2->next->next->next->next = new LL;
    root2->next->next->next->next->data = 134;
    root2->next->next->next->next->next = NULL;

    //5<->8<->13->NULL
    struct DoublyLL *head = new DoublyLL;
    head->data = 5;
    head->next = new DoublyLL;
    head->prev = NULL;
    head->next->data = 8;
    head->next->next = new DoublyLL;
    head->next->prev = head->next;
    head->next->next->data = 13;
    head->next->next->next = NULL;
    head->next->next->prev = head->next->next;

    //root = reverseLL(root);
    //root = insertNodeTail(root, 77);
    //root = insertNodeHead(root, 77);
    //root = insertAtPosition(root, 3, 77);
    //root = mergeSortedLinkedList(root, root2);
    printLL(head);
    //cout << endl << endl;
    //printReverse(root);

    return 0;
}

void printLL(struct LL *root) {
    if (root != NULL) {
        cout << root->data << endl;
        printLL(root->next);
    }
}

//recursively 
//5->8->13...
//dfs
void printReverse(struct LL *root) {
    if (root != NULL) {
        printReverse(root->next);//all the way through the end
        cout << root->data << endl;
    }
}

//
//(root)(prev)(next)34->21->13->8->5->NULL     NULL
struct LL *reverseLL(struct LL *root) {
    struct LL *next = root; //iterate through my LL
    struct LL *prev = NULL; //my new reversed LL

    while (root != NULL) {
       next = root->next;
       root->next = prev;
       prev = root;
       root = next;
    }
    root = prev;
    return root;
}

//7 we want to insert this at node tail 
//(root)5->8->13->21->(itr)34->NULL 
struct LL *insertNodeTail(struct LL *root, int val){
    struct LL *itr = root;

    //base case
    if (root == NULL) {
        struct LL *tmp = new LL;
        tmp->data = val;
        tmp->next = NULL;
        return tmp;
    }

    while (itr != NULL) {
        if (itr->next == NULL) {
            struct LL *tmp = new LL;
            tmp->data = val;
            tmp->next = NULL;
            itr->next = tmp;
            return root;
        }
        itr = itr->next;
    }
    return root;
}


//create node of value
//insert into head
//(newNode)7->(root)5->8->...
struct LL *insertNodeHead(struct LL *root, int val) {
    struct LL *newNode = new LL;
    newNode->data = val;
    newNode->next = NULL;

    //base case root is empty
    if (root == NULL) return newNode;

    //else we have data
    newNode->next = root;//make this (left) point to (right)
    free(root);
    return newNode;
}
//at position 3 so after the 13-> 77 -> ... 
//(root)5->8->(next)13->(tmp)21->34

//tmp NULL
//
//(root)5->8->(next)13->(newNode)77->NULL (tmp)21->34->NULL

//next will iterate through LL
//have a counter until I get to position-1 then I can point 13->next to new node
//and point new node next to 13->next (what it was, so I need a placeholder for that)
struct LL *insertAtPosition(struct LL *root, int position, int val) { //root, 3,77
    struct LL *next = root;//pointing same place in RAM 
    struct LL *tmp = NULL;//tmp node 
    //new node for value
    struct LL *newNode = new LL;
    newNode->data = val;
    newNode->next = NULL;

    //counts until I get to my position
    int counter = 0;

    while (next != NULL) {
        if (counter == position-1) {
            //cout << "ARRIVED" << endl;
            //cout << counter << endl;
            tmp = next->next;
            next->next = newNode;
            newNode->next = tmp;
            return root;
        }
        counter++;
        next = next->next;
    }
    return root;
}


//(root)1->2->(tmp)3->NULL  (tmp2)6->7->8->NULL
//(root2)
struct LL *mergeSortedLinkedList(struct LL *root, struct LL *root2) {
    //base case
    if (root == NULL && root2 == NULL) return root;//aka NULL
    if (root == NULL) return root2;
    if (root2 == NULL) return root;

    //something to iterate through 
    struct LL *tmp = root;
    struct LL *tmp2 = root2;
    
    //iterate through lowest first
    if (tmp->data < tmp2->data) {
        while (tmp != NULL) {
            if (tmp->next == NULL) {
                tmp->next = tmp2;
                return root;
            }
            tmp = tmp->next;
        }
    } else {
        while (tmp2 != NULL) {
            if (tmp2->next == NULL) {
                tmp2->next = tmp;
                return root2;
            }
            tmp2 = tmp2->next;
        }
    }
    return root;
}

//
// <-next5prev->  next<-8->prev  (temp) next<-13->prev(current)(root)NULL
//answer NULL<-13<->8<->5->NULL
struct DoublyLL *reverseDoublyLL(struct DoublyLL *root) {
    struct DoublyLL *temp = NULL;  
    struct DoublyLL *current = root;

     while (current !=  NULL){
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;              
       current = current->prev;
     }   

    if(temp != NULL )
        root = temp->prev;

    return root;
}