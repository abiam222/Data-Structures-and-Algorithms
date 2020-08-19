// Arup Guha
// 4/2/2013
// Minimum Coins: 2 solutions (a) Divide and Conquer with Memoization and
//                            (b) Dynamic Programming

import java.util.*;

public class mincoins {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int[] coins = {2, 3, 5, 9, 12};
		System.out.println("Please enter n.");
		int n = stdin.nextInt();

		// Will store all answers here. -1 indicated unanswered.
		Integer[] ans = new Integer[n+1];
		Arrays.fill(ans, new Integer(-1));

		int myAns = minCoinsDP(n, coins);
		System.out.println("Answer is "+myAns);

	}

	public static Integer minCoinsDP(int n, int[] denom) {

		// Will store all answers here.
		Integer[] dp = new Integer[n+1];
		dp[0] = 0;

		// These are my impossible cases.
		for (int i=1; i<denom[0]; i++)
			dp[i] = null;

		// Calculate min coins for i cents, for each i.
		for (int i=denom[0]; i<=n; i++) {

			// Only try adding coins that don't exceed the total I am making change for.
			Integer best = null;
			for (int j=0; j<denom.length && denom[j]<=i; j++) {

				Integer temp = null;

				// Avoid null ptr error.
				if (dp[i-denom[j]] != null)
					temp = dp[i-denom[j]] + 1;
				else
					continue;

				// Only replace if this one is better.
				if (best == null || temp < best)
					best = temp;

			}

			// Store best answer for making change for i cents.
			dp[i] = best;
		}

		return dp[n];
	}

	public static Integer minCoins(int n, int[] denom, Integer[] memo) {

		// No more coins to give.
		if (n == 0) return 0;

		// Impossible case.
		if (n < denom[0]) return null;

		// Directly return previously solved cases.
		if (memo[n] != -1) return memo[n];



		Integer ans = null;

		// Go through option of giving each coin as change.
		for (int i=0; i<denom.length; i++) {

			// Try this case.
			Integer temp = minCoins(n-denom[i], denom, memo);
			if (temp != null) memo[n-denom[i]] = temp;

			// Set temp answer if this case is valid.
			int next = -1;
			if (temp != null)
				next = temp + 1;

			// Update our best, if necessary.
			if (next != -1) {
				if (ans == null || next < ans)
					ans = next;
			}
		}

		// Store answer in array, THEN return.
		memo[n] = ans;
		return ans;
	}
}
