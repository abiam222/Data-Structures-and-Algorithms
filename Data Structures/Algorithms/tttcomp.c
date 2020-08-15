// Arup Guha
// 2/13/08

// This program is a revised version of the tic-tac-toe program created for
// COP 3223 on 11/5/03. In particular, this program employs a computer player
// for team 'O' instead of a human player. It uses the backtracking technique
// to find an optimal move for the computer.

// Known Bugs: Some error checking is done, but users must still enter the
//             correct type of information desired in the proper format.
//             For example, if the user enters their square as 1,2 instead
//             of 1 2 as specified, a run-time error will occur.



#include <stdio.h>

#define SIZE 3
#define UNFINISHED 0
#define WINX 1
#define WINO 2
#define CATS 3
#define WIN 1
#define LOSS -1
#define TIE 0

void init(char board[][3]);
void printboard(char board[][3]);
void domove(char board[][3], char player);
int status(char board[][3]);
int checkrows(char board[][3], char player);
int checkcols(char board[][3], char player);
int checkdiag(char board[][3], char player);
int hasmoveleft(char board[][3]);
char getplayer(int turn);
char other(char player);
int isvalid(char board[][3], int r, int c);
int compmove(char board[][3], char piece);
int score(char board[][3], char piece);

int main() {

    char board[3][3];
    int i,j, result;
    int turn = 0; // Set the current turn to player X

    init(board);
  
    // Play until the game is over.
    while (status(board) == UNFINISHED) {

        // Execute a turn and change who's move it is.
        domove(board, getplayer(turn));
        turn = (turn+1)%2;
    }

    result = status(board);
  
    printf("\nHere is the final board:\n");
    printboard(board);

    // Output the appropriate message for each possible outcome.
    if (result == WINX)
        printf("Congrats team X, you won!\n");
    else if (result == WINO)
        printf("Congrats team O, you won!\n");
    else
        printf("Good job to both teams, the outcome is a tie!\n");

  system("PAUSE");
  return 0;
}

// Returns the character corresponding to the player number. Player 0 is
// character 'X' and player 1 is character 'O'.
char getplayer(int turn) {
  
    if (turn == 0)
        return 'X';
    return 'O';
}

// Pre-condition: player must be 'X' or 'O'
// Post-condition: The opposite player's symbol will be returned.
char other(char player) {
     
    if (player == 'X')
        return 'O';
    return 'X';
}

// Initializes the board to hold all underscore('_') characters.
void init(char board[][3]) {
  
    int i, j;
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
            board[i][j] = '_';
}

// Prints out the board in a readable format with rows and columns
// labelled.
void printboard(char board[][3]) {
     
    int i, j;

    // Print out labels.
    printf("Col->\t0 1 2\n");
    printf("Row\n");

    // Print out each board entry.
    for (i=0; i<SIZE; i++) {
    
        printf("%d\t",i);
        for (j=0; j<SIZE; j++)
            printf("%c ",board[i][j]);
        printf("\n");
    }
} 

// Executes a move for the player specified by the second parameter and
// reflects those changes on the board.
void domove(char board[][3], char player) {

    int done = 0;
    int r, c, temp;

    // Continue until a move has been executed.
    while (!done) {

        // Human player is X.
        if (player == 'X') {
                   
            // Prompt for and read in the player's move.
            printf("\nHere is the current board:\n");
            printboard(board);   
            printf("\nEnter your move, player %c.\n", player);
            printf("Enter the row(0-2) followed by a space and the col(0-2).\n");
            scanf("%d%d", &r, &c);
        }
    
        // Computer Player is O
        else {
        
            // Get the computer's move, split into row&col and print it.     
            temp = compmove(board, player);
            r = temp/3;
            c = temp%3;   
            printf("\nThe computer has chosen to take square %d, %d.\n", r, c);
        }
    
        // Check for invalid indexes.
        if (r<0 || r>2 || c<0 || c>2)
            printf("Sorry, that is not a valid square.\n");

        // Check for a taken square.
        else if (board[r][c] != '_')
            printf("Sorry, that square has been taken already.\n");

        // Execute the move.
        else {
      
            board[r][c] = player;
            done=1;
        }
        
    } // end while loop
}

// Returns the status of the board. Either X has won, O has won, the game
// is unfinished or it's a cats game.
int status(char board[][3]) {

    // X wins!
    if (checkrows(board,'X') || checkcols(board,'X') || checkdiag(board,'X'))
        return WINX;
    
    // O wins!
    if (checkrows(board,'O') || checkcols(board,'O') || checkdiag(board,'O'))
        return WINO;
    
    // Game in progress.
    if (hasmoveleft(board))
        return UNFINISHED;
    
    // Must be a cats game!    
    return CATS;
}

// Returns 1 if there is a blank square on the board, 0 otherwise.
int hasmoveleft(char board[][3]) {

    int i,j;

    // Check for blank square.
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
            if (board[i][j] == '_')
                return 1;
  
    // Only gets here if none are found.
    return 0; 
}

// Returns true if player has all three squares in any row.
int checkrows(char board[][3], char player) {

    int row, col, check;

    // Check all rows one by one, to see if player has all squares.
    for (row=0; row<SIZE; row++) {
    
        check = 0;
        for (col=0; col<SIZE; col++)

            // Count all squares that player has on a row.
            if (board[row][col] == player)    
                check++;
   
        // Player has all squares on a row.
        if (check == SIZE)
            return 1;
    }
  
    // No full rows found.
    return 0;
}

// Returns true if player has all three squares in any row.
int checkcols(char board[][3], char player) {

    int row, col, check;
  
    for (col=0; col<SIZE; col++) {
    
        check = 0;
        for (row=0; row<SIZE; row++)

            // Count # squares player has on a column.
            if (board[row][col] == player)    
                check++;
   
        // Player has all squares on a column.
        if (check == SIZE)
            return 1;
    }
  
    // No full columns found.
    return 0;
}

// Returns 1 if player owns a diagonal, 0 otherwise.
int checkdiag(char board[][3], char player) {

    int row;
    int check=0;

    // Check forward diagonal.
    for (row=0; row<SIZE; row++)
        if (board[row][row] == player)
            check++;
  
    // Forward diagonal is full.
    if (check == SIZE)
        return 1;

    // Check backward diagonal.
    check=0;
    for (row=0; row<SIZE; row++)
        if (board[SIZE-1-row][row] == player)
            check++;
  
    // Backward diagonal is full.
    if (check == SIZE)
        return 1;

  return 0;
}

// Pre-condition: 0 <= r,c, < 3
// Post-condition: Returns true iff the location r,c on the board isn't taken.
int isvalid(char board[][3], int r, int c) {
    
    // Avoid array out of bounds.
    if (r < 0 || r > 2 || c < 0 || c > 2) return 0;
    
    return board[r][c] == '_';   
}

// Pre-condition: The board is in valid configuration for a tic-tac-toe game
//                that ISN't FINISHED, where the next move is going to be 
//                made by piece.
// Post-condition: The recommended move by the computer for piece will be 
//                 returned. The value returned will be in between 0 and 8,
//                 inclusive, where the value/3 represents the row of the
//                 move and value%3 represents the column of the move.
int compmove(char board[][3], char piece) {
    
    int i=0;
    int scoremove;
    int bestmove = 0, bestscore = LOSS;
    int gotmove = 0;
    
    // Try each move!
    for (i=0; i<9; i++) {
        
        // We only do the move if it's a possible one.
        if (isvalid(board, i/3, i%3)) {
                
            // Temporarily place the piece here so we can try to score this
            // move.
            board[i/3][i%3] = piece;
            
            // Score this move.
            scoremove = score(board, piece);
                   
            // Update our best if we find something better than before!
            if (scoremove > bestscore || gotmove == 0) {
                bestscore = scoremove;
                bestmove = i;              
            }
                           
            // Restore the board to its correct configuration, now that we are
            // done trying that piece out.
            board[i/3][i%3] = '_';
            
            gotmove = 1; // Indicate that we have one valid move stored.
                           
        } // end if-isvalid
    } // end-for
    
    return bestmove;
}

// Pre-condition: board is in a valid configuration for a tic-tac-toe game,
//                right after piece just moved.
// Post-condition: A score will be returned corresponding to the score of 
//                 piece's position in the current board.
int score(char board[][3], char piece) {
 
    // Figure out the status now.
    int curstatus = status(board);
    int nextmove, answer;
    
    // If the game is over, we can easily return our answer.
    if (curstatus == WINX && piece == 'X')
        return WIN;
    if (curstatus == WINO && piece == 'O')
        return WIN;
    if (curstatus == WINX && piece == 'O')
        return LOSS;
    if (curstatus == WINO && piece == 'X')
        return LOSS;
    if (curstatus == CATS)
        return TIE;
        
    // Otherwise, assume the opponents move will be the one the computer
    // selects.
    nextmove = compmove(board, other(piece));
    
    // Place this new move on the board.
    board[nextmove/3][nextmove%3] = other(piece);
    
    // Return the OPPOSITE score, since this time, the score function will be
    // scoring our opponent!
    answer = -score(board, other(piece));
    
    // Restore the board to what it looked like before.
    board[nextmove/3][nextmove%3] = '_';
    
    return answer;          
}
