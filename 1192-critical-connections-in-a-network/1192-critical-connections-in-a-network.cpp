class Solution {
public:
    int t = 0;
    void DFS(int u, vector<int> &dis, vector<int> &low, int par, vector<int> adj[], vector<vector<int>>& res)
    {
        dis[u] = t++;
        low[u] = dis[u];
        for(auto v : adj[u])
        {
            if(v == par)
                continue;
            if(dis[v] == -1)
            {
                DFS(v, dis, low, u, adj, res);
                low[u] = min(low[u], low[v]);
                if(dis[u] < low[v])
                    res.push_back({u, v});
            }
            else
            {
                low[u] = min(low[u], dis[v]);
            }
        }
        // inStack[u] = false;
        // st.pop();
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<int> adj[n];
        for(auto x : con)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            
        }
        vector<int> dis(n, -1); //discoveryTime
        vector<int> low(n, INT_MAX); //lowTime
        t = 0;
        // stack<int> st;
        // vector<bool> inStack(n, false);
        vector<vector<int>> res;
        for(int i = 0; i < n; i++)
        {
            if(dis[i] == -1)
            {
                DFS(i, dis, low, -1, adj, res);
            }
        }
        
        
        return res;
        
    }
};