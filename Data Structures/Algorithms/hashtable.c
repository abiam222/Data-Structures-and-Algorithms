// Arup Guha
// 10/24/01 edited 2/24/04 for COP 3502 Lecture
// Linked List Example

// Edited on 3/31/08 to implement a hashtable of strings.
// In particular, this implements separate chaining hashing.

#include <stdio.h>

#define MAX_SIZE 39
#define TABLE_SIZE 59999

// Struct used to form a linked list of integers.
struct ll {
    char word[MAX_SIZE+1];
    struct ll *next;
};

struct htable {
    struct ll* entries[TABLE_SIZE];
};

// Linked List Functions.
void print(struct ll *front);
struct ll* insert_front(struct ll *front, char word[]);
struct ll* delete(struct ll *front, char word[]);
void dellist(struct ll *p);
int search(struct ll *front, char word[]);

// Hash Table Functions.
void initTable(struct htable *h);
int hashvalue(char word[]);
void insertTable(struct htable *h, char word[]);
int searchTable(struct htable *h, char word[]);
void deleteTable(struct htable *h, char word[]);
void killTable(struct htable *h);

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
    printf("%d words\n", numwords);
    
    // Read in all of the words from a file into the table.
    // This is only done once.
    initTable(&mytable);
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
    
    // Not totally necessary since our program is ending, but good style.
    killTable(&mytable);
    
    system("PAUSE");
    return 0;
}


// Pre-condition: none
// Post-condition: Initializes the struct pointed to by h to be a valid empty
//                 hash table.
void initTable(struct htable *h) {
    
    int i;
    
    // Set all of these to NULL!
    for (i=0; i<TABLE_SIZE; i++) {
        h->entries[i] = NULL;       
    }
} 

void killTable(struct htable *h) {
     
    int i;
    
    // Set all of these to NULL!
    for (i=0; i<TABLE_SIZE; i++) {
        dellist(h->entries[i]);        
    }
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

// Pre-condition: h points to a valid hash table.
// Post-condition: word will be inserted into the table h.
void insertTable(struct htable *h, char word[]) {
     
    int hashval;
    hashval = hashvalue(word);
    h->entries[hashval] = insert_front(h->entries[hashval], word);     
}

// Pre-condition: h points to a valid hash table.
// Post-condition: 1 will be returned iff word is stored in the table pointed to
//                 by h. Otherwise, 0 is returned.
int searchTable(struct htable *h, char word[]) {
 
    int hashval;
    hashval = hashvalue(word);
    return search(h->entries[hashval], word);   
}

// Pre-condition: h points to a valid hash table.
// Post-condition: deletes word from the table pointed to by h, if word is
//                 stored here. If not, no change is made to the table pointed
//                 to by h.
void deleteTable(struct htable *h, char word[]) {
 
    int hashval;
    hashval = hashvalue(word);
    h->entries[hashval] = delete(h->entries[hashval], word);   
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: each value in the list will be printed, in order.
void print(struct ll *front) {

    while (front !=NULL) {
        printf("%d ", front->word);
        front = front -> next;
    }
    printf("\n");
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: if val is stored in the list, 1 will be returned,
//                 otherwise 0 will be.
int search(struct ll *front, char word[]) {
  
    while (front != NULL) {
 
         if (strcmp(front->word, word) == 0)
             return 1;
         front = front->next;
    }
  
    return 0;
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: a new node storing num will be inserted to the front of
//                 this list and a pointer to this node will be returned.
struct ll* insert_front(struct ll *front, char word[]) {

    struct ll *temp;

    // Create temp node and link it to front.
    temp = (struct ll*)malloc(sizeof(struct ll));
    strcpy(temp->word, word);
    temp->next = front;

    // Return the new front of the list.
    return temp;
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: The first node that contains the value num will be
//                 removed from the list. A pointer to the front of the
//                 list will be returned. If no such value is stored,
//                 the list will remain unchanged.
struct ll* delete(struct ll *front, char word[]) {

    struct ll *temp, *del;
    temp = front;

    // Only need to delete if the list is not null.
    if (temp != NULL) {
    
        // Take care of the case where first node needs to be deleted.
        if (strcmp(temp->word,word) == 0) {
      
            del = temp -> next;
            free(temp);
            return del;
        }
    
        // Otherwise, loop until you find the node to delete and do so.
        while (temp->next != NULL) {
      
            if (strcmp(temp ->next->word,word) == 0) {
        
                del = temp -> next;
                temp->next = temp ->next->next;
                free(del);   
                return front;
            }
            temp = temp -> next;
        }
    }
    return front;
}

// Pre-condition: p points to a linked list.
// Post-condition: All the memory for the linked list pointed to by p is
//                 freed for use.
void dellist(struct ll *p) {

    struct ll *temp;

    // Recursively free each element in the list.
    if (p !=NULL) {
        temp = p -> next;
        dellist(temp);
        free(p);
    }
}
