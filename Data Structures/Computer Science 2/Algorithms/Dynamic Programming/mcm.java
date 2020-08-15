// Arup Guha
// 12/1/2006
// Written for COP 3503 Final Exam

import java.util.*;

class Pair {
	
	public int rows;
	public int cols;
	
	public Pair(int r, int c) {
		rows = r;
		cols = c;
	}
}

public class mcm {
	
	private Pair[] dim;
	
	public mcm() {

		// Get user input.
		Scanner stdin = new Scanner(System.in);
		System.out.println("Enter the number of matrices.");
		int nummatrices = stdin.nextInt();
		
		// Store relevant matrix information here.
		dim = new Pair[nummatrices];
		
		System.out.println("Enter each dimension in order.");
		System.out.println("You should enter "+(nummatrices+1)+" values.");
		int firstrow = stdin.nextInt();
		
		// Loop to use inner dimensions twice.
		for (int i=0; i< nummatrices; i++) {
			int seconddim = stdin.nextInt();
			dim[i] = new Pair(firstrow, seconddim);
			firstrow = seconddim;
		}
	}
	
	// Run the program.
	public static void main(String[] args) throws Exception {
		mcm mine = new mcm();
		int answer = mine.runAlg();
		System.out.println("The answer is "+answer);
	}
	
	public int runAlg() {
		int[][] minMult = new int[dim.length][dim.length];
		
		for (int i=0; i<minMult.length; i++)
			minMult[i][i] = 0;
			
		// c = number of matrices in the subproblem
		for (int c = 1; c < minMult.length; c++) {
			
			for (int start = 0; start < minMult.length-c; start++) {
				
				// Calculating the min. multiplications for the matrices
				// Matrix # start through Matrix # start+offset
				int min = -1;
				
				for (int offset=start; offset<start+c; offset++) {
				
					// Make the calculation for # of mults.
					// Mults o to s
					// Mults s+1 to o+c
					// Mults for the last matrix mult
					int value = minMult[start][offset]+minMult[offset+1][start+c] + dim[start].rows*dim[offset].cols*dim[start+c].cols;
					
					if (min == -1)
						min = value;
					else if (value < min)
						min = value;		
				}
				minMult[start][start+c] = min;
				
			}
		}
		
		// This is our best answer.
		return minMult[0][minMult.length-1];
	}
}
