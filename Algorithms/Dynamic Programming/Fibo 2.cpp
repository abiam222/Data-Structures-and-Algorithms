#include <iostream>
#include <math.h>

using namespace std;

int fib(int n);


int main(){

    int firstTerm, secondTerm, N;
    
    cin >> firstTerm >> secondTerm >> N;

    int total = fib(N);
 

   cout << total << endl;

    return 0;
}

int fib(int n){

	int memo[n+1], total;
	//cout << n << endl;

	if( memo[n] >= 3) { return memo[n];}
		 else if( n == 2) { return 1; }
			else if ( n <= 1) { return 0; }
				else { total = pow(fib(n-1),2) + fib(n-2); }

	if(n == 5){
		cout << "here" << endl;
	}
	else{
		cout << "dah" << endl;
	}

		memo[n] = total;
		cout << "here";
	//	cout << total;

		return total;

}