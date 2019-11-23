#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> tarIndex;
int target(2);

void process();
void initializeArr();
void printIndex();

int main() {
    initializeArr();
    target = 9;
    process();
    printIndex();

    return 0;
}

void process() {
    int firstIndex = -1;
    int lastIndex = -1;
    int index = 0;
    //save 1st instance
    for (int i=0; i<arr.size();i++) {
        //found first target and only on first try 
        if ( (arr.at(i) == target) && index==0 ) {
            firstIndex = i;
            index++;
        }

        //found other indexes, will obviouly keep last one
        else if (arr.at(i) == target) {
            lastIndex = i;
        }
    }

    tarIndex.push_back(firstIndex);
    tarIndex.push_back(lastIndex);
}

void printIndex() {
    for (int i=0; i<tarIndex.size();i++) {
        cout << tarIndex[i] << " ";
    }
    cout << endl;
}

//arr = [1,3,3,5,7,8,9,9,9,15];
//[100, 150, 150, 153]
//1,2,3,4,5,6,10]
void initializeArr() {
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(10);
}


/*

Hi, here's your problem today. This problem was recently asked by AirBNB:

Given a sorted array, A, with possibly duplicated elements, find the indices of the first and last occurrences of a target element, x. Return -1 if the target is not found.

Example:
Input: A = [1,3,3,5,7,8,9,9,9,15], target = 9
Output: [6,8]

Input: A = [100, 150, 150, 153], target = 150
Output: [1,2]

Input: A = [1,2,3,4,5,6,10], target = 9
Output: [-1, -1]
class Solution: 
    def getRange(self, arr, target):
       # Fill this in.


 */