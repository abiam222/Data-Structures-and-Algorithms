// Arup Guha
// 9/25/06
// Written in COP 3503 class to test the theoretical result derived about
// the number of inversions in a random array.

import java.util.*;
import java.io.*;

public class testsort {
	
	public static void main(String[] args) {
		Random r = new Random();
		int cnt = 0;
		
		// Run the test 1000 times.
		for (int i=0; i<1000; i++) {
			
			// We create an array of size 1000, with numbers ranging from 0
			// to 999,999.
			int[] test = randArray(1000, 1000000, r);
			
			// Keep track of the total number of inversions in all test runs.
			cnt += countInversions(test);
		}
		
		// Print out the average number of inversions.
		System.out.println("Avg inversions = "+(double)cnt/1000);
		
		// Print out what we expected if all values were distinct.
		System.out.println("Expected = "+(1000*999/4));
		
	}
	
	// Returns a random array of values of size size where each value is
	// in between 0 and maxval-1. r is used to create the random values.
	public static int[] randArray(int size, int maxval, Random r) {
		
		int[] vals = new int[size];
		
		for (int i=0; i<size; i++) {
			vals[i] = Math.abs(r.nextInt()%maxval);
		}
		return vals;
	}
	
	// Returns the number of inversions in array.
	public static int countInversions(int[] array) {
		
		int cnt = 0;
		for (int i=0; i<array.length; i++)
			for (int j=i+1; j<array.length; j++)
				if (array[j] < array[i])
					cnt++;
		return cnt;
	}
}
