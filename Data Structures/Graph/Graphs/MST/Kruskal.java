


import java.util.*;
import java.io.*;
import java.util.Arrays;



public class Problem{

    // A little driver program to test our class.
    public static void main(String[] args) throws IOException{

       
         Scanner fin = new Scanner(System.in);
        
         
         int nodes = fin.nextInt();
         int edges = fin.nextInt();

        PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
        
            for(int i=0;i<edges;i++){
                int x = fin.nextInt();
                int y = fin.nextInt();
                int weight = fin.nextInt();
                pq.add(new Edge(x-1,y-1,weight));
            }

           // System.out.println();
             //   for(int i=0;i<edges;i++){
               //     System.out.println(pq.peek().end1+" "+pq.peek().end2+" "+pq.peek().weight);
                 //  pq.poll();
               //}

            int start = fin.nextInt();
            start -= 1;
            
             int answer = kruskal(pq, nodes);
           System.out.println(answer);
     
    }

    public static int kruskal(PriorityQueue<Edge> pq, int nodes)
    {
       // int components = nodes;
        int cost = 0;
        
        // I make use of a Disjoint Sets data structure using the union-find 
        // algorithm to determine whether two nodes are reachable from one
        // another
        DisjointSets sets = new DisjointSets(nodes);
        
        // Repeat until every node can reach every other node
        while(!pq.isEmpty())
        {
            Edge e = pq.poll();
            
            // If the smallest remaining edge connects two vertices that can
            // already get to each other, just ignore that edge and move on
           // System.out.println("here:"+sets.find(e.end1)+" "+sets.find(e.end2));
            if(sets.find(e.end1) == sets.find(e.end2))
                continue;
             // System.out.println("here2:"+sets.find(e.end1)+" "+sets.find(e.end2));
            
            // Combine the components containing the endpoints of the edge into
            // a single component
            sets.union(e.end1, e.end2);
          //  components--;
            cost += e.weight;
        }
        return cost;
    }
}



class DisjointSets
{
    // For each node, store a link to another node which may or may not be
    // the canonical element of the set. Every node that points to itself is
    // a canonical element. All other nodes can find their canonical element
    // by following the (typically very short) chain of links
    private int[] parent;
    public DisjointSets(int size)
    {
        // Initially, every vertex is in a set by itself.
        parent = new int[size];
        for(int i=0;i<size;i++)
            parent[i] = i;
    }
    
    // The find algorithm, in addition to returning the canonical element of
    // the set containing node x, also makes all nodes along x's path to the
    // canonical element point at the canonical element. That way, the next
    // time find is called on any of those nodes, it will be really fast.
    public int find(int x)
    {
        if(parent[x] == x)
            return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    
    // Union combines two sets by making the canonical element of one point at
    // the canonical element of the other.
    public void union(int x, int y)
    {
        parent[find(x)] = find(y);
    }
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
    
    // This compareTo method looks at the weight of the edge first,
    // then uses arbitrary criteria to distinguish them if they have
    // the same weight. A negative return value indicates that this edge
    // comes before rhs, positive means that this comes after, and 0 means
    // that they're the same edge.
    public int compareTo(Edge rhs)
    {
        if(weight != rhs.weight)
            return weight - rhs.weight;
        if(end1 != rhs.end1)
            return end1 - rhs.end1;
        return end2 - rhs.end2;
    }
}