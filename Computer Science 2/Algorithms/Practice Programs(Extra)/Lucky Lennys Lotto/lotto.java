// Arup Guha
// Written on 10/8/05 during UCF Programming Team Practice
// Edited on 11/8/05 for COP 3530 Take Home Exam Solution

// Edited on 12/7/09 to fit new i/o format.

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class lotto {


  public static void main(String[] args) throws IOException {

      // Open the input file.
	BufferedReader fin = new BufferedReader(new FileReader("lotto.in"));

	int i,j,n,m,sets,k;

	// Pre-solve all possible test cases using a dynamic programming solution.
    // The entry dp[i][j] will store the number of lotto combinations of i numbers
    // with the largest number being j. To answer any specific query, we must simply 
    // sum all the values in the appropriate row upto the correct column. For example,
    // the number of combinations of 5 values all with numbers less than or equal to 100
    // would equal dp[5][0]+dp[5][1]+dp[5][2]+...+dp[5][100]. We can either calculate 
    // this sum on the fly, or precalculate it.

	BigInteger[][] dp = new BigInteger[11][2001];
	BigInteger zero = new BigInteger("0");
	BigInteger one = new BigInteger("1");

	// These are extra base cases for when there are 0 possible lotto tickets.
	for (i=0; i<=200; i++)
		dp[0][i] = zero;
	for (i=0; i<=10; i++)
		dp[i][0] = zero;

	// Initialize the regular base cases: The first row of the table.
	for (i=1; i<=2000; i++)
		dp[1][i] = one;

      // Just set the rest to zero initially. This case isn't necessary.
	for (i=2; i<=10; i++)
		for (j=1; j<=2000; j++)
			dp[i][j] = zero;

      // Loop through each row of the table.
	for (i=2; i<=10; i++) {

            // Loop through each column of the table.
		for (j=1; j<=2000; j++) {

                  // Here's the crux of the solution. To determine the number of combinations
 		      // that have i values with the largest value j, we KNOW we must fill in j
		      // for the last value. This leaves i-1 values to fill in. Of these values
			// the last value of the remaining i-1 could be anywhere from 1 to j/2,
			// inclusive, thus, the number of combos needed here is simply the sum of
			// the number of ways to choose i-1 numbers with the last number ranging
			// from 1 to j/2, inclusive.
			for (k=1; k<=j/2; k++)
				dp[i][j] = dp[i][j].add(dp[i-1][k]);

		}
	}

	// Now that we have all possible answers stored, just process each case.
	
	// Read in the current test case.
	StringTokenizer tok = new StringTokenizer(fin.readLine());
	n = Integer.parseInt(tok.nextToken());
	m = Integer.parseInt(tok.nextToken());
	
	i = 1;
	while (n!=0 || m != 0) {

		// ans will accumulate the actual answer.
		BigInteger ans = zero;

		// Add up all lotto combinations of n numbers that have the last number 1, 2, n,..., m.
		for (j=1; j<=m; j++)
			ans = ans.add(dp[n][j]);

		System.out.println("Case "+i+": n = "+n+", m = "+m+", # lists = "+ans);
		
		// Get the next case.
		tok = new StringTokenizer(fin.readLine());
		n = Integer.parseInt(tok.nextToken());
		m = Integer.parseInt(tok.nextToken());
		i++;
	}
  }
}
