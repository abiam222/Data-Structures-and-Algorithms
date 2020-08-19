// Arup Guha
// 3/2/2013
// Solution to UCF Practice Problem E: Cow Steeplechase
// Uses my previous network flow code to implement bipartite matching.

import java.io.*;
import java.util.*;

public class e {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();
		
		for (int loop=0; loop<numCases; loop++) {
		
			int n = stdin.nextInt();

			// Read in all lines.
			int[][] lines = new int[n][4];
			for (int i=0; i<n; i++)
				for (int j=0; j<4; j++)
					lines[i][j] = stdin.nextInt();

			// Our strategy is to do a maximum matching between the horizontal and vertical lines.
			// Our source will connect to all horizontal lines and our sink to all vertical lines.
			// We'll connect horizontal lines to vertical ones iff they intersect.

			int[][] adj = new int[n+2][n+2];

			// Capacities from source to horizontal line and vertical to sink.
			for (int i=1; i<=n; i++) {
				if (horizontal(lines[i-1]))
					adj[0][i] = 1;
				else
					adj[i][n+1] = 1;
			}

			// Try all pairs.
			for (int i=0; i<n; i++) {
				for (int j=i+1; j<n; j++) {

					// Try both orders of intersection.
					if (horizontal(lines[i]) && vertical(lines[j])) {
						if (intersect(lines[i], lines[j]))
							adj[i+1][j+1] = 1;
					}
					else if (vertical(lines[i]) && horizontal(lines[j])) {
						if (intersect(lines[j], lines[i]))
							adj[j+1][i+1] = 1;
					}
				}
			}

			// Get our answer. We need to subtract these out of all the lines, namely
			// the flow of this graph equals what we must remove.
			networkflow graph = new networkflow(adj, 0, n+1);
			int ans = graph.getMaxFlow();
			System.out.println(n-ans);
			
		}
	}

	public static boolean horizontal(int[] line) {
		return line[1] == line[3];
	}

	public static boolean vertical(int[] line) {
		return line[0] == line[2];
	}

	public static boolean intersect(int[] hline, int[] vline) {

		return Math.min(hline[0], hline[2]) <= vline[0] && Math.max(hline[0], hline[2]) >= vline[0] &&
			   Math.min(vline[1], vline[3]) <= hline[1] && Math.max(vline[1], vline[3]) >= hline[1];
	}
}

