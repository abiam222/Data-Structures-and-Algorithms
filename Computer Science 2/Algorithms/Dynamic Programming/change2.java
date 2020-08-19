// Arup Guha
// Edited 6/13/05 and 9/21/04 (not known when this was orignally 
// written.) Added recursive code to solve the change problem.
// Re-editied on 6/14/05 to fully generalize the code to work for
// any denominations array (in increasing order).

public class change2 {
 
  public static int[] denominations = {1, 2, 4, 7};

  public static void main(String[] args) {
    System.out.println("rec: "+makeChangerec(15, 7));
    System.out.println("dyn: "+makeChangedyn(15, 7));
  }

  public static int makeChangedyn(int n, int d) {

    // No way to make change for a negative amount.
    if (n < 0)
      return 0;

    // We can make change for i cents using the smallest coin only
    // if i is divisible by this coin amount.
    else if ((n>=0) && (n < denominations[1]))
      if (n%denominations[0] == 0)
        return 1;
      else
        return 0;
    
    // Build table here.
    else {
  
      int[][] table = new int[denominations.length][n+1];

      // We can make change for i cents using the smallest coin only
      // if i is divisible by this coin amount.
      for (int i=0; i<n+1;i++)
        if (i%denominations[0] == 0)
          table[0][i] = 1;
        else
          table[0][i] = 0;

      // We can make change for 0 cents in 1 way.
      for (int i=1; i<denominations.length; i++)
        table[i][0] = 1;
      
      // den: the denomination we are currently considering in 
      //      handing out change. we consider these in 
      //      increasing order.
      // amount: the amount we are handing out change for.
      // highden: the current coin we are handing out, also the 
      //          largest coin.
      for (int den=1; den<denominations.length; den++) {
        for (int amount=1; amount<n+1; amount++) {
          for (int highden=0; highden<=den; highden++) {

            // We only give change with the coin highden, if 
            // the amount we are giving change for is 
            // greater than or equal to the value of that 
            // single coin.
            if ( amount >= denominations[highden])

              // If we give out one coin with the 
              // denomination highden, the amount 
              // of money we have make change for is 
              // amount minus the value of that 
              // denomination. The largest coin we 
              // can use to make this change is highden.
              table[den][amount] += table[highden][amount - denominations[highden]];
          } 
        }
      }        
    
      // This part prints out the whole table so we can see the values of all
      // of the sub-cases.  
      /*
      for (int den=1; den<denominations.length; den++) {
        for (int amount=0; amount<n+1; amount++) {
			System.out.print(table[den][amount]+" ");
		}
		System.out.println();
	  }
	  */
	  
      // This is the value we desire: the number of ways to make 
      // change for n cents using denomination d or less.
      return table[lookup(d)][n]; 
    }
  }

  public static int makeChangerec(int n, int d) {

    // Can't make change for a negative value.
    if (n < 0)
      return 0;

    // One way to make change for 0 cents: no coins!
    if (n == 0)
      return 1;
    
    // Add up the appropriate possibilities, based on the largest coin,
    // you can give out. (Notice the lack of breaks!!!)
    int sum = 0;

    // Go through each denomination as being the next coin given.
    for (int den=denominations.length-1; den>=0; den--)

      // Check to see that the largest denomination we are allowed to 
      // use is at least as big as the one we are trying to use.
      if (d >= denominations[den])

        // if so, give this coin as change, and determine the number 
        // of ways to make change for the amount leftover now using 
        // den as the largest possible denomination.
        sum += makeChangerec(n-denominations[den], denominations[den]);

    return sum;
  }

  // Inverts the function calculated by the denominations array by doing a brute force lookup.
  public static int lookup(int d) {

    for (int i=0; i<denominations.length; i++)
      if (d==denominations[i]) 
        return i;
   
    return 0;
  }
}
