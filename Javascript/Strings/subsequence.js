/*

Subsequence - a sequence that van be derived form another sequence by deleting some or no elements without changing the order of the remaining elements
e.g.
ABCD AB AC AD A BC CD or what I do\
2 longest subsequence 5 3 2 4 6 1
3 4 6
2 4 6

Is subsequence
and
find all subsequence 

*/

main();

function main() {
    let str = "ABCD";//ABCD AB AC AD A BC CD
    let str2 = "ABA";//AB
    //"gksrek"; 
    //geeksforgeeks

    //findSubsequence(str);
    console.log( isSubsequence(str, str2) );

}

// function findSubsequence(str) {
//     let 
// }

function isSubsequence(str, str2) {
    let j = 0; // For index of str1 (or subsequence 
 
    for (let i=0; i<str.length && j<str2.length; i++) 
        if (str.charAt(i) == str2.charAt(j)) j++; 
    
   return (j==str2.length); 
}

/*
  A B C D
  1 2 3 4


*/

// // Driver program to test methods of graph class 
// int main() 
// { 
//     char str1[] = "gksrek"; 
//     char str2[] = "geeksforgeeks"; 
//     int m = strlen(str1); 
//     int n = strlen(str2); 
//     isSubSequence(str1, str2, m, n)? cout << "Yes ": 
//                                      cout << "No"; 
//     return 0;


// above is recursive
// this is iterative

// bool isSubSequence(char str1[], char str2[], int m, int n) 
// { 
//    int j = 0; // For index of str1 (or subsequence 
//   
//    // Traverse str2 and str1, and compare current character  
//    // of str2 with first unmatched char of str1, if matched  
//    // then move ahead in str1 
//    for (int i=0; i<n&&j<m; i++) 
//        if (str1[j] == str2[i]) 
//          j++; 
//   
//    // If all characters of str1 were found in str2 
//    return (j==m); 
// } 
