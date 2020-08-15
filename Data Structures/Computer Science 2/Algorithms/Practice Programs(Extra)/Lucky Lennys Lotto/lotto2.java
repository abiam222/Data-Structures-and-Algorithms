// Arup Guha
// Written on 10/8/05 during UCF Programming Team Practice
// Edited on 11/8/05 for COP 3530 Take Home Exam Solution
// Edited on 12/7/09 for slightly different I/O Spec for Honors CS 2 Contest.

// lotto2.java: slightly different solution that uses a slightly different 
//				recursive characterization of the problem. This method is  
//				more efficient as it saves one nested loop in the   
//				computation of the table. A student in the class helped me  
//				come up with this solution.

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class lotto2 {


  	public static void main(String[] args) throws IOException {

      	// Open the input file.
  		BufferedReader fin=new BufferedReader(new FileReader("lotto2.in"));

		int i,j,n,m,sets,k;

		// Pre-solve all possible test cases using a dynamic prog sol.
      	// The entry dp[i][j] will store the number of lotto combos of i 
      	// numbers with the largest number being less than or equal to j.  
      	// To answer any specific query, we must simply return dp[n][m].

		BigInteger[][] dp = new BigInteger[11][2001];
		BigInteger zero = new BigInteger("0");
		BigInteger one = new BigInteger("1");

		// These are extra base cases for 0 possible lotto tix.
		for (i=0; i<=200; i++)
			dp[0][i] = zero;
		for (i=0; i<=10; i++)
			dp[i][0] = zero;

		// Initialize the regular base cases: The first row of the table, 
		// the entry in column i will be i, because the i lotto tickets  
		// with one number that have the largest number i or less is i.
      	// The tickets are 1, 2, 3, ..., i.
		for (i=1; i<=2000; i++)
			dp[1][i] = dp[1][i-1].add(one);

      	// Just set the rest to zero initially. This case isn't necessary.
		for (i=2; i<=10; i++)
			for (j=1; j<=2000; j++)
				dp[i][j] = zero;

      	// Loop through each row of the table.
		for (i=2; i<=10; i++) {

            // Loop through each column of the table.
			for (j=1; j<=2000; j++) {

            	// Here's the crux of the solution. To determine the  
            	// number of combinations that have i values with the  
            	// largest value j or less, we can split our counting  
            	// into 2 cases: all combos with i values that have a  
            	// largest value or j-1 OR less, AND all combos with i 
            	// values with the largest value j.
				// If the largest value is j, then we have i-1 values  
				// left to fill up, and all of these simply have to be  
				// less than or equal to j/2. Luckily, this is a subproblem  
				// that we already have a solution for.
				dp[i][j] = dp[i][j-1].add(dp[i-1][j/2]);

			}
		}

		// Now that we have all answers stored, just process each case.
		for (i=1;; i++) {

			// Read in the current test case.
			StringTokenizer tok = new StringTokenizer(fin.readLine());
			n = Integer.parseInt(tok.nextToken());
			m = Integer.parseInt(tok.nextToken());
			
			// Get out, if we need to, or output result.
			if (m == 0 && n == 0) break;
			System.out.println("Case "+i+": n = "+n+", m = "+m+", # lists = "+dp[n][m]);			
		}
  	}
}
