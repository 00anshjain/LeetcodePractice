class Solution {
public:
    void DFS(int u, vector<int> adj[], vector<bool> &visited)
    {
        visited[u] = true;
        for(auto x : adj[u])
        {
            if(!visited[x])
                DFS(x, adj, visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        if(con.size() < n-1)
            return -1;
        vector<int> adj[n];
        for(auto x : con)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n, false);
        int cnt = 0;
        for(int i = 0; i <n; i++)
        {
            if(!visited[i])
            {
                cnt++;
                DFS(i, adj, visited);
            }
        }
        return cnt-1;
        
    }
};