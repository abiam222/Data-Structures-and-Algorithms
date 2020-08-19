// Arup Guha
// 5/25/2010
// Sieve of Eratosthenes, for experimental timing purposes.
public class sieve {
	
	public final static int N = 61000000;
	
	public static void main(String[] args) {
		
		// Set up our boolean array marking what is prime.
		boolean[] numbers = new boolean[N+1];
		
		numbers[0] = false;
		numbers[1] = false;
		for (int i=2; i<numbers.length; i++)
			numbers[i] = true;
		
		// Start the clock.	
		long start = System.currentTimeMillis();
		
		// Note how simple this algorithm is to code!
		
		// We can stop at the square root since all composites have 
		// at least one factor less than or equal to sqrt(N).
		for (int i=2; i<Math.sqrt(N)+1; i++) {
			
			// Here we cross off all multiples of i, starting at 2i.
			for (int j=2*i; j<numbers.length; j+=i)
				numbers[j] = false;
		}
		long end = System.currentTimeMillis();
		
		// Print out the time it took.
		System.out.println("Took "+(end-start)+" ms.");
		
		// If we wanted to print out the list of primes this would do it.
		/*
		for (int i=2; i<numbers.length; i++)
			if (numbers[i])
				System.out.println(i);
		*/
	}
}
