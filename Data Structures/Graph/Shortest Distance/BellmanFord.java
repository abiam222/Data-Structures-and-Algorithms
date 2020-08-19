
import java.io.*;
import java.util.*;
 
public class bellmanford {
     
    final public static int MAX = 1000000000;
 
    // Short driver program to test the Bellman Ford's method.  
    public static void main(String[] args) {
         
        // Read in graph.
        int[][] adj = new int[5][5];
        Scanner fin = new Scanner(System.in);
        int numEdges = 0;
        for (int i = 0; i<25; i++) {
            adj[i/5][i%5] = fin.nextInt();
            if (adj[i/5][i%5] != 0) numEdges++;
        }
         
        // Form edge list.
        edge[] eList = new edge[numEdges];
        int eCnt = 0;
        for (int i = 0; i<25; i++) 
            if (adj[i/5][i%5] != 0) 
                eList[eCnt++] = new edge(i/5, i%5, adj[i/5][i%5]);
             
        // Run algorithm and print out shortest distances.
        int[] answers = bellmanford(eList, 5, 0);
        for (int i=0; i<5; i++)
            System.out.print(answers[i]+" ");
        System.out.println();       
    }
     
    // Returns the shortest paths from vertex source to the rest of the 
    // vertices in the graph via Bellman Ford's algorithm. 
    public static int[] bellmanford(edge[] eList, int numVertices, int source) {
         
        // This array will store our estimates of shortest distances.
        int[] estimates = new int[numVertices];
         
        // Set these to a very large number, larger than any path in our
        // graph could possibly be.
        for (int i=0; i<estimates.length; i++)
            estimates[i] = MAX;
             
        // We are already at our source vertex.
        estimates[source] = 0;
         
        // Runs v-1 times since the max number of edges on any shortest path is v-1, if
        // there are no negative weight cycles.
        for (int i=0; i<numVertices-1; i++) {
         
            // Update all estimates based on this particular edge only.
            for (edge e: eList) {
                if (estimates[e.v1]+e.w < estimates[e.v2])
                    estimates[e.v2] = estimates[e.v1] + e.w;    
            }
                     
        }
        return estimates;
    }
}
 
class edge {
 
    public int v1;
    public int v2;
    public int w;
 
    public edge(int a, int b, int c) {
        v1 = a;
        v2 = b;
        w = c;
    }
 
    public void negate() {
        w = -w;
    }
}