// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	int findMin(vector<bool> &visited, vector<int>& dist)
	{
	    int dis = INT_MAX;
	    int idx = 0;
	    int n = visited.size();
	    for(int i = 0; i < n; i++)
	    {
	        if(!visited[i] && dist[i] < dis)
	        {
	            dis = dist[i];
	            idx = i;
	        }
	    }
	   // cout<<idx;
	    return idx;
	}
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX);
        vector<int> parent(n, -1);
        dist[0] = 0;
        // int cnt = 0;
        int ans = 0;
        //intinially no edge coming for i = 0
        //only vertex 0 coming from findmin function
        for(int i = 0; i <= n-1; i++)
        {
            int u = findMin(visited, dist);
            // if(visited[u])
            //     continue;
            visited[u] = true;
            // cout<<" "<<parent[u]<<" "<<dist[u]<<endl;
            ans += dist[u];
            // cnt++;
            for(auto x : adj[u])
            {
                if(!visited[x[0]] && dist[x[0]] > x[1])
                {
                    dist[x[0]] = x[1];
                    parent[x[0]] = u; 
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends