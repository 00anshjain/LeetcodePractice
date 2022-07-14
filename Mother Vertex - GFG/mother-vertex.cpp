// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	void DFS(int u, vector<bool> &visited, int &cnt, vector<int>adj[])
	{
	    visited[u] = true;
	    cnt++;
	   // cout<<u<<endl;
	    for(auto x : adj[u])
	    {
	        if(!visited[x])
	            DFS(x, visited, cnt, adj);
	    }
	}
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool> visited(V, false);
        int cnt = 0;
        int canMother = 0;
	    for(int i = 0; i < V; i++)
	    {
	        if(!visited[i])
	        {
    	        DFS(i, visited, cnt, adj);
    	        if(cnt == V)
    	        {
    	           // cout<<cnt<<endl;
    	           // cout<<"Mother"<<i<<endl;
    	            canMother = i;
    	            break;
	            }
	        }
	    }
	   // visited.resize(V, false);
	   vector<bool> g(V, false);
	    cnt = 0;
	    DFS(canMother, g, cnt, adj);
	   // cout<<cnt<<endl;
	    if(cnt == V)
	        return canMother;
	    return -1;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends