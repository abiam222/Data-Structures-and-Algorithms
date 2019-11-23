#include <iostream>
#include <vector>

using namespace std;

vector<int> total;
void binarySearch(vector<int> arr, int size, int num);

int main() {
    int arr[5] = {4, 21, 5, 66, 12};
    vector<int> vals(arr, arr+(sizeof(arr)/sizeof(arr[0])) );
   
    //always do this in case because you can be
    //popping vals values and vals.size() changes
    int size = vals.size();

    //base case
    //array is empty 
    if (vals.size() == 0) return 0;

    //insert as binary search O(nlogn) O(n) going through a
    //arry and log n going through binary search 
    for (int i=0; i<size;i++)  {
        binarySearch(vals, vals.size(), vals.back()); 
        vals.pop_back();
    }

    //, then search [1] O(1)
    //cout << vals.at(1) << endl;//second smallest;
        for (int i=0; i<size;i++){
            cout << total.at(i) << endl; 
            total.pop_back();
        }

    return 0;
}

void binarySearch(vector<int> vals, int size, int num) {
    int low =0; int high=size-1;
    int found=0; int mid;
    int resize=1;

    while (low <= high) {
        mid = (low + high) / 2;
        //12,66

        cout << "EMPTY? "  << total.empty() << endl;
        //if total empty just insert
        if (total.empty()) { 
            cout << "INSIDE EMPTY: " << num << endl;
            total.push_back(num);
            found++;
        }

        //found the value (means there is duplicate just add to left)
        else if (total.at(mid) == num)  {
            cout << "INSIDE MID, NOBODY SHOULD BE HERE" << num << endl;
            total.insert(total.begin()+mid+1, num);  
            found++;
        }

        else {

            if (num > total.at(mid)) {
                cout << "num > total[mid] " << num << endl;
                low = mid+1;
            } else {
                cout << "num < total[mid] " << num << endl;
                high = mid-1;
            }

        resize++;
         total.resize(resize);
        }
        //didn't find number but there wasn't another number there
    }
    cout << endl;
    cout << "num: " << num << " found: " << found << " mid: " << mid << endl << endl;
    if (found==0) {
       total.insert(total.begin()+mid, num);
    }
}