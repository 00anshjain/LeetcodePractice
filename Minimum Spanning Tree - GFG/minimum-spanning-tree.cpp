// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // int dist = 0;
        int curr = 0;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        int ans = 0;
        vector<bool> visited(n, false);
        while(1)
        {
            visited[curr] = true;
            for(auto x : adj[curr])
            {
                if(visited[x[0]])
                    continue;
                dist[x[0]] = min(dist[x[0]], x[1]);
            }
            curr = min_element(dist.begin(), dist.end()) - dist.begin();
            if(dist[curr] == INT_MAX)
                return ans;
            // cout<<curr<<" "<<dist[curr]<<endl;
            ans += dist[curr];
            dist[curr] = INT_MAX;
        }
        return 0;
        // code here
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