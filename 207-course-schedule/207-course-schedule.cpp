class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
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
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            for(auto x : adj[t])
            {
                in[x]--;
                if(in[x] == 0)
                    q.push(x);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(in[i] != 0)
                return false;
        }
        return true;
    }
};