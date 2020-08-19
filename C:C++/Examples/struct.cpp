#include <iostream>

using namespace std;

struct test{
    int data;
    int number;
  
};



int main(){
    
    struct test okay;
    okay.data = 5;
    cout << "Our data = " << okay.data;
    
    return 0;
}

