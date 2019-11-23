#include <iostream>

using namespace std;

int itr=0;

void printTable(int table[5][3], int m, int n);
int count( int S[], int m, int n );
void setTable(int table[5][3], int m, int n);

int main() { 
    int i, j; 
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    cout << count(arr, m, 4) << endl;
    return 0; 
} 

void printTable(int table[5][3], int m, int n) {
 for (int i=0;i<5;i++) {//n+1
        for (int j=0;j<4;j++) { //m
            cout << table[i][j];
        }
        cout << endl;
    }
}

void setTable(int table[5][3], int m, int n) {
    for (int i=0;i<5;i++) {//n+1
        for (int j=0;j<4;j++) { //m
            table[i][j] = 0;
        }
    }
}

int count( int S[], int m, int n ) { 
    int i, j, x, y; 
   
    // We need n+1 rows as the table  
    // is constructed in bottom up 
    // manner using the base case 0 
    // value case (n = 0) 
    int table[5][3];//[n+1] [m] 
    setTable(table, m, n);
      
    // Fill the enteries for 0 
    // value case (n = 0) 
    for (i = 0; i < m; i++) {
        table[0][i] = 1; 
    }
    printTable(table, m, n);
    cout << endl;
        
  
    // Fill rest of the table entries  
    // in bottom up manner  
    for (i = 1; i < n + 1; i++) {

        for (j = 0; j < m; j++) { 
            // Count of solutions including S[j] 
            cout << "Count of solutions including S[j]" << endl;
            printTable(table, m, n) ;
            cout << endl << endl;
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
            printTable(table, m, n) ;
            cout << endl << endl;

            cout << "Count of solutions excluding S[j]" << endl;
            // Count of solutions excluding S[j] 
            printTable(table, m, n);
            cout << endl << endl;
            y = (j >= 1) ? table[i][j - 1] : 0; 
            printTable(table, m, n);
            cout << endl << endl;
  
            // total count 
            cout << "total count" << endl;
            printTable(table, m, n);
            cout << endl << endl;
            table[i][j] = x + y; 
            printTable(table, m, n);
            cout << endl << endl;
        } 
        cout << endl;
    } 
    cout << endl;
    printTable(table, m, n);
    return table[n][m - 1]; 
}