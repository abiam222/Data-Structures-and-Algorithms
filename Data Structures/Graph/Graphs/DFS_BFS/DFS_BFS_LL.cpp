#include <iostream>
#include <queue>
#define N  8

using namespace std;

struct Node{
    
    int data;
    struct Node *next;
};

struct AdjancencyList{
    
    struct Node *row;
    
};

void setupGraph();
void DFS();
void DFSsearch(int i, bool V[]);
void BFS();
void BFSsearch(int i, bool V[]);

AdjancencyList *G = new AdjancencyList[N];



int main(){
    //delete pointer at the end
    
    //start clock
    double start = clock ()/(double)CLOCKS_PER_SEC;
    
    setupGraph();
    cout << "------------------------" << endl << endl;
    
    // DFS();
    //can't do both DFS and BFS because in each 'G' becomes null
    
    cout << "------------------------" << endl << endl;
    BFS();
    
    printf ("\n\n");
    double end = clock ()/(double)CLOCKS_PER_SEC;
    double interval = end - start;
    printf ("Time in seconds:%f\n", interval );
    
    return 0;
}


void setupGraph(){
    
    // set up a graph with 8 vertices + 3 components that looks like:
    /*
     0 --- 1        5---6
     | \    \       |  /
     |  \    \      | /
     2   3----4     7
     */
    
    // notice that for each edge G[i][j] == G[j][i]
    // this means that the graph is undirected. Also can be true,false
    //or 1,0
    
    //Do Loop if someone inserts numbers and weights!!*!**!*!*!*!*!*!*!*!*!*!*!*!*!*!
    
    
    Node *polymer = new Node;
    
    //iinsert nodes into array 0
    polymer->data = 1;
    polymer->next = new Node;
    polymer->next->data = 2;
    polymer->next->next= new Node;
    polymer->next->next->data = 3;
    polymer->next->next->next = NULL;
    
    G[0].row = polymer;
    
    //insert nodes into array 1
    polymer = new Node;
    polymer->data = 4;
    polymer->next = new Node;
    polymer->next->data = 0;
    polymer->next->next = NULL;//necessary??
    
    
    G[1].row = polymer;
    
    //insert nodes into array 2
    polymer = new Node;
    polymer->data = 0;
    polymer->next = NULL;
    
    G[2].row = polymer;
    
    //insert nodes into array 3
    polymer = new Node;
    polymer->data = 4;
    polymer->next = new Node;
    polymer->next->data = 0;
    polymer->next->next = NULL;//necessary??
    
    G[3].row = polymer;
    
    //insert nodes into array 4
    polymer = new Node;
    polymer->data = 1;
    polymer->next = new Node;
    polymer->next->data = 3;
    polymer->next->next = NULL;//necessary??
    
    G[4].row = polymer;
    
    //insert nodes into array 5
    polymer = new Node;
    polymer->data = 6;
    polymer->next = new Node;
    polymer->next->data = 7;
    polymer->next->next = NULL;//necessary??
    
    G[5].row = polymer;
    
    //insert nodes into array 6
    polymer = new Node;
    polymer->data = 5;
    polymer->next = new Node;
    polymer->next->data = 7;
    polymer->next->next = NULL;//necessary??
    
    G[6].row = polymer;
    
    //insert nodes into array 7
    polymer = new Node;
    polymer->data = 6;
    polymer->next = new Node;
    polymer->next->data = 5;
    polymer->next->next = NULL;//necessary??
    
    G[7].row = polymer;
    
}



void DFS(){
    // a visited array to mark which vertices have been visited in DFS
    bool V[N];
    
    //initialize to false
    for(int i=0;i<N;i++){
        V[i] = false;
    }
    
    int component=0;
    
    // do the DFS from each node not already visited
    //we're visiting everything for a total of N times
    for (int i=0; i<N; ++i){
        if(!V[i]){
            component++;
            cout << "DFS for component " << component << " starting at node " << i << endl;
            DFSsearch(i,V);
        }
    }
    cout << "Finished DFS - found " << component << " Components" << endl;
}


void DFSsearch(int currNode, bool V[]){
    
    cout << "At node " << currNode  << " in DFS" << endl;
    
    V[currNode] = true;
    
    // recursively visit every node connected yet to be visited
    while (G[currNode].row != NULL) {
        
        if(V[currNode] && !V[G[currNode].row->data]){
            cout << "Going to node " << G[currNode].row->data << " ... ";
            DFSsearch(G[currNode].row->data,V);
        }
        
        if(V[currNode] && V[G[currNode].row->data]){
            G[currNode].row = G[currNode].row->next;
            
        }
    }
    
    cout << "Done processing node " << currNode << endl;
    
}



 void BFS(){
     // a visited array to mark which vertices have been visited in BFS
     bool V[N];
 
     //initialize to false
     for(int i=0;i<N;i++){
         V[i] = false;
     }
 
     int component=0;
 
     // do the BFS from each node not already visited
     //we're visiting everything for a total of N times
     for (int i=0; i<N; ++i){
         if(!V[i]){
             component++;
             cout << "BFS for component " << component << " starting at node " << i << endl;
             BFSsearch(i,V);
         }
     }
        cout << "Finished BFS - found " << component << " Components" << endl;
}
 
 
 
 void BFSsearch(int start, bool V[]){
 
     queue <int> nodes;
 
     nodes.push(start);
     V[start] = true;
 
     while(!nodes.empty())
     {
         int head = nodes.front();
         nodes.pop();
         cout << "At node " << head  << " in BFS" << endl;
         

        // recursively visit every node connected yet to be visited
         while (G[head].row != NULL) {
        
             if(V[head] && !V[G[head].row->data]){
                 nodes.push(G[head].row->data);
                 V[G[head].row->data] = true;
                 cout << "Adding node " << G[head].row->data << " to the queue in the BFS" << endl;
             }
             
             if(V[head] && V[G[head].row->data]){
                 G[head].row = G[head].row->next;
                 
             }
         }
 
         cout << "Done processing node " << head << endl;
     }//end while
     cout << "Finished with the BFS from start node " << start << endl;
 }
 
