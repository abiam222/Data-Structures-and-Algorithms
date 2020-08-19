// Arup Guha
// 2/7/2013
// Quick Select - we try to validate that the rough number of comparisons a quick select does is
// about 3*n, as the theory suggests.

import java.util.*;

public class quickselect {

	public static long totalOps = 0;
	final static int NUMTRIALS = 1000;
	final static int SIZE = 100000;
	final static int MAXVAL = 1000000000;

	public static void main(String[] args) {

		Random r = new Random();

		// Run the trials.
		for (int i=0; i<NUMTRIALS; i++) {

			boolean result = trial(r, SIZE, MAXVAL);
			if (!result)
				System.out.println("Trial "+i+" failed.");
		}

		// Print out the operations per trial.
		System.out.println("Ops per run = "+((double)totalOps/NUMTRIALS));

		// This is the number that ought to be close to 3.
		System.out.println("Ratio to array size = "+((double)totalOps/NUMTRIALS/SIZE));
	}

	// Runs one trial with an array with size and maximum integer max.
	public static boolean trial(Random r, int size, int max) {
		int[] test = makeRandArray(r, size, max);
		int k = r.nextInt(size) + 1;
		int item = select(test, k, 0, size-1);
		return worked(test, k-1);
	}

	// Returns the kth smallest element in array[start..end]. 1 <= k <= end-start+1.
	public static int select(int[] array, int k, int start, int end) {

		if (end == start) return array[start];

		// Partition and return index of partition element.
		int split = partition(array, start, end);

		// Go to left.
		if (split-start >= k)
			return select(array, k, start, split-1);

		// Item desired is split value.
		else if (split-start == k-1)
			return array[split];

		// Go to right.
		else
			return select(array, k - (split-start+1),split+1, end);


	}

	// Partitions array[start..end] and returns the index of the partition element.
	public static int partition(int[] array, int start, int end) {

		// Here is our counter for number of operations, roughly.
		totalOps += (end - start + 1);

		int partElem = array[start];
		int low = start+1, high = end;

		// Run until pointers switch over.
		while (low < high) {

			// Slide over low pointer.
			while (low < end && array[low] < partElem) low++;
			while (high > start+1 && array[high] >=  partElem) high--;

			// Don't swap if they've crossed over.
			if (low > high) break;

			// Swap these.
			int temp = array[low];
			array[low] = array[high];
			array[high] = temp;
		}

		// Swap these.
		if (array[start] > array[high]) {
			int temp = array[start];
			array[start] = array[high];
			array[high] = temp;
			return high;
		}

		// Start IS the correct place for the partition element.
		else
			return start;
	}

	// Makes an array with size elements in between 0 and max-1.
	public static int[] makeRandArray(Random r, int size, int max) {

		int[] array = new int[size];
		for (int i=0; i<size; i++)
			array[i] = (int)(r.nextInt(max)) + 1;

		return array;
	}

	// Returns true iff array[split] partitions array.
	public static boolean worked(int[] array, int split) {

		// Illegal split!
		if (split < 0 || split >= array.length) return false;

		// Pivot item.
		int pivot = array[split];

		// Check if items before pivot are greater than it.
		for (int i=0; i<split; i++)
			if (array[i] > array[split])
				return false;

		// Check if items after pivot are less than it.
		for (int i=split+1; i<array.length; i++)
			if (array[i] < array[split])
				return false;

		// If we get here, the array is partitioned by index split.
		return true;
	}

	// For debugging...
	public static void print(int[] array) {
		for (int i=0; i<array.length; i++) {
			System.out.print(array[i]+" ");
		}
		System.out.println();
	}

}
