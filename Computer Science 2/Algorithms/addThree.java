// Arup Guha
// 5/20/2010
// Shown in class as an example of how to gauge run time experimentally.
// It's fairly obvious that this code runs in O(n^3) time.
// Note: The leading constant is about 1/3.

public class addthree {
	
	final public static int N = 7000;
	final public static int TARGET = 105;
	
	public static void main(String[] args) {
	
		long start = System.currentTimeMillis();

		// Triple loop structure - each loop runs upto N times.
		// A better analysis is that we are running through all
		// choices of 3 items out of N, which is about N^3/3.		
		int count = 0;	
		for (int x1=1; x1<=N; x1++)
			for (int x2=x1+1; x2<=N; x2++)
				for (int x3=x2+1; x3<=N; x3++)
					if (x1+x2+x3 == TARGET)
						count++;
		long end = System.currentTimeMillis();
						
		System.out.println("There are "+count+" number of solutions.");
		System.out.println("It took "+(end-start)+" ms.");
	}
}
