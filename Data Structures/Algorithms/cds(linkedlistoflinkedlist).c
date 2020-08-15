// Arup Guha
// 5/30/07
// A class example for COP 3502 illustrating a linked list 
// of linked lists!

#include <stdio.h>

struct CDNode {
    
    char title[50];
    struct CDNode* next;
};

struct ArtistNode {

    char first[30];
    char last[30];
    struct CDNode* listOfCDs;
    struct ArtistNode* next;
};

struct CDNode* insertFrontCD(struct CDNode* list, char title[]);
struct ArtistNode* createNewArtist(char first[], char last[]);
struct ArtistNode* insertFrontArt(struct ArtistNode* list,
                               struct ArtistNode* newNode);
void printCD(struct CDNode* ptr);
void printArtist(struct ArtistNode* ptr);
void printAll(struct ArtistNode* ptr);
struct ArtistNode* findArtist(struct ArtistNode* list,
                              char first[], char last[]);
                          
int menu();

    
int main() {
    
    int ans;
    struct ArtistNode* listOfArtists = NULL;
    struct ArtistNode* tmp = NULL;
    char first[30], last[30], title[50];
    
    ans = menu();
    
    // Loop through the user's choices until they quit.
    while (ans !=4) {
    
        // Add an artist.
        if (ans == 1) {
            
            // Get the information necessary.
            printf("Enter the new artist's name, first then last.\n");
            scanf("%s%s", first, last);    
            
            // We create a node for the artist, then add it to our master list.
            tmp = createNewArtist(first, last);
            listOfArtists = insertFrontArt(listOfArtists, tmp);
        }      
        
        // Add a CD.
        else if (ans == 2) {
        
            // Get all the CD information.
            printf("Enter the first and last name of the artist who has a new CD.\n");
            scanf("%s%s", first, last);
            printf("Enter the name of the CD.");
            scanf("%s", title);     
            
            // Find our Artist!
            tmp = findArtist(listOfArtists, first, last);
            
            // He/She wasn't on our list!
            if (tmp == NULL)
                printf("Sorry, that artist isn't in our catalog. No CD was added.\n");
            
            // We can add the CD.
            else {
            
                // Insert this CD into the correct list.
                tmp->listOfCDs = insertFrontCD(tmp->listOfCDs, title);
                printf("Your artist was found and the CD was added to our catalog.\n");
            }
        }
        
        // Print everything.
        else if (ans == 3) 
            printAll(listOfArtists);
        
        // Just a friendly error message =)
        else if (ans != 4)
            printf("Sorry, not a valid choice. Try again.\n");
            
        ans = menu();
          
    }
    
    system("PAUSE");   
    return 0;
}

// Pre-condition: None
// Post-condition: Returns a pointer to a linked list of CDNodes where a new
//                 node was inserted to the front of the list that was originally
//                 pointed to by list.
struct CDNode* insertFrontCD(struct CDNode* list, char title[]) {
       
    struct CDNode* tmp;
    
    // Set up the new node.
    tmp = (struct CDNode*)malloc(sizeof(struct CDNode));
    strcpy(tmp->title, title);
    
    // Attach the new node to the rest of the list and return it, since it'll
    // be the front of the new list.
    tmp->next = list;
    return tmp;
}

// Pre-condition: None
// Post-condition: Returns a pointer to a single Artist Node that stores
//                 the information for the artist with the name first last.
struct ArtistNode* createNewArtist(char first[], char last[]) {

    struct ArtistNode* tmp;
    
    // Create the new artist node.
    tmp = (struct ArtistNode*)malloc(sizeof(struct ArtistNode));
    strcpy(tmp->first, first);
    strcpy(tmp->last, last);
    
    // Since they are new, they have no CDs.
    tmp->listOfCDs = NULL;
    tmp->next = NULL;
    
    // Return the newly created node.
    return tmp;
}

// Pre-condition: newNode points to a single ArtistNode that stores information
//                for one Artist. list points to the front of an existing list
//                of artists.
// Post-condition: Inserts the Node pointed to by newNode to the front of the list
//                 pointed to by list and returns this new pointer.
struct ArtistNode* insertFrontArt(struct ArtistNode* list,
                               struct ArtistNode* newNode) {
                                      
    // Since the artist data is already filled in, just attach the node to the
    // original list and return it.                                  
    newNode->next = list;
    return newNode;
}

// Pre-condition: None
// Post-condition: Prints out the title of the node pointed to by ptr.
void printCD(struct CDNode* ptr) {
    if (ptr != NULL)
        printf("%s",ptr->title);
}

// Pre-condition: None
// Post-condition: Prints out all hte data for the single artist pointed to by
//                 ptr;
void printArtist(struct ArtistNode* ptr) {

    int cnt = 1;
    struct CDNode* tmp;
    
    // Trivial case.
    if (ptr == NULL) return;
    
    // Print out the name of the artist.
    printf("Artist Name: %s %s\n", ptr->first, ptr->last);
    
    tmp = ptr->listOfCDs;
    
    // Print out each of their CD's, numbering them.
    while (tmp != NULL) {
    
        printf("%d. ",cnt);
        printCD(tmp);
        printf("\n");
        cnt++;
        
        // Go to the next CD.
        tmp = tmp->next;
    }      
    printf("\n");
} 

// Pre-condition: None
// Post-condition: Prints out all the data for all artists in the list pointed
//                 to by ptr.
void printAll(struct ArtistNode* ptr) {
     
    printf("Here is everything we have in stock:\n\n");
    
    // Go through each artist in the list!
    while (ptr != NULL) {
        printArtist(ptr);
        ptr = ptr->next;
    }     
}

// Pre-condition: None
// Post-condition: If the artist with the name first last is in the list pointed
//                 to by list, then a pointer to the node storing that artist's
//                 information is returned. Otherwise, NULL is returned.
struct ArtistNode* findArtist(struct ArtistNode* list,
                              char first[], char last[]) {
                                   
    // Iterate through the list.                               
    while (list != NULL) {
          
        // We found the artist! Return the correct pointer.
        if (strcmp(first, list->first) == 0 &&
            strcmp(last, list->last) == 0)
             return list;       
        list = list->next;  
    }
    
    // Never found the artist.
    return NULL;
}

// Pre-condition: None
// Post-condition: Returns the user's menu choice.
int menu() {

    int ans;
    printf("Which choice would you like?\n");
    printf("1. Enter a new artist.\n");
    printf("2. Add a CD.\n");
    printf("3. Print all the inventory.\n");
    printf("4. Quit.\n");
    scanf("%d", &ans);
    return ans;
}
