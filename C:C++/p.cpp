#include <iostream>
#include <string>
#include <vector>
#include <set> 
#include <map>

using namespace std;

int myAtoi(string str);

struct LL {
    int data;
    struct LL *next;
}

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
}

class LL2 {
    public:
        int data;
        struct LL *next;
}

map<string, int> amt;
class myObj {
    public:
        string name;
        string id;
        int num;
        
    myObj(){
        
    }

    myObj(string pname, string pid, int pnum) {
        name = pname;
        id = pid;
        num = pnum;
        amt[name]++;
    }
};

int main() {
    //remove dup with arr not set
    // string arr[] = {"Bob", "Jill", "Bob", "Alice"};
    // vector <string> vals;
    // int size = sizeof(arr)/sizeof(arr[0]);
    // int found = 0;
    // set <string> vals2(arr, arr+size);

    

    // int = {
    //     "Abiam", "1234", 10,
    //     "Rachael", "23434", 20,
    //     "Abiam", "35435", 34,
    //     "Nick", "24533", 5
    // }


    // for (//size) {
    //   myObj obj = myObj(i,b,c);
    //   vals.push_back(obj);
    // }

    //ex
    myObj *obj = new myObj();
    obj->name = "abiam";
    cout << obj->name << endl;

//     myObj obj = myObj("Abiam", "1234", 10);
//     myObj obj2 = myObj("Rachael", "643534", 20);
//     myObj obj3 = myObj("Abiam", "5635", 30);
//     myObj obj4 = myObj("Nick", "234234", 40);
//    // myObj arr[] = {obj, obj2, obj3, obj4};
    vector<myObj> vals;
    // vals.push_back(obj);
    // vals.push_back(obj2);
    // vals.push_back(obj3);
    // vals.push_back(obj4);

     string arr[][3] = { //or 4
            {  "Abiam", "1234", "10"},
            {  "Rachael", "23434", "20",},
            {  "Abiam", "35435", "34"},
            {  "Nick", "24533", "5" }
     };
   
   //n times
    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) {
        myObj obj = myObj(arr[i][0], arr[i][1], stoi(arr[i][2]));
        vals.push_back(obj);
    }

    map<string, int> nums;
    map<string, int> averages;
    //or use vector for dynamic data
    //cout << obj.name << endl;

    //find average
    //O(n)
    for (int i=0;i<vals.size();i++) {
        //if there something there add more else just add
         if (nums[vals[i].name]) {
            nums[vals[i].name] += vals[i].num;
         } else {
             nums[vals[i].name] = vals[i].num;
         } 
    }

    //O(n-m) where m is the set(repeating) of values
    for (auto i: nums) {
        cout << i.first << " ";
        cout << i.second << endl;
        cout << amt[i.first] << endl;
        int average = i.second / amt[i.first];
        averages[i.first] =average;
    }

    for (auto i: averages) {
        cout << i.first << " ";
        cout << i.second << endl;
    }

    
    //O(n^2) using array
    // for (int i=0;i<size;i++) {
    //     for (int j=i+1;j<size;j++) {
    //         if (arr[i] == arr[j]) found = 1;
    //     }
    //     if (found == 0) vals.push_back(arr[i]);
    //     found = 0;

    // }

    //print array
    //  for (int j=0;j<vals.size();j++) {
    //      cout << vals[j] << endl;
    // }

    //O(n) time
    // for (int i=0;i<size;i++) {
    //     vals2.insert(arr[i]);
    // }

    // for(auto i: vals2){
    //     cout << i << endl;
    // }

    // string str = "-123"; 
    // int val = myAtoi(str); 
    // cout << val << endl; 

    return 0;
}

// A simple atoi() function 
// int myAtoi(string str) 
// { 
//     int res = 0; // Initialize result 
//     int sign = 1; // Initialize sign as positive 
//     int i = 0; // Initialize index of first digit 
  
//     // If number is negative, then update sign 
//     if (str[0] == '-') { 
//         sign = -1; 
//         i++; // Also update index of first digit 
//     } 
  
//     // Iterate through all digits and update the result 
//     for (; str[i] != '\0'; ++i) {
//         cout << i << endl;
//         res = res * 10 + str[i] - '0'; 
//     }
        
  
//     // Return result with sign 
//     return sign * res; 
// } 