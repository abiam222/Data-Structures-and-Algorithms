#include <iostream>
#include <math.h>
#include <queue>

using namespace std;
queue<int> myQ;

int fib(int n);
//int N = 4;
int memo[10];
int total;

void printQueue();

int main(){
	int firstTerm, secondTerm, N;
    cin >> N;

	//only use this if I want the whole array 
	//myQ.push(0); 
	//myQ.push(1); 

	//give me the Nth number
    int total = fib(N);
    cout << total << endl;
	printQueue();
    return 0;
}

void printQueue() {
	while (!myQ.empty()) {
		cout << myQ.front() << endl;
		myQ.pop();
	}
}


int fib(int n){
	if(n == 0) return 0; 
	if (n == 1) return 1; 
	if (memo[n]) return memo[n];
	
	total = fib(n-1) + fib(n-2); 
	memo[n] = total;

	return total;
}

//This return the array of values (I can do it with queue, stack, vector)
// int fib(int n){
// 	if(n == 0) return 0; 
// 	if (n == 1) return 1; 
// 	if (memo[n]) return memo[n];
	
// 	total = fib(n-1) + fib(n-2); 
// 	myQ.push(total);
// 	memo[n] = total;

// 	return total;
// }

////0 1 1 2 3 5 8 13 21 34 ...
