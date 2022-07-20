class Solution {
public:
    int DFS(int u, vector<int> adj[], vector<int>& informTime)
    {
        int ans = 0;
        bool flag = false;
        for(auto x : adj[u])
        {
            flag = true;
            ans = max(ans, DFS(x, adj, informTime));
        }
        if(!flag)
            return 0;
        return ans + informTime[u];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i = 0; i < n; i++)
        {
            if(i == headID)
                continue;
            adj[manager[i]].push_back(i);
        }
        return DFS(headID, adj, informTime);
        // queue<pair<int, int>> q;
        // q.push({headID, 0});
        // int ans = 0;
        // while(!q.empty())
        // {
        //     auto p = q.front();
        //     q.pop();
        //     int u = p.first;
        //     int d = p.second;
        //     ans = max(ans, d);
        //     for(auto x : adj[u])
        //     {
        //         q.push({x, d + informTime[u]});
        //     }
        // }
        // return ans;
    }
};