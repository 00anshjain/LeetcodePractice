class Solution {
public:
    int t = 0;
    void DFS(vector<int> &dis, vector<int> &low, int u, vector<int> adj[], vector<vector<int>>& res, int p)
    {
        dis[u] = ++t;
        low[u] = dis[u];
        for(auto v : adj[u])
        {
            if(v == p)
                continue;
            if(dis[v] == -1)
            {
                DFS(dis, low, v, adj, res, u);
                low[u] = min(low[u], low[v]);
            }
            if(low[v] > dis[u])
            {
                res.push_back({u, v});
            }
            else{
                low[u] = min(low[u], dis[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> res;
        t = 0;
        vector<int> adj[n];
        for(auto x : con)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> dis(n, -1), low(n, -1);
        // vector<bool> inStack(n, false);
        // stack<int> st;
        for(int i = 0; i < n; i++)
        {
            if(dis[i] == -1)
                DFS(dis, low, i, adj, res, -1);
        }
        return res;
    }
};