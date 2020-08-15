#include <iostream>
#include <queue>

using namespace std;

void setupGraph();
void DFS();
void DFSsearch(int i, bool V[]);
void BFS();
void BFSsearch(int i, bool V[]);

//write herer big oh notattion for BFS and DFS

#define N  8
bool G[N][N];//// the graph as an adjacency matrix	

int main(){

	setupGraph();
	cout << "------------------------" << endl << endl;

	DFS();

    cout << "------------------------" << endl << endl;
    BFS();
	
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
       // int N 

        G[0][1]=G[1][0]=true; G[0][2]=G[2][0]=true; G[0][3]=G[3][0]=true;
        G[1][4]=G[4][1]=true; G[3][4]=G[4][3]=true; G[5][6]=G[6][5]=true;
        G[5][7]=G[7][5]=true; G[6][7]=G[7][6]=true;

        /*for(int i=0;i<N;i++){
        	cout << "" << endl;
        	for(int j=0;j<N;j++){
        		cout << G[i][j];
        	}
        }*/

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
        for (int i=0; i<N; i++){
            if (G[currNode][i] && !V[i])
            {
                cout << "Going to node " << i << " ... ";
                DFSsearch(i,V);
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

        queue<int> nodes;

        nodes.push(start);
        V[start] = true;

        while(!nodes.empty())
        {
            int head = nodes.front();
            nodes.pop();
            cout << "At node " << head  << " in BFS" << endl;

        // recursively visit every node connected yet to be visited
        for (int i=0; i<N; i++){
            if (G[head][i] && !V[i])
            {
                nodes.push(i);
                V[i] = true;
                cout << "Adding node " << i << " to the queue in the BFS" << endl;
                
            }
    }
     cout << "Done processing node " << head << endl;
 }//end while
    cout << "Finished with the BFS from start node " << start << endl; 

}