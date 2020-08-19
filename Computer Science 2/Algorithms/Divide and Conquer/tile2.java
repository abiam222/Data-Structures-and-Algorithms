// Arup Guha
// 11/3/06
// Written in COP 3503 - solves "tile" problem.
// Prints out each way to tile a length of n with 1, 2, 3, 4 and 5 unit tiles.

public class tile2 {
	
	
	public static void main(String[] args) {

		// One test case.		
		printTile(10,"");
	}
	
	public static void printTile(int n, String curtiles) {
		
		// This is invalid.
		if (n < 0)
			return;
		
		// Print out the tiles we've already laid out.
		if (n == 0) {
		
			System.out.println(curtiles);
			return;
		}
		
		// For starting case, so a comma doesn't precede the first tile.
		if (curtiles.equals("")) {
			printTile(n-5, "5");
			printTile(n-4, "4");
			printTile(n-3, "3");
			printTile(n-2, "2");
			printTile(n-1, "1");
		}	
		
		// We can place a tile of length 2, and from that, do all tilings of
		// length n-2.
		// OR
		// We can place a tile of length 1, and from that, do all tilings of
		// length n-1.
		else {
			
			char lasttile = curtiles.charAt(curtiles.length()-1);
			
			switch (lasttile) {
			
				case '5': printTile(n-5, curtiles+", 5");	
				case '4': printTile(n-4, curtiles+", 4");
				case '3': printTile(n-3, curtiles+", 3");
				case '2': printTile(n-2, curtiles+", 2");
				case '1': printTile(n-1, curtiles+", 1");
			
			}
		}
	}
}
