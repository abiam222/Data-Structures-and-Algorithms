// Arup Guha
// 6/25/02
// Floyd Warshall's algorithm: an example of dynamic programming.
public class floyd {

  public static int[][] shortestpath(int[][] adj) {

    int n = adj.length;
    int[][] ans = new int[n][n];
    
    // Implement algorithm on a copy matrix so that the adjacency isn't
    // destroyed.
    copy(ans, adj);

    // Compute successively better paths through vertex k.
    for (int k=0; k<n;k++) {

      // Do so between each possible pair of points.
      for (int i=0; i<n; i++) {
        for (int j=0; j<n;j++)
          ans[i][j] = min(ans[i][j], ans[i][k]+ans[k][j]);
      }
    }
    // Return the shortest path matrix.
    return ans;
  }

  // Copies the contents of array b into array a. Assumes that both a and
  // b are 2D arrays of identical dimensions.
  public static void copy(int[][] a, int[][] b) {

    for (int i=0;i<a.length;i++)
      for (int j=0;j<a[0].length;j++)
        a[i][j] = b[i][j];
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
    int[][] m = new int[5][5];
    m[0][0] = 0; m[0][1] = 3; m[0][2] = 8; m[0][3] = 10000; m[0][4] = -4;
    m[1][0] = 10000; m[1][1] = 0; m[1][2] = 10000; m[1][3] = 1;
    m[1][4]=7;
    m[2][0] = 10000; m[2][1] = 4; m[2][2] = 0; m[2][3] = 10000; 
    m[2][4] = 10000;
    m[3][0] = 2; m[3][1] = 10000; m[3][2] = -5; m[3][3] = 0; 
    m[3][4] = 10000;
    m[4][0] = 10000; m[4][1] = 10000; m[4][2] = 10000; m[4][3] = 6;
    m[4][4] =0;


    int[][] shortpath;
    shortpath = shortestpath(m);

    for (int i=0; i<5;i++) {
      for (int j=0; j<5;j++)
        System.out.print(shortpath[i][j]+" ");
      System.out.println();
    }
 
  }
}
