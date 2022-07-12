// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    typedef pair<int, int> pii;
    // typedef pair<int, pair<int, int>> piii;
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<bool> visited(n, false);
        pq.push({0, 0});
        int ans = 0;
        while(!pq.empty())
        {
            pii p = pq.top();
            int d = p.first;
            int u = p.second;
            pq.pop();
            if(visited[u])
                continue;
            visited[u] = true;
            ans += d;
            for(auto vec : adj[u])
            {
                int v = vec[0];
                int dis = vec[1];
                if(!visited[v])
                    pq.push({dis, v});
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