// Arup Guha
// 1/22/2013
// Written in COP 3503 to illustrate a basic disjoint set class, w/o path compression.

import java.util.*;
import java.io.IOException;
import  java.util.*;

public class DisjointSet {

	// A little driver program to test our class.
	public static void main(String[] args) throws IOException{

		Scanner stdin = new Scanner(new File("/Users/macuser/UndergroundCables.txt"));

		System.out.println("How many items do you want in your Disjoint Set?");
		int n = stdin.nextInt();

		DisjointSet mySet = new DisjointSet(n);

		// Keep on going till the user wants to quit.
		while (true) {

			System.out.println("Do you want to quit(1=yes, 0=no)?");
			int ans = stdin.nextInt();
			if (ans == 1) break;

			// Get the two items to union.
			System.out.println("Which two items do you want to bring together, 0 through "+(n-1)+"?");
			int item1 = stdin.nextInt();
			int item2 = stdin.nextInt();

			// See if it worked!
			boolean result = mySet.union(item1, item2);

			if (!result) {
				System.out.println("Sorry, those were already together!");
			}
			else {
				System.out.println("The union was successful, here is the new parent list: "+mySet);
			}
		}
	}

	private pair[] parents;

	// Create the initial state of a disjoint set of n elements, 0 to n-1.
	public DisjointSet(int n) {

		// All nodes start as leaf nodes.
		parents = new pair[n];
		for (int i=0; i<n; i++)
			parents[i] = new pair(i, 0);
	}

	// Returns the root node of the tree storing id.
	public int find(int id) {

		// Go up tree until there's no parent.
		while (id != parents[id].getID())
			id = parents[id].getID();

		return id;
	}

	public boolean union(int id1, int id2) {

		// Find the parents of both nodes.
		int root1 = find(id1);
		int root2 = find(id2);

		// No union needed.
		if (root1 == root2)
			return false;

		// Attach tree 2 to tree 1
		if (parents[root1].getHeight() > parents[root2].getHeight()) {
			parents[root2].setID(root1);
		}

		// Attach tree 1 to tree 2
		else if (parents[root2].getHeight() > parents[root1].getHeight() ) {
			parents[root1].setID(root2);
		}

		// Same height case - just attach tree 2 to tree 1, adjust height.
		else {
			parents[root2].setID(root1);
			parents[root1].incHeight();
		}

		// We successfully did a union.
		return true;
	}

	// Just represents this object as a list of each node's parent.
	public String toString() {

		String ans = "";
		for (int i=0; i<parents.length; i++)
			ans = ans + parents[i].getID() + " ";
		return ans;
	}
}

class pair {

	private int ID;
	private int height;

	public pair(int myNum, int myHeight) {
		ID = myNum;
		height = myHeight;
	}

	public int getHeight() {
		return height;
	}

	public int getID() {
		return ID;
	}

	public void incHeight() {
		height++;
	}

	public void setID(int newID) {
		ID = newID;
	}
}
