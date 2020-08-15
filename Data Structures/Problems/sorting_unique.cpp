/*

Hi, here's your problem today. This problem was recently asked by Google:

Given a list of numbers with only 3 unique numbers (1, 2, 3), sort the list in O(n) time.

Example 1:
Input: [3, 3, 2, 1, 3, 2, 1]
Output: [1, 1, 2, 2, 3, 3, 3]
Challenge: Try sorting the list using constant space.

 */

 #include <iostream>
 #include <map>
 #include <stack>
 #include <deque>
 #include <queue>

 using namespace std;
 stack<int> myS;
 deque<int> myD;
 queue<int> myQ;

void iterVal(int itr, int num);
void finalArrLoop();

 int main() {
     int arr[] = {3,3,2,1,3,2,1};
     int arrSize = sizeof(arr)/sizeof(arr[0]);
     int arrSort[arrSize];//array size of original
     int valOne, valTwo, valThree;

    //test case
     if (arrSize == 0) return 0;

     //value with number of items
     map<int, int> myMap;

     //iterate through arrSize to get values in myMap O(n)
    for (int i=0;i<arrSize;i++) {
        myMap[arr[i]]++;// 3:3 2:2 1:2 this is map value
    }

    //since I know the only values is 1,2,3
    //so myMap[1] print how many
    //myMap[2] how many
    //myMap[3] how many 
    for (int i=0;i<arrSize;i++) {
        if (i+1 == 1) valOne =  myMap[1];
        if (i+1 == 2) valTwo =  myMap[2];
        if (i+1 == 3) valThree = myMap[3];
    }

    //iterate through each
    iterVal(valOne, 1);
    iterVal(valTwo, 2);
    iterVal(valThree, 3);

    //cout << endl;
    //loop through final array
    finalArrLoop();


     return 0;
 }

 void iterVal(int itr, int num) {
   //  cout << itr << endl;
   //  cout << num << endl;
     //O(n)
     for (int i=0;i<itr;i++) {
         //myS.push(num);
         myD.push_back(num);
         myQ.push(num);
     }
 }

void finalArrLoop() {
    //do this in reverse order 
    //int size = myD.size();
    int size = myQ.size();
    for (int i=0; i<size;i++) {
        // cout << myD.front() << endl;
        // myD.pop_front();
        cout << myQ.front() << endl;
        myQ.pop();
    }
}