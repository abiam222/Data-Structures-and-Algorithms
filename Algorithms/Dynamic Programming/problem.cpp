/*#include <iostream>
#include <array>

using namespace std;

void NC(long long n[]);
void C(long long n[]);
int isNegative(int MAX, int n[]);

int MAX1, MAX2, elements, allNegative = 0;

int main(){

   int cases;
   long long num;

   cin >> cases;
   

   for(int i = 0; i < cases ;i++){
   	cin >> elements;
    int a[elements];


   for(int j = 0; j < elements; j++){
   		//cin >> a[j];
       cin >> num;
   }

   MAX1 = 0;
   MAX2 = -10000;
  // cout << endl;
   //C(a);
  // CC(a, size(a));
   allNegative = 0;
  // NC(a);
   cout << MAX2 << " " << MAX1 <<  " "  << endl;
}

 

    return 0;
}

void NC(int n[]){



    for(int i=0; i<elements; i++){
    	if(n[i] > 0){
    		//cout << i << " " << n[i] << " " << MAX1 << endl;
    		MAX1 += n[i]; 
    		allNegative++;
    	}
    }
    if(allNegative == 0)
  	MAX1 = isNegative(MAX1, n);
}

void C(int n[]){

int num=0;
//elements, MAX2
int G[elements][elements];

	 for(int i = 0; i < elements; i++){
    for(int j = 0; j < elements; j++){
        if(j >= i){
            if(i == j){
              G[i][j] = n[j];
            }else{
              G[i][j] = G[i][j-1] + n[j];
            }

            if(G[i][j] > MAX2){
              MAX2 = G[i][j];
            }
        }//end if1
    }
   }



}


int isNegative(int MAX, int n[]){


  //all numbers are negative
   // if(allNegative == 0){
    	MAX = -1000;
    	for(int i=0; i<elements; i++){
    		if(n[i] > MAX ){
    			MAX = n[i];
    		}
    	}
    //}

   return MAX;
  }
  */

  #include <iostream>

using namespace std;

void NC(int n[]);
void C(int n[]);
int isNegative(int MAX, int n[]);

int MAX1, MAX2, elements, allNegative = 0;

int main(){

   int cases;

   cin >> cases;
   

   for(int i = 0; i < cases ;i++){
    cin >> elements;
    long *a = new long[elements];

   for(int j = 0; j < elements; j++){
      cin >> a[j];
   }

   MAX1 = 0;
   MAX2 = -10000;
  // cout << endl;
   //C(a);
   allNegative = 0;
   //NC(a);
   cout << MAX2 << " " << MAX1 << endl;
}

 

    return 0;
}

void NC(int n[]){



    for(int i=0; i<elements; i++){
      if(n[i] > 0){
        //cout << i << " " << n[i] << " " << MAX1 << endl;
        MAX1 += n[i]; 
        allNegative++;
      }
    }
    MAX1 = isNegative(MAX1, n);
}

void C(int n[]){

int num=0;

  for(int i=0;i<=elements-1;i++){
    
    //cout << endl;

  for(int k = elements; k > 0; k--){
    num = 0;
    for(int j=i; j<k; j++){
        num = n[j] + num;
      
        //cout << j << " " << n[i] << " " << MAX2<< " " << num << endl;
        if(num > MAX2 && (j == k-1)){
          MAX2 = num;
      //allNegative++;
      // cout << num << " ";
  }
    }
       
  
  //MAX2 = isNegative(MAX2,n);
    }

  }
}


int isNegative(int MAX, int n[]){


  //all numbers are negative
    if(allNegative == 0){
      MAX = -1000;
      for(int i=0; i<elements; i++){
        if(n[i] > MAX ){
          MAX = n[i];
        }
      }
    }

   return MAX;
  }
