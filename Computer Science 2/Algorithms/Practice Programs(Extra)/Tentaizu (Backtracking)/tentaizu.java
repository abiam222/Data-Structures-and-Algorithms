// Arup Guha
// 2/15/2013
// Solution to 2010 UCF High School Contest Problem: Tentaizu

import java.util.*;

public class tentaizu {

	final public static int N = 7;
	final public static int TOTALBOMBS = 10;

	private char[] board;

	// Creates a board from b, assuming b is size NxN storing the
	// values of each square in standard row, col order.
	public tentaizu(String b) {
		board = new char[N*N];
		for (int i=0; i<N*N; i++)
			board[i] = b.charAt(i);
	}

	// Wrapper Function.
	public void solve() {
		solveRec(0, 0);
	}

	public boolean solveRec(int sq, int numbombs) {

		// Fail cases just based on the number of bombs
		if (numbombs + N*N - sq < TOTALBOMBS) return false;
		if (sq == N*N && numbombs != TOTALBOMBS) return false;
		if (numbombs > TOTALBOMBS) return false;

		// Answer based on consistency of board.
		boolean okay = consistent(sq, numbombs);
		if (!okay) return false;
		if (numbombs == TOTALBOMBS) return true;

		// Can't place a bomb here, there is a number.
		if (board[sq] != '.' || zero(sq)) {
			return solveRec(sq+1, numbombs);
		}
		else {

			boolean result = false;

			// Try placing a bomb here.
			board[sq] = '*';
			result = solveRec(sq+1, numbombs+1);

			// A bomb in sq worked, return true!
			if (result) return true;

			// The bomb here didn't work, try without it.
			board[sq] = '.';
			return solveRec(sq+1, numbombs);
		}
	}

	// See if the result of filling board[0..sq-1] with numbombs is consistent with a valid answer.
	public boolean consistent(int sq, int numbombs) {

		// Look for numbers.
		for (int i=0; i<board.length; i++) {

			// In here, check if this number is correct.
			if (board[i] >= '0' && board[i] <= '9') {

				int row = i/N;
				int col = i%N;

				int cnt = 0;
				for (int x=row-1; x<=row+1; x++) {
					for (int y=col-1; y<=col+1; y++) {
						if (inbounds(x,y) && board[N*x+y] == '*')
							cnt++;
					}
				}

				// Check a bad full board and a square surrounded by too many bombs.
				if ((sq == N*N || numbombs == TOTALBOMBS) && (char)(cnt + '0') != board[i]) return false;
				if ((char)(cnt + '0') > board[i] ) return false;

				// This is key: Check an incomplete board with a impossible answer.
				// Our bomb count is accurate to sq-N-1...
				if (i < sq-N-1 && (char)(cnt + '0') != board[i]) return false;
			}
		}
		return true;
	}

	// Returns true iff board[sq] definitively doesn't have a bomb.
	public boolean zero(int sq) {

		int row = sq/N;
		int col = sq%N;

		int cnt = 0;
		for (int x = row-1; x<=row+1; x++) {
			for (int y=col-1; y<=col+1; y++) {
				if (inbounds(x,y)) {
					if (board[N*x+y] == '0')
						return true;
				}
			}
		}
		return false;
	}

	// Sees if coordinate (x,y) is within the bounds of the board.
	public boolean inbounds(int x, int y) {
		return x >= 0 && x < N && y >= 0 && y < N;
	}

	// Returns the object as it is to be printed for the problem.
	public String toString() {
		String ans = "";
		for (int i=0; i<board.length; i++) {
			if (i%N == 0 && i > 0) ans = ans + "\n";
			ans = ans + board[i];
		}
		return ans+"\n";
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numBoards = stdin.nextInt();

		// Process all cases.
		for (int loop=1; loop<=numBoards; loop++) {

			// Read in the board and create a tentaizu object.
			String b = "";
			for (int i=0; i<N; i++)
				b= b + stdin.next();
			tentaizu myBoard = new tentaizu(b);

			// Solve and print!
			myBoard.solve();
			System.out.println("Tentaizu Board #"+loop+":");
			System.out.println(myBoard);
		}
	}
}
