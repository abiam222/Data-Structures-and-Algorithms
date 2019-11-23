#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() {
    set<int> mySet;
    priority_queue<int> myPQ;

    myPQ.push(5);
    myPQ.push(10);
    myPQ.push(3);

    //second largest
    myPQ.pop(); //10
    cout << myPQ.top() << endl;
    

    mySet.insert(5);
    mySet.insert(10);
    mySet.insert(5);
    mySet.insert(10);
    mySet.insert(6);

    for (set<int>::iterator it=mySet.begin(); it!=mySet.end(); it++)
        cout << *it << endl;

    return 0;
}