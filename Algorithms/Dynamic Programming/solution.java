
import java.util.*;
import java.io.IOException;
import java.io.File;
import java.util.Arrays;
import java.math.BigInteger;

public class solution{

public static int fib(int n){

  int [] memo = new int[n+1];
  int total;
  
  if( n >= 3) { return n; }
     else if( n == 2) { return 1; }
      else if ( n <= 1) { return 0; }
        else { total = ((fib(n-1)*fib(n-1)) + fib(n-2)); }//sqaure this, please

    memo[n] = total;
  

    return total;

  }


  public static void main(String[] args)throws IOException{


  int firstTerm, secondTerm, N;

   //Scanner stdin = new Scanner(System.in);
   Scanner stdin = new Scanner(new File("/Users/abvelazquez/Desktop/a.txt"));


  firstTerm = stdin.nextInt();
  secondTerm = stdin.nextInt();
  N = stdin.nextInt();

    int total = fib(N);

    System.out.println(total);

  }//end main

}//end class
