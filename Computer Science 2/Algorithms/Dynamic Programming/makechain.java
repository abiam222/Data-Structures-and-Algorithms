// Arup Guha
// 4/11/2013
// Program for "Make Chain Problem", similar to MCM, using memoization

/*** The Problem
 *
 *   You are given a list of components in order that need to be fastened.
 *   Each component just has a weight. Eventally, all of the components need
 *   to be fused into one. The cost of fusing two components of weights x and y
 *   is xy/(x+y). Determine the minimum cost of fusing all the components together.
 *
 *   For example, for the sequence 3 6 9:
 *
 *   If we fuse as follows: ((3 6) 9), then the first fusion costs 18/9 = 2 while the
 *   second costs 81/18 = 4.5, for a total cost of 6.5
 *
 *   If we fuse (3 (6 9)) instead, our cost is 54/15 + 45/18 = 3.6 + 2.5 = 6.1.
 *
 *   Thus, the best answer for this case is 6.1
 *
 ***/

 /*** Input File Format:
  *
  *   First line has an integer with the number of test cases.
  *   The first line of each test case has an integer n, the number of components for that case.
  *   The second line of each test case has the weight of each component, in order.
  *
  ***/

import java.util.*;

public class makechain {

	// Both used and frequently accessed in our solution.
	public static double[][] memo;
	public static int[] sumArray;

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		// Go through the cases.
		for (int loop=0; loop<numCases; loop++) {

			int n = stdin.nextInt();
			int[] weights = new int[n];
			for (int i=0; i<n; i++)
				weights[i] = stdin.nextInt();

			// Create cumulative frequency array.
			sumArray = new int[n+1];
			for (int i=1; i<sumArray.length; i++)
				sumArray[i] = sumArray[i-1] + weights[i-1];

			// Initialize the memo array.
			memo = new double[n][n];
			for (int i=0; i<n; i++) {
				Arrays.fill(memo[i], -1);
				memo[i][i] = 0;
			}

			// Solve and print.
			System.out.printf("%.2f\n", solveRec(weights, 0, n-1));
		}
	}

	// Returns the best answer for the sequence original[start...end].
	public static double solveRec(int[] original, int start, int end) {

		// Don't resolve old cases.
		if (memo[start][end] >= 0)
			return memo[start][end];

		double best = -1;

		// Try each split.
		for (int split=start; split<end; split++) {

			// Calculate the cost of [start, split] join [split+1,end].
			int sumLeft = getSum(start, split);
			int sumRight = getSum(split+1, end);
			double cost = solveRec(original, start, split) + solveRec(original, split+1, end)
				                                           + (double)sumLeft*sumRight/(sumLeft + sumRight);
			// Update if this one's better.
			if (best < 0 || cost < best)
				best = cost;
		}

		// Store and return.
		memo[start][end] = best;
		return best;
	}

	// Uses the cumulative sum array to return the sum of a contiguous subsequence.
	public static int getSum(int start, int end) {
		return sumArray[end+1] - sumArray[start];
	}
}
