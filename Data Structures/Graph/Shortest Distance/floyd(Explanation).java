import java.util.*;
import java.io.*;


public class floyd {

  public static int[][] shortestpath(int[][] adj) {

    int n = adj.length;
    System.out.println("Graph length is:"+n);
    int[][] ans = new int[n][n];
     System.out.println("Making new graph called ans");
    
    // Implement algorithm on a copy matrix so that the adjacency isn't
    // destroyed.
      System.out.println("Copying adj to ans");
    copy(ans, adj);

    // Compute successively better paths through vertex k.
    for (int k=0; k<n;k++) {
         System.out.println("Computing better paths in vertex K:"+k);
      // Do so between each possible pair of points.
      for (int i=0; i<n; i++) {
        for (int j=0; j<n;j++){
        System.out.println("i:"+i+" j:"+j);
          ans[i][j] = min(ans[i][j], ans[i][k]+ans[k][j]);
         System.out.println("Minimum of ans[i][j]:"+ans[i][j]+" and of ans[i][k]+ans[k][j]:"+(ans[i][k]+ans[k][j]));
      }
     }
    }
    // Return the shortest path matrix.
    return ans;
  }

  // Copies the contents of array b into array a. Assumes that both a and
  // b are 2D arrays of identical dimensions.
  public static void copy(int[][] a, int[][] b) {

    for (int i=0;i<a.length;i++)
      for (int j=0;j<a[0].length;j++){
        a[i][j] = b[i][j];
        System.out.print(a[i][j]+" ");
      }
  }

  // Returns the smaller of a and b.
  public static int min(int a, int b) {
    if (a < b) 
      return a;
    else       
      return b;
  }

  public static void main(String[] args) {


    // Tests out algorithm with graph shown in class.
     Scanner fin = new Scanner (System.in);
     int nodes = fin.nextInt();
     int edges = fin.nextInt();

    int[][] G = new int[nodes][nodes];
    int INFINITY = 10000;
    
    for(int i=0;i<nodes;i++)//necessary, for time complexity?!
    {
      for(int j=0;j<nodes;j++){
        if(i == j){
          G[i][j] = 0;
        }else{
          G[i][j] = INFINITY;
        }
      }
    }

  //make digraph 
    for(int i=0;i<edges;i++){
      int x = fin.nextInt();
      int y = fin.nextInt();
      G[x-1][y-1] = fin.nextInt();
    }


    int[][] shortpath;
    shortpath = shortestpath(G);

    int Q = fin.nextInt();

  //System.out.println();
    for(int i=0;i<Q;i++){
        int x = fin.nextInt();
        int y = fin.nextInt();
       // System.out.println(x+" "+y);
        if(shortpath[x-1][y-1] == INFINITY){
            System.out.println("-1");
        }else{
        System.out.println(shortpath[x-1][y-1]);
      }
    }


//prints out digraph shortest paths
   /* for (int i=0; i<nodes;i++) {
      for (int j=0; j<nodes;j++)
        System.out.print(shortpath[i][j]+" ");
      System.out.println();
    }*/
 
  }
}
