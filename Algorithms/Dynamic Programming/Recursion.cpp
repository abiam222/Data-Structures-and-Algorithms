#include <iostream>

using namespace std;

int f(int n);


int main(){

    //int b[] = { 1,2,3 };
    //cout << b[0] << " " << b[1] << " " << b[2] << endl;
   int var = 7;
   int total = f(var);

   cout << "answer is:" << total << endl;

    return 0;
}

int f(int n){

    //cout << n << endl;
    if(n == 0) return 0;
    else if (n == 1) return 1;

    return f(n-1) + f(n-2);
}