import java.io.*;
import java.util.*;
import java.util.PriorityQueue;
 
public class Problem2 {
     
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
         
         PriorityQueue<Integer> queue =  new PriorityQueue<Integer>();
          //adj.length = 4 hence n*n
        int[] estimates = new int[adj.length];
         
          //set everything to infinity
        for (int i=0; i<estimates.length; i++)
            estimates[i] = MAX;
      

         estimates[source] = 0;

         //initialize Priority Queue
        for(int i=0;i<adj.length;i++)
                queue.add(i);

            int p=0;//??????


        //our Dijkstra algorithm with Priority Queue
            while(queue.peek() != null){
            
            //start out with our highest priority
            int vertex = queue.poll();

                
           for (int j = 0; j<estimates.length; j++) {

                 System.out.println("other loop, j="+j);

                if (adj[vertex][j] == NOEDGE) continue;

                if (estimates[vertex]+adj[vertex][j] < estimates[j])
                {
                    estimates[j] = estimates[vertex] + adj[vertex][j];  
                    System.out.println("estimates[vertex]="+estimates[vertex]+"adj[vertex][j]="+adj[vertex][j]+" < estimates[j] so = "+estimates[j]);
                }
            }
    }


        System.out.println("This is the end of the loop");
        return estimates;
    }
}