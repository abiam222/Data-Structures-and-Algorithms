#include <iostream>

using namespace std;

struct BST {
    int data;
    BST *left;
    BST *right;
};

class BST_Class {
    public:
        int data;
        BST_Class *left;
        BST_Class *right;
};

int depthOfBST(struct BST *root);
void preorder(struct BST *root);
struct BST* insert(struct BST *root, struct BST *elem);
int find(struct BST *root, int num);
int height(struct BST * root);
struct BST* deleteNode(struct BST *root, struct BST *elem);
int isLeaf(struct BST *elem);
int hasOneChild(struct BST* root);

int main() {
    struct BST *root = new BST;
    BST_Class *head = new BST_Class;

    //   10
    // 5    15
    //3 7  11 20
    root->data = 10;
    root->left = new BST;
    root->right = new BST;
    root->left->data = 5;
    root->left->left = new BST;
    root->left->right = new BST;
    root->left->left->data = 3;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->data = 7;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->data = 15;
    root->right->left = new BST;
    root->right->right = new BST;
    root->right->left->data = 11;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right->data = 20;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    struct BST *elem = new BST;
    elem->data = 15;
    elem->left = NULL;
    elem->right = NULL;
   //cout <<  depthOfBST(root) << endl;
  //// root = insert(root, elem);
  // preorder(root);

   //cout << find(root, 5) << endl;
    
   //cout << height(root) << endl;

   root = deleteNode(root, elem);
   preorder(root);

    return 0;
}

void preorder(struct BST *root) {
    if (root != NULL) {
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

//read BFS

int depthOfBST(struct BST *root) {
    return 1;
}

struct BST* insert(struct BST *root, struct BST *elem) {
    if (root == NULL) 
        return elem;
    
    if ( elem->data > root->data ) {
        root->right = insert(root->right, elem);
    } else {
        root->left = insert(root->left, elem);
    }
    return root;
}


int find(struct BST *root, int num) {
    if (root != NULL) {
        if (num == root->data) return 1;
        if (num < root->data) return find(root->left, num);
        if (num > root->data) return find(root->right, num);
    }
    return 0;
}

int height(struct BST * root) {
  if (root == NULL) return 0;
  return 1 + max(height(root->left), height(root->right));
}

//   10
// 5    15
//3 7  11 20
struct BST* deleteNode(struct BST *root, struct BST *elem) {
    if (root != NULL) {
        if (root->data == elem->data) {
            if ( isLeaf(root) ) {
                return NULL;
            } else if ( hasOneChild(root) ) {
                if (root->right) { return root->right; }
                else { return root->left; }
            } else { //hasTwoChildren  15 -(e.g. delete 15)
                //get max value in left side, save as new node (new node)
                struct BST* maxValLeft = getMaxLeft(root->left);
                maxValLeft->left = root->left;
                maxValLeft->right = root->right;
                //make max val (new node) parent point to tmp2 return this
                return maxValLeft;
                //create new node on elem left pointer since ill delete elem (new node 2)
                root->left 
                //delete elem, make parent of elem point to new node 
                //make new node left point to new node 2 
            }
        } else if (elem->data > root->data) {
          root->right = deleteNode(root->right, elem);
        } else {
          root->left = deleteNode(root->left, elem);
        }
    }
    return root;
}

int isLeaf(struct BST *elem) {
    if (elem == NULL) return 0;

    if ( (elem->left == NULL) && 
    (elem->right == NULL) ) return 1;

    return 0;
}

int hasOneChild(struct BST* root) {
    if (root == NULL) return 0;

    if ( (root->left == NULL) && 
    (root->right != NULL) ) return 1;

    if ( (root->right == NULL) && 
    (root->left != NULL) ) return 1;

    return 0;
}

struct BST* tmp;
struct BST* max = new BST;

//redo-this again with returns 
struct BST* getMaxLeft(struct BST* root) {
    if (root != NULL) {
        if (root->data > max->data) max = root;
        getMaxLeft(root->left);
        getMaxRight(root->right);
    }
    return max;
}