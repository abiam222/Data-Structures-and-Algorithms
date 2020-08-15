// Arup Guha
// 3/31/08
// Hash Table of words implemented using Linear Probing.

#include <stdio.h>

// Note: This constrains the limits of static memory allocation...
#define MAX_SIZE 29
#define TABLE_SIZE 59999

struct htable {
    char entries[TABLE_SIZE][MAX_SIZE+1];
};

// Hash Table Functions.
void initTable(struct htable *h);
int hashvalue(char word[]);
void insertTable(struct htable *h, char word[]);
int searchTable(struct htable *h, char word[]);
void deleteTable(struct htable *h, char word[]);

int main() {
    
    char filename[MAX_SIZE+1], temp[MAX_SIZE+1];
    FILE *ifp;
    int numwords, i;
    struct htable mytable;
    int ans;
    
    // Get the file name.
    printf("What is the name of the dictionary file?\n");
    scanf("%s", &filename);
    ifp = fopen(filename, "r");
    
    fscanf(ifp, "%d", &numwords);
    
    // Read in all of the words from a file into the table.
    // This is only done once.
    printf("get here\n");
    initTable(&mytable);
    printf("iniit table\n");
    
    for (i=0; i<numwords; i++) {
        fscanf(ifp, "%s", temp);
        insertTable(&mytable, temp);
    }
    
    
    // Allow the user to make changes to the hash table and search for words.
    do {
       
        printf("Do you want to 1)search word, 2) add word, 3) delete a word?\n");
        scanf("%d", &ans);
       
        // Search for a word.
        if (ans == 1) {
                   
            printf("What word are you looking for?\n");
            scanf("%s", temp);
            if (searchTable(&mytable, temp))
                printf("%s was found.\n", temp);
            else
                printf("%s was NOT found.\n", temp);     
        }    
        
        // Add a word.
        else if (ans == 2) {
            
            printf("What word do you want to add?\n");
            scanf("%s", temp);
            if (searchTable(&mytable, temp))
                printf("%s was ALREADY in the table\n", temp);
            else 
                insertTable(&mytable, temp);     
        }
        
        // Delete a word.
        else if (ans == 3) {
        
            printf("What word do you want to delete?\n");
            scanf("%s", temp);
            deleteTable(&mytable, temp);
                 
        }
        
    } while (ans < 4); // Not very user friendly, just quits for any number > 3.
    
    system("PAUSE");
    return 0;
}

// Pre-condition: none
// Post-condition: Sets each entry in the hash table pointed to by h to the
//                 empty string.
void initTable(struct htable *h) {
     int i;
     
     // Our marker for an empty entry is the empty string.
     for (i=0; i<TABLE_SIZE; i++)
         strcpy(h->entries[i], "");     
}

// Pre-condition: none
// Post-condition: Calculates a hash value for word.
int hashvalue(char word[]) {
    
    int i, sum=0;
    
    // Basically represents the value of word in base 128 (according to ascii
    // values) and returns its value mod the TABLE_SIZE.
    for (i=0; i<strlen(word); i++)
        sum = (128*sum + (int)(word[i]))%TABLE_SIZE;
        
    return sum;
}

// Pre-condition: h points to a valid hash table that IS NOT full.
// Post-condition: word will be inserted into the table h.
void insertTable(struct htable *h, char word[]) {
     
    int hashval;
    hashval = hashvalue(word);
    
    // Here's the linear probing part.
    while (strcmp(h->entries[hashval], "") != 0)
         hashval = (hashval+1)%TABLE_SIZE;
         
    strcpy(h->entries[hashval], word);     
}

// Pre-condition: h points to a valid hash table.
// Post-condition: 1 will be returned iff word is stored in the table pointed to
//                 by h. Otherwise, 0 is returned.
int searchTable(struct htable *h, char word[]) {
 
    int hashval;
    hashval = hashvalue(word);

    // See what comes first, the word or a blank spot.    
    while (strcmp(h->entries[hashval], "") != 0 &&
           strcmp(h->entries[hashval], word) != 0)
        hashval = (hashval+1)%TABLE_SIZE;
        
    // The word was in the table.
    if (strcmp(h->entries[hashval], word) == 0)
        return 1;
        
    // It wasn't.
    return 0;

}

// Pre-condition: h points to a valid hash table.
// Post-condition: deletes word from the table pointed to by h, if word is
//                 stored here. If not, no change is made to the table pointed
//                 to by h.
void deleteTable(struct htable *h, char word[]) {
 
    int hashval;
    hashval = hashvalue(word);
    
    // See what comes first, the word or a blank spot.    
    while (strcmp(h->entries[hashval], "") != 0 &&
           strcmp(h->entries[hashval], word) != 0)
        hashval = (hashval+1)%TABLE_SIZE;
        
    // Reset the word to be the empty string.
    if (strcmp(h->entries[hashval], word) == 0)
        strcpy(h->entries[hashval],"");
        
    // If we get here, the word wasn't in the table, so nothing is done.
}
