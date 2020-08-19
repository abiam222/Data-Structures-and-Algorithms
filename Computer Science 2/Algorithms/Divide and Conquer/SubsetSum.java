public class subsetsumrec {
	
	public static void main(String[] args) {
		
		int[] vals = new int[6];
		vals[0] = 2; vals[1] = 5; vals[2] = 12;
		vals[3] = 7; vals[4] = 9; vals[5] = 6;
		
		for (int i=0; i<42; i++) {
			if (SS(vals, i, 6, ""))
				System.out.println("Found subset : "+i);
		}
	}
	
	public static boolean SS(int[] vals, int target, int length, String numbers) {
		
		// Empty set satisfies this target.
		if (target == 0) {
			System.out.println(numbers);
			return true;
		}
		
		// An empty set can't add up to a non-zero value.
		if (length == 0)
			return false;
			
		return SS(vals, target - vals[length-1], length-1, numbers+", "+vals[length-1]) ||
			   SS(vals, target, length-1, numbers );
	}
			
}
