class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i = 0; i < n; i++)
        {
            if(i == headID)
                continue;
            adj[manager[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({headID, 0});
        int ans = 0;
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int u = p.first;
            int d = p.second;
            ans = max(ans, d);
            for(auto x : adj[u])
            {
                q.push({x, d + informTime[u]});
            }
        }
        return ans;
    }
};