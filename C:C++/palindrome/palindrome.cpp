#include <iostream>

using namespace std;

string str;

string longestPalindrome(string str);

int main() {
    string answer;

    cin >> str;

   answer = longestPalindrome(str);

   cout << answer << endl;

    return 0;
}
    
string longestPalindrome(string str) {
        //if size zero, return ""
        if (str.size()==0)return "";
            
        //if size 1 return just s
        if (str.size()==1)return str;
        
        //else
        int n = str.size();
        int table[n][n];
        int maxLength=1,start=0;
         
        // All all to zero
        for (int i=0; i<n; i++) 
            for(int j=0;j<n;j++)
                table[i][j] = 0;
        
        // All substrings of length 1 are palindromes 
        for (int i=0; i<n; i++) 
           table[i][i] = 1;
        
        // check for sub-string of length 2. 
        for (int i=0;i<n-1;i++) { 
            if (str[i] == str[i+1]){ 
                table[i][i+1] = true; 
                start = i; 
                maxLength = 2; 
            } 
        }
        
        // Check for lengths greater than 2. k is length 
        // of substring 
        for (int k = 3; k<=n;++k) { 
        // Fix the starting index 
        for (int i = 0; i < n-k+1 ; ++i) { 
            int j = i + k - 1; 
                
        //print
        for(int p=0;p<n;p++){
            for (int q=0;q<n;q++){
                cout <<table[p][q]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;

            //if behind is palindrone and i match with the other side, then Palindrone
            cout << table[i+1][j-1] <<" "<< i+1 <<" "<<j-1<<endl;//check below and before if its palendrome
            cout << str[i] << " " << str[j]<< endl;
            cout << k <<" "<<i<<" "<<j<<endl;//k length, i j where im at
            //if palendrome and str[i]==str[j] are the same
            if (table[i+1][j-1] && str[i] == str[j]){ 
                table[i][j] = 1; 
  
                if (k>maxLength) { 
                    start = i; 
                    maxLength = k; 
                    //cout << k <<" "<<i<<" "<<maxLength<<" "<<endl;//5 0 5
                } 
            } 
        } 
    } 

        //print
        for(int p=0;p<n;p++){
            for (int q=0;q<n;q++){
                cout <<table[p][q]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;


        string printPal="";
        cout << start << " " << maxLength <<endl;
        for(int i=start;i<=start+maxLength-1;i++){
                printPal+=str[i];
        }
  
    return printPal; // return length of LPS 
}
    
