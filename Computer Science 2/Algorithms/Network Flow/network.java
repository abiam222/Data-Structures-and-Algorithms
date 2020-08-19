// Arup Guha
// 8/24/2011
// Uses Edmunds-Karp Algorithm to calculate Maximum Flow in a Flow Network.

import java.util.*;

class Edge {

	private int capacity;
	private int flow;

	public Edge(int cap) {
		capacity = cap;
		flow = 0;
	}

	public int maxPushForward() {
		return capacity - flow;
	}

	public int maxPushBackward() {
		return flow;
	}

	public boolean pushForward(int moreflow) {

		// We can't push through this much flow.
		if (flow+moreflow > capacity)
			return false;

		// Push through.
		flow += moreflow;
		return true;
	}

	public boolean pushBack(int lessflow) {

		// Not enough to push back on.
		if (flow < lessflow)
			return false;

		flow -= lessflow;
		return true;
	}
}

class direction {

	public int prev;
	public boolean forward;

	public direction(int node, boolean dir) {
		prev = node;
		forward = dir;
	}

	public String toString() {
		if (forward)
			return "" + prev + "->";
		else
			return "" + prev + "<-";
	}
}

public class networkflow {
	
	private final static boolean DEBUG = false;
	private final static boolean PRINTPATH = true;

	private Edge[][] adjMat;
	private int source;
	private int dest;

	// All positive entries in flows should represent valid flows
	// between vertices. All other entries must be 0 or negative.
	public networkflow(int[][] flows, int start, int end) {

		source = start;
		dest = end;
		adjMat = new Edge[flows.length][flows.length];

		for (int i=0; i<flows.length; i++) {
			for (int j=0; j<flows[i].length; j++) {

				// Fill in this flow.
				if (flows[i][j] > 0)
					adjMat[i][j] = new Edge(flows[i][j]);
				else
					adjMat[i][j] = null;
			}
		}
	}

	public ArrayList<direction> findAugmentingPath() {

		// This will store the previous node visited in the BFS.
		direction[] prev = new direction[adjMat.length];
		boolean[] inQueue = new boolean[adjMat.length];
		for (int i=0; i<inQueue.length; i++)
			inQueue[i] = false;

		// The source has no previous node.
		prev[source] = new direction(-1, true);

		LinkedList<Integer> bfs_queue = new LinkedList<Integer>();
		bfs_queue.offer(new Integer(source));
		inQueue[source] = true;

		// Our BFS will go until we clear out the queue.
		while (bfs_queue.size() > 0) {

			// Add all the new neighbors of the current node.
			Integer next = bfs_queue.poll();
			if (DEBUG) System.out.println("Searching " + next);

			// Find all neighbors and add into the queue. These are forward edges.
			for (int i=0; i<adjMat.length; i++)
				if (!inQueue[i] && adjMat[next][i] != null && adjMat[next][i].maxPushForward() > 0) {
					bfs_queue.offer(new Integer(i));
					inQueue[i] = true;
					prev[i] = new direction(next, true);
				}

			// Now look for back edges.
			for (int i=0; i<adjMat.length; i++)
				if (!inQueue[i] && adjMat[i][next] != null && adjMat[i][next].maxPushBackward() > 0) {
					bfs_queue.offer(new Integer(i));
					inQueue[i] = true;
					prev[i] = new direction(next, false);
				}
		}

		// No augmenting path found.
		if (!inQueue[dest])
			return null;

		ArrayList<direction> path = new ArrayList<direction>();

		direction place = prev[dest];

		direction dummy = new direction(dest, true);
		path.add(dummy);

		// Build the path backwards.
		while (place.prev != -1) {
			path.add(place);
			place = prev[place.prev];
		}

		// Reverse it now.
		Collections.reverse(path);

		return path;
	}

	// Run the Max Flow Algorithm here.
	public int getMaxFlow() {

		int flow = 0;

		ArrayList<direction> nextpath = findAugmentingPath();
		
		if (DEBUG || PRINTPATH) {
			System.out.println("Found one augmenting path.");
			for (int i=0; i<nextpath.size(); i++)
				System.out.print(nextpath.get(i)+" ");
			System.out.println();
		}
		
		// Loop until there are no more augmenting paths.
		while (nextpath != null) {

			// Check what the best flow through this path is.
			int this_flow = Integer.MAX_VALUE;
			for (int i=0; i<nextpath.size()-1; i++) {

				if (nextpath.get(i).forward) {
					this_flow = Math.min(this_flow, adjMat[nextpath.get(i).prev][nextpath.get(i+1).prev].maxPushForward());
				}
				else {
					this_flow = Math.min(this_flow, adjMat[nextpath.get(i+1).prev][nextpath.get(i).prev].maxPushBackward());
				}
			}

			// Now, put this flow through.
			for (int i=0; i<nextpath.size()-1; i++) {

				if (nextpath.get(i).forward) {
					adjMat[nextpath.get(i).prev][nextpath.get(i+1).prev].pushForward(this_flow);
				}
				else {
					adjMat[nextpath.get(i+1).prev][nextpath.get(i).prev].pushBack(this_flow);
				}
			}

			// Add this flow in and then get the next path.
			if (DEBUG || PRINTPATH) System.out.println("Adding "+this_flow);
			flow += this_flow;
			nextpath = findAugmentingPath();
			if (nextpath != null && (DEBUG || PRINTPATH)) {

				System.out.println("Found another augmenting path.");
				for (int i=0; i<nextpath.size(); i++)
					System.out.print(nextpath.get(i)+" ");
				System.out.println();
			}

		}

		return flow;
	}

	// Test my algorithm!
	public static void main(String[] args) {

		int[][] graph = new int[6][6];
		graph[0][1] = 16;
		graph[0][2] = 13;
		graph[1][2] = 10;
		graph[2][1] = 4;
		graph[1][3] = 12;
		graph[3][2] = 9;
		graph[2][4] = 14;
		graph[3][5] = 20;
		graph[4][3] = 7;
		graph[4][5] = 4;

		networkflow mine = new networkflow(graph, 0, 5);

		int answer = mine.getMaxFlow();

		System.out.println("The flow is "+answer);

		graph = new int[10][10];
		graph[0][1] = 3;	graph[1][6] = 2; 	graph[1][7] = 5;
		graph[0][2] = 7;	graph[2][5] = 4;	graph[2][8] = 6;
		graph[0][3] = 12;	graph[3][6] = 8;	graph[3][7] = 5;
		graph[0][4] = 6; 	graph[4][8] = 9;

		graph[5][9] = 8;	graph[6][9] = 5;	graph[7][9] = 6;	graph[8][9] = 7;

		mine = new networkflow(graph, 0, 9);
		answer = mine.getMaxFlow();
		System.out.println("Second flow is "+answer);
	}

}
