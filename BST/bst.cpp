#include <iostream>

using namespace std;

struct TNode {
    int data;
    struct TNode *left;
    struct TNode *right;
};


struct TNode *create_bst();
void insert_bst(struct TNode *root, struct TNode *node);
void inorder(struct TNode *root);
void preorder(struct TNode *root);
void postorder(struct TNode *root);
int search_node(struct TNode *root, int value);
void update_node(struct TNode *root, int val, int repVal);

struct TNode *insert(struct TNode *root, int value);
struct TNode *insert2(struct TNode *root,struct TNode *element);

int parent(struct TNode *root, int node);
void minVal(struct TNode *root);
void maxVal(struct TNode *root);
int isLeaf(struct TNode *root, int val);
struct TNode *deleteNode(struct TNode *root, int val);

int hasOnlyLeftChild(struct TNode *node);
int hasOnlyRightChild(struct TNode *node);
void findParentDeleteChild(struct TNode *root, int node);

int main() {
    struct TNode *root;
    root = create_bst();

    //parent(root,9);
    //inorder(root);
    //cout << endl;
    //minVal(root);
    //maxVal(root);
    //isLeaf(root,9);
    root = deleteNode(root,9);
    inorder(root);
    return 0;
}

struct TNode *create_bst() {
    struct TNode *root = new TNode;
    root->left = NULL; root->data = 5; root->right = NULL;

    int arr[] = {7,1,9,3,4,2,6};
    int length = 7,i=0;

    while (length--){
        //create tmp
        struct TNode *tmp = new TNode;
        tmp->left = NULL; tmp->data = arr[i];  tmp->right = NULL;

       insert_bst(root,tmp);
        
        i++;
    }
    return root;
}

void insert_bst(struct TNode *root, struct TNode *node) {
    struct TNode *tmp = root;

    while (tmp != NULL) {
        if (tmp->data > node->data){
            if (tmp->left == NULL) { tmp->left = node;return; }
            else { tmp = tmp->left; }
        }else{
            if (tmp->right == NULL) { tmp->right = node;return; }
            else { tmp = tmp->right; }
        }
    }
}

void preorder(struct TNode *root){
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    } 
}

void inorder(struct TNode *root){
  if (root != NULL){
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

void postorder(struct TNode *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " "; 
    }
}

//Log(n)
int search_node(struct TNode *root, int value){
    if (root != NULL){
        if (root->data == value) return 1;

        if (root->data > value){
            return search_node(root->left, value);
        } else {
            return search_node(root->right, value);
        }
        
        
    }else {
    return 0;
    }
}

//another iterative example
// int Find(struct tree_node *ptr, int val) {
//     if (ptr != NULL) {
//         if(ptr->data == val)
//             return 1;
//         return (Find(ptr->left,val) ||
//                 Find(ptr->right,val)
//         )
//     } else {
//         return 0;
//     }
// }


void update_node(struct TNode *root, int val, int repVal){
    if (root != NULL){
        if (root->data == val)root->data = repVal;
        if (root->data > val){
            update_node(root->left, val, repVal);
        }else {
            update_node(root->right, val, repVal);
        }
    }
}


//insert iterative
struct TNode *insert(struct TNode *root, int value){ //or the param can be the whole node too
    //create node
    struct TNode *node = new TNode;
    node->data = value; node->left = NULL; node->right = NULL;
    struct TNode *tmp = root;

    if (tmp == NULL)return node;

    while (tmp != NULL){
        if (tmp->data > node->data){
            if(tmp->left == NULL) {
                tmp->left = node; 
                return root;
            }else {
                tmp = tmp->left;
            }
        } else {
            if (tmp->right == NULL) {
                tmp->right = node; 
                return root;
            } else {
                tmp = tmp->right;
            } 
        }
    }
    return root;
}

//recursion
struct TNode *insert2(struct TNode *root,struct TNode *element) {
    if (root == NULL) return element;
    else {
        if (element->data > root->data)
            root->right = insert2(root->right,element);
        else {
            root->left = insert2(root->left, element);
        }
        return root;
    }
}

/*

       5
   1     7
    3  6  9
   2 4   8
*/

int curr2;
//find parent of a given node in a BST
int parent(struct TNode *root, int node){
    //null case
    cout << "?";
   
    if (root == NULL || root->data == node)
            return 0;
    
  
    //the root is the direct parent of node
    if (root->left->data == node || root->right->data == node){
           cout << "PARENT OF NODE: " << node << " Is: " << root->data << endl;
           return root->data;
    }
    
    //look for nodes parent in the left side of the tree
    if (node < root->data)
        curr2 = parent(root->left, node);
    
    //look for nodes parent in the right side of the tree
    else if (node  > root->data)
        curr2 = parent(root->right, node);
    
    return curr2;
}

void minVal(struct TNode *root) {
    if (root->left == NULL)
        cout << root->data << endl;

    else minVal(root->left);
}

void maxVal(struct TNode *root){
    if (root->right == NULL)
        cout << root->data << endl;
    else maxVal(root->right);
}

int curr=0;
//check whole BST if val is leaf
int isLeaf(struct TNode *root, int val){

    if (root != NULL){
  
        if ( (root->left==NULL) && (root->right==NULL) && (root->data==val) ) {
            return 1;
        }
    
        curr = isLeaf(root->left, val);
        curr = isLeaf(root->right, val);
    }
    return curr;
}

//just check that pointer if its a leaf
// int isLeaf(struct TNode *node){
//     return (node->left == NULL && node->right == NULL);
// }

//has only left child
int hasOnlyLeftChild(struct TNode *node){
    return (node->left!=NULL && node->right==NULL);
}

int hasOnlyRightChild(struct TNode *node){
    return (node->left==NULL && node->right!=NULL);
}


void findParentDeleteChild(struct TNode *root, int node){
    //null case
   
    if (root == NULL || root->data == node)
            return;
    
  
    //the root is the direct parent of node
    if (root->left->data == node ){
           cout << "PARENT OF NODE LEFT: " << node << " Is: " << root->data << endl;
          
        //if is leaf do
         if (isLeaf(root->left,node)==1){
             free(root->right);
             root->right = NULL;
         } 

        //else if has leftChildo r right child or two children
         // cout << hasOnlyLeftChild(root->left) << endl;
           //if only left child point to left
           //else point to right child
    } else if ( root->right->data == node ){
         cout << "PARENT OF NODE RIGHT: " << node << " Is: " << root->data << endl;
         
        if (isLeaf(root->right,node)==1){
             free(root->right);
             root->right = NULL;
        } else if (hasOnlyLeftChild(root->right)==1){
            struct TNode *tmp = root->right->left;
            free(root->right);
            root->right = tmp;
        } else if (hasOnlyRightChild(root->right)==1){
            struct TNode *tmp = root->right->right;
            free(root->right);
            root->right = tmp;
        } else {
            //has two children
            //find min
            //find max, replace ...
        }
    }
    
    //look for nodes parent in the left side of the tree
    if (node < root->data)
       findParentDeleteChild(root->left, node);
    
    //look for nodes parent in the right side of the tree
    else if (node  > root->data)
       findParentDeleteChild(root->right, node);
    
    // return root;
}

//delete leaf Node
//delete 1 Child
//deletes 2 children

struct TNode *deleteNode(struct TNode *root, int val){
    if (root == NULL)
        cout << "NO TREE :(" << endl;

    //get a pointer to the node to delete

    //find parent, make parent point to childs pointer
    findParentDeleteChild(root,val);
      
    return root;
}