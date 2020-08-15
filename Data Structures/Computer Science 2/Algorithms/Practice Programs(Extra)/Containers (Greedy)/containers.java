// Arup Guha
// 10/7/09
// Solution to 2007 World Finals Problem B: Containers

import java.io.*;
import java.util.*;

public class containers {
	
	public static void main(String[] args) throws Exception {

		Scanner fin = new Scanner(new File("containers.in"));
		
		String line = fin.next();
		int num = 1;
		
		// Go through each case.
		while (!line.equals("end")) {
			
			// Initialize each stack's top to be a dummy letter after Z.
			int[] top = new int[26];
			for (int i=0; i<26; i++)
				top[i] = 26;
				
			// Go through each box in the string.
			for (int i=0; i<line.length(); i++) {
				int best = -1;
				int curItem = line.charAt(i) - 'A';
				
				// Loop through each stack, and find the stack with
				// the closest letter equal to or after the letter to
				// place. This is the stack we want to place our item.
				for (int j=0; j<26; j++) {
					
					// Indicates we've found A place for our item.
					if (best==-1 && curItem <= top[j])
						best = j;
				}
				
				// Place the item here.
				top[best] = curItem;
			}
			
			// Count the number of non-empty stacks.
			int numStacks = 0;
			for (int i=0; i<26; i++)
				if (top[i] < 26)
					numStacks++;
			
			// Output our answer.
			System.out.println("Case "+num+": "+numStacks);
			line = fin.next();
			num++;
		}
				
	}
}
