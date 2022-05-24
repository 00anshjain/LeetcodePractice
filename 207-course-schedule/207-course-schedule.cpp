class Solution {
public:
    bool DFS(int u, vector<int> adj[], vector<bool> &visited, vector<bool> &cycle)
    {
        visited[u] = true;
        cycle[u] = true;
        for(auto x : adj[u])
        {
            if(!visited[x])
            {
                if(DFS(x, adj, visited, cycle))
                    return true;
            }
            else if(cycle[x])
                return true;
        }
        cycle[u] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto x : pre)
            adj[x[1]].push_back(x[0]);
        vector<bool> visited(n, false);
        vector<bool> cycle(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                if(DFS(i, adj, visited, cycle))
                    return false;
        }
        return true;
    }
};