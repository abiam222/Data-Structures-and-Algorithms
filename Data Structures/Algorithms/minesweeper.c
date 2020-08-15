// Arup Guha
// 9/27/00
// Program Description : Implements a simplified version of the game 
//                       minesweeper. The user must clear off squares
//                       one by one, and is not allowed to mark bombs.
//                       Any time the user hits a bomb, they lose, just
//                       like the original game. Play will halt if all
//                       non-bomb squares have been cleared, and the player
//                       is declared the winner in this situation.

// Edited on 5/28/08 to change language from C++ to C.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const int SIDE = 8; // side length of the board
const int NUMBOMBS = 10; // number of bombs on the board
const double EPSILON = 0.001; // Tolerance so adjacent bombs get counted properly.
 
void printboard(char[][SIDE]);
int numberbombs(int,int,int[][2]);
int domove(char[][SIDE], char[][SIDE], int[][2], int, int, int*);
void getbombs(int[][2]);
void getmove(int*, int*);
int valid(int,int);

int main() {
  
    int gameover = 0; // used to check if the game is over or not
  
    char uncovered_board[SIDE][SIDE]; // board that stores the location of all
                                      // the bombs and numbers of adjacent bombs.

    char current_board[SIDE][SIDE]; // stores the current board as it should be
                                    // printed out.

    int totalmoves; // stores the total moves left for the user before they win.

    int i,j;
    int x,y;

    int listbombs[NUMBOMBS][2]; // stores (x,y) coordinates of all bombs.
  
    srand(time(0)); // Seed the random number generator.

    // Initialize the current board.
    for (i=0;i<SIDE;i++) {
        for (j=0;j<SIDE;j++) {
            current_board[i][j] = '_';
            uncovered_board[i][j] = '_';
        }
    }

    // Randomly choose where the bombs will go.
    getbombs(listbombs);
  
    // Place the bombs onto the board.
    for (i=0;i<NUMBOMBS;i++) 
        uncovered_board[listbombs[i][0]][listbombs[i][1]]='*';
  
    totalmoves = SIDE*SIDE - NUMBOMBS;

    // Continue playing until the game ends.
    while (!gameover) {
        
        // Get a move from the user.
        printf("Here is the board : \n");
        printboard(current_board);
        getmove(&x,&y);
        printf("at 7 1 when get move is %c\n", current_board[7][1]);
    
        // Execute that move.
        gameover = domove(current_board,uncovered_board,listbombs,x,y,&totalmoves);

        // Check if they have won.
        if ((!gameover) && (totalmoves==0)) {
            printf("Great! You win!!!\n");
            gameover = 1;
        }
    }
  
    system("PAUSE");
    return 0;
  
}

// Pre-condition: Nada
// Post-condition: x and y will be set to the values of the coordinates that
//                 the user desires to uncover on the board.
void getmove(int *x,int *y) {

    // Read in move.
    printf("To enter a move for row 2 column 3 type 2 3\n");
    printf("Enter your move, (row column) -> ");
    scanf("%d%d", x, y);
  
    // Re-read if invalid.
    while (!valid(*x,*y)) {
        printf("Sorry those aren't valid coordinates. Please try again.\n");
        printf("Enter your move, (row column) -> ");
        scanf("%d%d", x, y);
    }
}

// Pre-condition: The character array passed into the function must be a
//                square 2 dimensional array with each dimension of size
//                SIZE.
// Post-condition: The board passed into the function will be printed out
//                 exactly according to the characters stored in the array.
void printboard(char board[][SIDE]) {

    int i,j;

    // Print out side labels.
    printf("    ");
    for (i=0;i<SIDE;i++)
        printf("%d ", i);
    printf("\n\n");

    // Print out actual board.
    for (i=0;i<SIDE;i++) {
    
        printf("%d   ", i);
        for (j=0;j<SIDE;j++)
            printf("%c ",board[i][j]); 
        printf("\n");
    }
}

// Pre-conditions: Both character arrays are squre 2D arrays with each
//                 dimension of size SIZE, the first dimension of the 
//                 list of bombs array should be of size NUMBOMBS,
//                 row and column must represent the row and column of
//                 the player's move, and totalmoves must equal how many
//                 more squares the user must uncover before winning.
// Post-conditions: The procedure will execute a single move in the game
//                  and make the necessary changes to the auxiliary
//                  data structures to ensure the game runs properly following
//                  the move.
int domove(char board[][SIDE], char realboard[][SIDE],
            int listbombs[][2], int row, int column, int *totalmoves) {


    int i, j, num;
  
    // Take care of the case that the user loses.
    if (realboard[row][column]=='*') {
    
        board[row][column]='*';
        for (i=0;i<NUMBOMBS;i++) 
            board[listbombs[i][0]][listbombs[i][1]]='*';
    
        printboard(board);
        printf("Sorry, you lose!\n");
        return 1;
    }
    
    // Take care of the case that the user chooses a square already chosen.
    else if (board[row][column]!='_') {
    
        printf("That square as already been cleared, try again!\n");
        return 0;
    }
  
    // Execute a normal non-losing move.
    else {
 
        // Calculate the number of adjacent bombs, and place this number on
        // the regular board.
        num = numberbombs(row, column, listbombs);
        (*totalmoves)--;
        
        // Cast is to make sure we store a character in the array.
        board[row][column]=(char)(num+'0');

        // If there are no adjacent bombs, we can recursively clear.
        if (num == 0) {
                
            // Loop through all adjacent indexes to the current square.    
            for (i=-1;i<2;i++) {
	            for (j=-1;j<2;j++) {
	  
	                // We only want to clear this new square IF it hasn't
	                // previously been cleared, so check that first.
	                if (valid(row+i,column+j) && (board[row+i][column+j]=='_'))
	                    domove(board, realboard, listbombs, row+i, column+j, totalmoves);
	            }
            }
	      
        } // end-if num==0

        return 0;
        
    } // end else
}

// Pre-conditions: None
// Post-conditions: Returns 1 iff the coordinates given are within the bounds
//                  of the gameboard.
int valid(int row, int column) {

    // Check four possibilities for an invalid coordinate.
    if (row < 0) return 0;
    
    else if (row >= SIDE) return 0;
  
    else if (column < 0) return 0;
  
    else if (column >= SIDE) return 0;
  
    // If we get here we're good.
    else return 1;
}

// Pre-condition: The size of the first dimension of listbombs is NUMBOMBS,
//                and row and column indicate where the user last moved.
// Post-condition: The function will compute how many bombs are adjacent to
//                 the square the user desires to uncover.
int numberbombs(int row ,int column ,int listbombs[][2]) {

    int i;
    int count = 0;
    for (i=0;i<NUMBOMBS;i++) {

        // Check each bomb one by one against the square to uncover.
        if ((abs(row-listbombs[i][0])<=1+EPSILON) && (abs(column-listbombs[i][1])<=1+EPSILON)) {
            count++; 
        }  
    }
    
    return count;
}


// Pre-condition : The size of the first dimension of listbombs is NUMBOMBS.
// Post-condition: The function will randomly select the appropriate number
//                 of bombs and place them on the board, storing the 
//                 information in bomblist.
void getbombs(int bomblist[][2]) {
  
    int i;
    int help;
    int curbombs[SIDE*SIDE];
  
    for (i=0; i<SIDE*SIDE; i++)
        curbombs[i] = 0;
    
    // Keeps track of number of bombs currently placed.  
    i = 0;
 
    // Continue until all random bombs have been created.
    while(i<NUMBOMBS) {
    
        help = rand()%(SIDE*SIDE);

        // Only add the bomb if it is not a duplicate.
        if (curbombs[help]==0) {
      
            bomblist[i][0] = help/SIDE;
            bomblist[i][1] = help%SIDE;
            i++;
            curbombs[help] = 1;
        }
    }
}
