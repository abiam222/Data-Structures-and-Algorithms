#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int total=0;

struct LL {
    int data;
    struct LL *next;
};

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};

int binarySearch(int a[], int len, int val);
void readReverseLL(struct LL *head);
void readLL(struct LL *head);
void readArray(int a[], int size);
void readVector(vector<int> a);


int add(BST* root) {
    if (root != NULL) {
        total += root->data;
        add(root->left);
        add(root->right);
    }
    return 0;
}

int totalNodes(BST* root) {
    // if (root != NULL) {
    //     total += 1;
    //     //cout << root->data << endl;
    //     totalNodes(root->left);
    //     totalNodes(root->right);
    // }
     if (root != NULL)
        return 1 + totalNodes(root->left) + totalNodes(root->right);
    else  
    return 0;
}

int main() {
    struct BST* root = new BST;
    root->data = 5;
    root->left = new BST; root->right = new BST;
    root->left->data = 2;
    root->left->left = NULL; root->left->right = NULL;
    root->right->data = 8;
    root->right->left = NULL; root->right->right = NULL;

     //add(root);
    cout << totalNodes(root) << endl;
    //cout << total  << endl;
    //  int a[] = {7,4,1,132,22,334,5,78,100};
    //  vector<int> b;
    //  string c = "me";

    // cout << c.length() << endl;

    // int arraySize = sizeof(a)/sizeof(a[0]);
    // readArray(a, arraySize);
    // sort(a,a+9);
    // readArray(a, arraySize);

    // for (int i=0; i< arraySize; i++) b.push_back(a[i]);

    // cout << b.size() << endl;
    // sort(b.begin(), b.end());
    // readVector(b);

     //cout << a << endl;
    //cout << binarySearch(a, 9, 101) << endl;
    // ///////////'///

    //cout << root->next->data << endl;

    //readReverseLL(root);

    //find missing
    // int arr[] = { 4, 6, 7, 5, 15, 9, 2, 12};
    // int arr2[] = { 12, 7, 6, 4, 9, 5, 15 };
    // int arrSize = sizeof(arr)/sizeof(arr[0]);
    // int arr2Size = sizeof(arr2)/sizeof(arr2[0]);
    // map<int, int> count;
    // int minVal = 100000;
    // int val;

    //cout << count.at(4) << endl;

    //loop O(n) through the first array. Put how many 4 in map
    //4=1 6=1 7=1 5=1 9=1 12=1 in our map
    // for (int i=0; i < arrSize ; i++) {
    //     count[arr[i]]++;
    // }

    //loop O(n) through the second array. Put how many 4 in map
    //4=2 6=2 7=2 5=1 9=2 12=2 in our map
    // for (int i=0; i < arr2Size ; i++) {
    //     //cout << count[arr2[i]] << " ";
    //     //cout << arr2[i] << " ";
    //     count[arr2[i]]++;
    //     //cout << count[arr2[i]] << endl;
    // }

    //cout << count[4] << endl;
    //loop through largest array so we can get all values
    //O(n)
    // for (int i=0; i < arrSize ; i++) {
    //     //found a lower value 
    //     //cout << count[i] << endl;
    //      if ( count[arr[i]] < minVal) {
    //          minVal = count[arr[i]];
    //          val = arr[i];
    //      }
    // }

    // cout << val << endl;

    // vector<int> myV;
    // vector<int> myV(2)

    // //myV[0] = 1;
    // myV.push_back(1);

    // cout << myV[0] << endl;
    //vector<int> myV(3);
   // myV.push_back(1);
   // myV.push_back(2);
    //  vector<vector<int> > myV(2); //row of 2
    //  myV.at(0).push_back(34);
    // myV.at(1).push_back(10);
    // myV.at(1).push_back(9);//this works because vector are dynamic in the row, that's why you don't have to initialize a vector

    // //these are the same 
    //  cout << myV[0][0] << endl;
    //  cout << myV.at(0).at(0) << endl;
    // cout << myV.size() << endl; // total rows for 2d vector
    // cout << myV.at(0).size() << endl;//row 1 size
    // cout << myV.at(1).size() << endl;
    // int arr[5][5];
    // int arr2[2][3] = { {1,2,3}, {1,2,3} };

    return 0;
}

// void readArray(int a[], int size) {
//    // int size = sizeof(a)/sizeof(a[0]); //can't do this. a has to be in scope
//     for (int i=0;i<size;i++){
//         cout << a[i] << " ";
//     }
//     cout << endl;
// }

// void readVector(vector<int> a) {
//     for (int i=0;i<a.size();i++){
//        // cout << a[i] << " ";
//        cout << a.at(i) << " ";
//     }
//     cout << endl;
// }

// void readLL(struct LL *head) {
//     // while(head != NULL) {
//     //     cout << head->data << endl;
//     //     head = head->next;
//     // }

//     // if (head == NULL ) return;
//     // cout << head->data << endl;
//     // readLL(head->next);
// }
 
void readReverseLL(struct LL *head) {
    if (head == NULL) return;
    readReverseLL(head->next);
    cout << head->data << endl;
}
 
// int binarySearch(int a[], int len, int value){
//     int low = 0, high = len - 1, mid = -1;
//     int index = 0;
//     while (low <= high) {
//          mid = (low + high) / 2; //index low and high 
//          if (value < a[mid]) high = mid-1;
//          else if(value > a[mid]) low = mid+1;
//          else return index;
//          index++;
//     }
//     return index;
// }