// Arup Guha
// 1/24/2013
// Written in COP 3503 to show the performance of a Hash Table
// with an "ideal" hash function.

import java.util.*;

public class HashTableSim {

	public static void main(String[] args) {

		// Get the size of our table,
		Scanner stdin = new Scanner(System.in);
		System.out.println("Enter the size of your hash table.");
		int n = stdin.nextInt();

		// This will simulate our table.
		int[] freq = new int[n];

		Random r = new Random();

		// Fill our simulated hash table. - we just keep track
		// of how man items hash to each spot, assuming that the
		// hash function output is random.
		for (int i=0; i<n; i++) {
			freq[r.nextInt(n)]++;
		}

		// Find the length of the longest list.
		int maxList = 0;
		for (int i=0; i<n; i++)
			if (freq[i] > maxList)
				maxList = freq[i];

		System.out.println("Largest LL was size "+maxList);

		// We derived the formula in class to calculate the length of an
		// average query. It's implemented below.
		int sum = 0;
		for (int i=0; i<n; i++)
			sum += (freq[i]*(freq[i]+1)/2);

		double avg = (double)sum/n;
		System.out.println("Average time per search = "+avg);
	}
}
