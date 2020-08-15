// Arup Guha
// 2/21/2013
// Alternate (and better) solution to 2012 Mercer Programming Contest Problem #9: Prefix Free Set

/*** After I solved the problem in a convoluted way, Satej told me the greedy solution, which is
 *   implemented here. Basically, we always want to "expand" all minimal cost nodes. At no time
 *   while we solve the problem do we have nodes in our tree storing all strings (each leaf is a
 *   string) with costs that differ by more than 4.
 ***/
 
 import java.util.*;
 
 public class prefix {
 	
 	// We actually only need an array of size 61, since is a safe overestimate.
 	final public static int SIZE = 100;
 	final public static int COSTA = 1;
 	final public static int COSTB = 4;
 	
 	public static void main(String[] args) {
 		
 		Scanner stdin = new Scanner(System.in);
 		int numCases = stdin.nextInt();
 		
 		// Solve each case.
 		for (int loop=0; loop<numCases; loop++) {
 			int n = stdin.nextInt();
 			System.out.println(n+": "+solve(n));
 		}
 	}
 	
 	// Uses a greedy strategy of growing an optimal tree to calculate f(n),
 	// the minimal cost of a prefix free set of n words.
 	public static long solve(int n) {
 		
 		// Simple base cases.
 		if (n == 1) return Math.min(COSTA, COSTB);
 		if (n == 2) return COSTA + COSTB;
 		
 		// freq[i] will store the number of words with cost i at any given point
 		// in time.
 		int[] freq = new int[SIZE];
 		
 		// We start with a tree with 2 nodes(a, b), costs 1 and 4, respectively.
 		freq[COSTA] = 1;
 		freq[COSTB] = 1;
 		
 		// Other initial values.
 		int min = 1;
 		int curTotal = 2;
 		long curCost = 5;
 		
 		// We'll cut out when we get to n.
 		while (curTotal < n) {
 			
 			// Expand the necessary number of nodes, updating all variables.
 			int next = Math.min(n - curTotal, freq[min]); 
 			freq[min] -= next;
 			
 			// Add to the number of words with costs min+COSTA and min+COSTB.
 			freq[min+COSTA] += next;
 			freq[min+COSTB] += next;
 			
 			// New total number of nodes in the tree.
 			curTotal += next;
 			
 			// We incur the new cost of the last two letters a and b, as
 			// well as the cost of min since we're adding a whole new word
 			// and using the old prefix twice.
 			curCost += ((long)next)*(COSTA+COSTB+min);
 			min++;
 		}
 		
 		return curCost;
 	}
 }
