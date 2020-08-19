// Arup Guha
// 6/21/2012
// Solution to 2009 SER Problem: Museum Guards
// Edited to use binary search to find # of guards. Runs in 15 seconds on my laptop.

import java.util.*;

public class c2 {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int n = stdin.nextInt();

		while (n != 0) {

			// 0 = source, s-1 = sink, 1-n guards, n+1 -> n+48 shifts
			int s = n + 2 + 48;
			int[][] graph = new int[s][s];
			for (int i=0; i<s; i++)
				Arrays.fill(graph[i], 0);

			// Read in each guard.
			for (int i=0; i<n; i++) {
				int shifts = stdin.nextInt();
				int max = stdin.nextInt();
				boolean[] available = new boolean[1440];
				Arrays.fill(available, false);

				// Fill in guard's availability.
				for (int j=0; j<shifts; j++) {
					String t1 = stdin.next();
					String t2 = stdin.next();
					fillArray(convert(t1), convert(t2), available);
				}

				// Convert the minutes to 30 minute availability slots.
				int[] slots = getSlots(available);

				// These are the flows we want.
				graph[0][i+1] = max/30;
				for (int j=0; j<slots.length; j++) {
					graph[i+1][n+1+j] = slots[j];
				}
			}

			// Try 0 guards, then 1, etc.
			if (!solvable(graph, n, 1))
				System.out.println("0");
			else {

				int low = 1;
				int high = 51;
				int mid = (low + high)/2;

				// Run a binary search to find the lowest value that is unsolvable.
				while (low < high) {
					if (solvable(graph, n, mid))
						low = mid+1;
					else
						high = mid;
					mid = (low+high)/2;
				}
				System.out.println(low-1);
			}

			n = stdin.nextInt();
		}
	}

	// Returns true iff we can cover each shift with tryval guards.
	public static boolean solvable(int[][] graph, int n, int tryval) {

		// Fill in the flows from all the shifts to the sink.
		int s = graph.length;
		for (int j=0; j<48; j++) {
			graph[n+1+j][s-1] = tryval;
		}

		// Get the flow and see if each shift can be covered with tryval guards.
		networkflow obj = new networkflow(graph, 0, s-1);
		int flow = obj.getMaxFlow();
		return flow == tryval*48;
	}

	// Returns the number of minutes after midnight represented by s.
	public static int convert(String s) {
		int hr = 10*(s.charAt(0) - '0') + s.charAt(1) - '0';
		int min = 10*(s.charAt(3) - '0') + s.charAt(4) - '0';
		return 60*hr + min;
	}

	// Fills available in interval [start, end) if start < end.
	// Or [start, 1439], [0, end) if end < start. Or all slots if start == end.
	public static void fillArray(int start, int end, boolean[] available) {

		// Easy case.
		if (start == end) Arrays.fill(available, true);

		// Standard case.
		if (start < end) {
			for (int i=start; i<end; i++)
				available[i] = true;
		}

		// Loop through midnight.
		else {
			for (int i=0; i<end; i++)
				available[i] = true;
			for (int i=start; i<available.length; i++)
				available[i] = true;
		}
	}

	// Convert minute availability to 30 minute time slots.
	public static int[] getSlots(boolean[] array) {

		int[] slots = new int[48];
		for (int i=0; i<slots.length; i++) {

			// Make sure we can make all 30 minutes before being available for this slot.
			int ans = 1;
			for (int j=0; j<30; j++)
				if (!array[30*i+j]) {
					ans = 0;
					break;
				}
			slots[i] = ans;
		}
		return slots;
	}
}

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

class networkflow {

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
			flow += this_flow;
			nextpath = findAugmentingPath();
		}

		return flow;
	}
}
