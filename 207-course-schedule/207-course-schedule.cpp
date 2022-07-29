class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> deg(n, 0);
        for(auto x : pre)
        {
            adj[x[1]].push_back(x[0]);
            deg[x[0]]++;
        }
        int cnt = 0;
        queue<int> q;
        for(int i = 0;i < n; i++)
        {
            if(deg[i] == 0)
            {
                q.push(i);
                cnt++;
            }
        }
        while(!q.empty())
        {
            if(cnt == n)
                return true;
            int t = q.front();
            q.pop();
            for(auto x : adj[t])
            {
                deg[x]--;
                if(deg[x] == 0)
                {
                    q.push(x);
                    cnt++;
                }
            }
        }
        return false;
    }
};