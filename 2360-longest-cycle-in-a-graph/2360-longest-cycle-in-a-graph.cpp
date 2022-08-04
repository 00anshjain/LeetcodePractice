class Solution {
public:
    int ans;
    void DFS(int u, vector<int> &e, vector<bool> &visited, vector<int> &cycle, int k)
    {
        // cout<<u<<endl;
        visited[u] = true;
        cycle[u] = k;
        int child = e[u];
        if(child == -1)
        {
            cycle[u] = -1;
            return;
        }
        else if(cycle[child] != -1)
        {
            ans = max(ans, k - cycle[child] + 1);
            cycle[u] = -1;
            return;
        }
        else if(!visited[child])
            DFS(child, e, visited, cycle, k+1);
        cycle[u] = -1;
        return;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        // vector<int> adj[n];
        vector<bool> visited(n+1, false);
        vector<int> cycle(n+1, -1);
        ans = -1;
        for(int i = 0; i < n; i++)
        {
            // cout<<i<<endl;
            if(!visited[i])
                DFS(i, edges, visited, cycle, 0);    
        }
        return ans;
    }
};