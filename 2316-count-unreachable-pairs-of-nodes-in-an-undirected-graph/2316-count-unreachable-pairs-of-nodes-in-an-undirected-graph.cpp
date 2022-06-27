class Solution {
public:
    typedef long long ll;
    int DFS(int u, vector<bool> &visited, vector<int> adj[])
    {
        visited[u] = true;
        int ans = 1;
        for(auto x : adj[u])
        {
            if(!visited[x])
                ans += DFS(x, visited, adj);
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> grps;
        vector<int> adj[n];
        for(auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n, false);
        ll ans = ((ll)n*(n-1))/2;
        for(int i = 0; i < n; i++)
        {
            // grp_size = 0;
            if(!visited[i])
            {
                ll grp_size = (ll)DFS(i, visited, adj);
                ans -= ((grp_size)*(grp_size-1))/2;
                // for(auto k : grps)
                //    ans += k*(ll)grp_size;
                // grps.push_back(grp_size);
            }
        }
        return ans;
    }
};