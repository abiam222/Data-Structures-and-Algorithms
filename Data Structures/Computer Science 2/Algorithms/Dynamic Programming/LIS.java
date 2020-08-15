// Arup Guha
// 4/4/2013
// Longest Non-Decreasing Sequence DP

import java.util.*;

public class LIS {

	public static void main(String[] args) {

		int[] a = {2,8,4,3,4,9,6,5,7,12,13,8,1};

		System.out.println("Longest non-decreasing sequence length is "+longNDSeq(a));
	}

	public static int longNDSeq(int[] array) {

		int n = array.length;
		int[] dp = new int[n];

		// Just take first item.
		dp[0] = 1;

		// Solve each case in order.
		for (int i=1; i<n; i++) {

			int best = 1;

			// Try to build off shorter sequences.
			for (int j=0; j<i; j++) {

				// We can build off this one and it's longer.
				if (array[j] <= array[i] && dp[j]+1 > best)
					best = dp[j] + 1;
			}

			// Store the best answer for this case.
			dp[i] = best;
		}

		// Find the best of all the sequences.
		int best = dp[0];
		for (int i=1; i<n; i++)
			if (dp[i] > best)
				best = dp[i];

		return best;
	}

}
