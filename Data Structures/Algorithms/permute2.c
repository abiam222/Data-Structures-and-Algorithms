// Arup Guha
// 6/14/07
// Running version of the permutation example from Dr. Biswas' COP 3502
// notes.

#include <stdio.h>

void ListPermutations(char str[]);
void RecursivePermute(char str[], int k);
void ExchangeCharacters(char str[], int i, int j);

int main() {
    
    char word[20];
    
    // Let the user enter a word to permute.
    printf("Please enter a word you would like to permute.\n");
    scanf("%s", word);
    
    // Print out the permutations.
    printf("\nHere are the permutations:\n\n");
    ListPermutations(word);
    
    system("PAUSE");
    return 0;
    
}

// Pre-condition: str is a valid C String.
// Post-condition: All permutations of str (assuming all distinct
//                 characters) will be printed.
void ListPermutations(char str[]) {
     
     // Call the appropriate recursive function with the correct
     // parameters.
     RecursivePermute(str, 0);
}

// Pre-condition: str is a valid C String, and k is non-negative and
//                less than or equal to the length of str.
// Post-condition: All of the permutations of str with the first k
//                 characters fixed in their original positions are
//                 printed. Namely, if n is the length of str, then
//                 (n-k)! permutations are printed.
void RecursivePermute(char str[], int k) {
     
     int j, i;

     // Printing out recursion information for non-trivial calls.
     if (k < strlen(str)) {

       // This prints out spaces so we can visualize the depth in the
       // recursive stack with the printout.
       for (i=0; i<k; i++)
         printf("  ");
     
       // Prints out the fixed portion of the string for this recursive call.
       printf("Calling with ");
       for (i=0; i<k; i++)
         printf("%c", str[i]);
     
       // Now print out the letters we are permuting.
       printf(" fixed. Permute: ");
       for (i=k; i<strlen(str); i++)
         printf("%c", str[i]);
       printf("\n");
     }

     // Base-case: Since all letters are fixed, we can ONLY print
     // what's stored in str.
     if (k == strlen(str))
         printf("%s\n", str);
         
     else {
          
         // Loop through each possible starting letter for index k,
         // the first index for which we have a choice.
         for (j=k; j<strlen(str); j++) {
         
             // Place the character stored in index j in location k.
             ExchangeCharacters(str, k, j);
             
             // Print out all of the permutations with that character
             // just chosen above fixed. 
             RecursivePermute(str, k+1);
             
             // Put the original character that used to be there back
             // in its place.
             ExchangeCharacters(str, j, k);
         }
     }
}

// Pre-condition: str is a valid C String and i and j are valid indexes
//                to that string.
// Post-condition: The characters at index i and j will be swapped in
//                 str.
void ExchangeCharacters(char str[], int i, int j) {
     
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}
