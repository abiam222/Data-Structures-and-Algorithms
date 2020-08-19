import java.io.*;
import java.util.*;
 
public class Problem{
     
    final public static int MAX = 1000000000;
    final public static int NOEDGE = 0;
     
    // Short driver program to test the Dijkstra's method.  
    public static void main(String[] args) throws Exception {

        /*
        0 24 3 20
        24 0 0 0
        3 0 0 12
        20 0 12 0
        0 24 3 15 */
         
        int[][] adj = new int[4][4];
        Scanner fin = new Scanner (System.in);
        for (int i = 0; i<16; i++)
            adj[i/4][i%4] = fin.nextInt();

        //adj[i][j] //instead of doing this do above , n^2
        //both are n^2 anyway cause 16, just less line of code

 /*for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                System.out.print(adj[i][j]+" ");
            }
            System.out.println();
        }*/
       
         
        int[] answers = dijkstra(adj, 0);
        for (int i=0; i<4; i++)
            System.out.print(answers[i]+" ");
        System.out.println();       
    }
     
    // Returns the shortest paths from vertex source to the rest of the 
    // vertices in the graph via Dijkstra's algorithm. It's required that
    // all edge weights in adj be non-negative and that all edges be 
    // assigned weights.
    public static int[] dijkstra(int[][] adj, int source) {
         
          //adj.length = 4 hence n*n
        int[] estimates = new int[adj.length];
         
          //set everything to infinity
        for (int i=0; i<estimates.length; i++)
            estimates[i] = MAX;
      
             
        // We are already at our source vertex
        estimates[source] = 0;
         
        // This will keep track of which vertices we already have shortest
        // distances to.
        boolean[] chosen = new boolean[estimates.length];
        //chosen = 4 length
        for (int i=0; i<chosen.length; i++) chosen[i] = false;
            //all false cause you haven't been in any yet
         
    
        //chosen, estimates, adj

        //do this loop 3 times.  Because no point to try 0th, i think 
        for (int i=0; i<estimates.length-1; i++) {
            System.out.println("i = "+i);
             
            // Pick vertex.
            int vertex = 0;//start with this vertex
            int bestseen = MAX;
            System.out.println("vertex = 0, and bestseen= MAX ");
             
            // Find the best vertex that has NOT been added to our set S yet.
            for (int j=0; j<estimates.length; j++) {
                  System.out.println("in loop, j="+j+"estimates="+estimates[j]);
                if (chosen[j] == false && estimates[j] < bestseen) {//says where you will firt start in first whole iteratoin
                      System.out.println("In if, j="+j);
                        System.out.println("bestseen="+bestseen+"vertex="+vertex);
                    bestseen = estimates[j];
                    vertex = j;
                     System.out.println("new:: bestseen="+bestseen+"vertex="+vertex);
                }
            }
             
            // Choose this vertex to be added.
            chosen[vertex] = true;
             System.out.println("chosen[vertex]="+chosen[vertex]+"is true");
             
            // Update all estimates based on this particular vertex only.
            for (int j = 0; j<estimates.length; j++) {
                 System.out.println("other loop, j="+j);
                if (adj[vertex][j] == NOEDGE) continue;
                if (estimates[vertex]+adj[vertex][j] < estimates[j]){
                    estimates[j] = estimates[vertex] + adj[vertex][j];  
                    System.out.println("estimates[vertex]="+estimates[vertex]+"adj[vertex][j]="+adj[vertex][j]+" < estimates[j] so = "+estimates[j]);
                }
            }
                     
        }
        System.out.println("This is the end of the loop");
        return estimates;
    }
}