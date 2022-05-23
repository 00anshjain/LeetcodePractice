// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(vector<bool>& visited, vector<bool>& inCycle, int V, vector<int> adj[], int u, int parent)
    {
        visited[u] = true;
        inCycle[u] = true;
        int cnt = 0;
        for(auto x : adj[u])
        {
            if(x == parent)
            {
                cnt++;
                if(cnt == 2)
                    return true;
                continue;
            }
                
            if(inCycle[x])
                return true;
            if(!visited[x])
            {
                if(checkCycle(visited, inCycle, V, adj, x, u))
                    return true;
            }
        }
        inCycle[u] = false;
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> inCycle(V, false);
        for(int i = 0; i<V; i++)
         {
             if(!visited[i])
            {
                if(checkCycle(visited, inCycle, V, adj, i, -1))
                    return true;
            }
         }
         return false;
        
        // Code here
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends