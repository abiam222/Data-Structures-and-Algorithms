


import java.util.*;
import java.io.*;
import java.util.Arrays;

public class Problem{

        

    // A little driver program to test our class.
    public static void main(String[] args) throws IOException{

        Scanner fin = new Scanner(System.in);
        Queue<Edge> mst = new LinkedList<Edge>();
        PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
       
         
         int nodes = fin.nextInt();
         int edges = fin.nextInt();
        // EdgeWeightedGraph G = new EdgeWeightedGraph(nodes);
        boolean[] marked = new boolean[nodes];
         int[][] G = new int[nodes][nodes];
         int[][] Z = new int[nodes][nodes];
        
            for(int i=0;i<edges;i++){
                int x = fin.nextInt();
                int y = fin.nextInt();
                int weight = fin.nextInt();
                if(G[x-1][y-1] != 0){
                    if (G[x-1][y-1] > weight){
                        G[x-1][y-1] = weight;
                        G[y-1][x-1] = weight;
                    }
                }else{
                G[x-1][y-1] = weight;
                G[y-1][x-1] = weight;
            }
                Z[x-1][y-1] = 1;
                Z[y-1][x-1] = 1;
            }

            int start = fin.nextInt();
            start -= 1;
            
            visit(G, start, marked, nodes, pq,Z);
            while(!pq.isEmpty()){
                
                Edge e = pq.poll();//take out
                
                int v = e.end1, w = e.end2;

                if(marked[v] && marked[w])
                    continue;

                mst.offer(e);

                if(!marked[v]) visit(G, v, marked, nodes, pq,Z);
                if(!marked[w]) visit(G, w, marked, nodes, pq, Z);
            }


            //output offer but get the e.weight of each
            //in queue and add to answer
            int answer = 0;

            while(!mst.isEmpty()){
               // System.out.println(" "+mst.peek().end1+" "+mst.peek().end2+" "+mst.peek().weight);
              Edge e = mst.poll();
             // System.out.println(e.weight);
              answer += e.weight;
            }
           System.out.println(answer);
     }

    public static void visit(int[][] G, int vertex, boolean[] marked, int nodes, PriorityQueue<Edge> pq, int[][] Z)
    {
       marked[vertex] = true;

        for(int i=0;i<nodes;i++){
            //if(G[vertex][i] != 0){//&& Z[vertex][i] == 1
                if(Z[vertex][i] == 1)
                if(!marked[i]){
                    Edge e = new Edge(vertex,i,G[vertex][i]);
                    pq.offer(e);
                } } } 
}

class Edge implements Comparable<Edge>
{
    public int weight;
    public int end1;
    public int end2;
    
    // Constructor. Direction doesn't matter for these edges, so for 
    // simplicity, we just make sure that end1 is the smaller endpoint.
    public Edge(int e1, int e2, int w)
    {
        weight = w;
        end1 = e1;
        end2 = e2;
    }

    public int weight()
    {
        return weight;
    }

     public int compareTo(Edge rhs)
    {
        if(weight != rhs.weight)
            return weight - rhs.weight+1;
        if(end1 != rhs.end1)
            return end1 - rhs.end1;
        return end2 - rhs.end2;
    }
}