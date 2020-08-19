// Written in COP 3503 Class 9/1/06
// Tests out the three MCSS solutions in the text.

import java.util.*;

public class mcss {


	public static void main(String[] args) {
	
		// Test each of the three algorithms.
		// I currently have the slow one commented out so we could test
		// the other two with an input array of size 100,000.
	
		int[] vals = rndArray(100000);
		//printArray(vals);
		long t1 = System.currentTimeMillis();
		
		//int score = mcss(vals);
		long t2 = System.currentTimeMillis();
		int score2 = mcss2(vals);
		long t3 = System.currentTimeMillis();
		int score3 = mcss3(vals);
		long t4 = System.currentTimeMillis();
		System.out.println("Scores are "+" "+(t3-t2)+" "+(t4-t3));
	}

	// Streamlined O(n) solution.	
	public static int mcss3(int[] vals) {
	
		int max=0, sum=0, start=0, end=0, i=0;
	
		for (int j=0; j<vals.length; j++) {
			sum += vals[j];
		
			// Update if we get a better max.
			if (sum > max) {
				max = sum;
				start = i;
				end = j;
			
			}
			
			// If our running sum falls below 0, there's no need to
			// consider it at all, reset the sum to 0.
			else if (sum < 0) {
				i = j+1;
				sum = 0;
			}
		}
		return max;
	}
	
	// O(n^2) solution.
	public static int mcss2(int[] vals) {
		
		int max=0, start=0, end=0, sum=0;
		
		// Loop through all start points.
		for (int i=0; i<vals.length; i++) {
			sum = 0;
			
			// And all end points.
			for (int j=i; j<vals.length; j++) {
				
				// Just add the current value to the running sum to obtain
				// this new sum.
				sum += vals[j];
			
				// Update if we get a better max.
				if (sum > max) {
					max = sum;
					start = i;
					end = j;
				
				}
			}
		}
		return max;
	}
	
	// Brute force O(n^3) solution.
	public static int mcss(int[] vals) {
		
		int max=0, start=0, end=0, sum=0;
		
		// All starting values.
		for (int i=0; i<vals.length; i++) {
			
			// All ending values.
			for (int j=i; j<vals.length; j++) {
			
				sum =0;
				// Add up everything in between.
				for (int k=i; k<=j; k++)
					sum += vals[k];
			
				// Update if we find something better.
				if (sum > max) {
					max = sum;
					start = i;
					end = j;
				
				}
			}
		}
		return max;
	}
	
	// Randomly filles an array of size n with integers from -9 to 9.
	public static int[] rndArray(int n) {
		Random r = new Random();
		int[] array = new int[n];
		for (int i=0; i<n; i++)
			array[i] = r.nextInt()%10;
		return array;
	}
	
	// Prints out all the elements of vals.
	public static void printArray(int[] vals) {
		for (int i=0; i<vals.length; i++)
			System.out.print(vals[i]+" ");
		System.out.println();
	}
}
