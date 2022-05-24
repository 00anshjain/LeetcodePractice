class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> in(n, 0);
        for(auto x : pre)
        {
            in[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(in[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int t = q.front();
            ans.push_back(t);
            q.pop();
            for(auto x : adj[t])
            {
                in[x]--;
                if(in[x] == 0)
                    q.push(x);
            }
        }
        if(ans.size() < n)
            return {};
        return ans;
    }
};