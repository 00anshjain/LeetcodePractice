// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	void DFS(int u, vector<bool> &visited, vector<int>adj[])
	{
	    visited[u] = true;
	   // cnt++;
	    for(auto x : adj[u])
	    {
	        if(!visited[x])
	            DFS(x, visited, adj);
	    }
	}
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool> visited(V, false);
	    for(int i = 0; i < V; i++)
	    {
	        if(!visited[i])
	        {
	            vector<bool> g(V, false);
	            int cnt = 0;
	            DFS(i, g, adj);
	            if(cnt == V)
	            return i;
    	        for(int i = 0; i < V; i++)
    	        {
    	            visited[i] = visited[i] || g[i];
    	            if(g[i])
    	                cnt++;
    	        }
    	        if(cnt == V)
    	            return i;
	        }
	        
	    }
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