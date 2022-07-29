class Solution {
public:
    // int getHeight(vector<int> adj[], int i, int p)
    // {
    //     int ht = 0;
    //     for(auto x : adj[i])
    //     {
    //         if(x == p)
    //             continue;
    //         ht = max(ht, getHeight(adj, x, i));
    //     }
    //     return ht+1;
    // }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        if(n == 1)
            return {0};
        vector<int> deg(n, 0);
        for(auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            deg[x[0]]++;
            deg[x[1]]++;
        }
        queue<int> q;
        vector<int> ans;
        vector<bool> visited(n, false);
        for(int i = 0;i < n; i++)
        {
            if(deg[i] == 1)
            {
                q.push(i);
                // visited[i] = true;
                // ans.push(i);
            }
        }
        while(!q.empty())
        {
            ans.clear();
            int sz = q.size();
            while(sz--)
            {
                int t = q.front();
                ans.push_back(t);
                q.pop();
                // ans.push_back(t);
                for(auto x : adj[t])
                {
                    deg[x]--;
                    if(deg[x] == 1)
                        q.push(x);
                }
            }
        }
        return ans;
        // int currMn = INT_MAX;
        // vector<int> ans;
        // for(int i =0; i < n; i++)
        // {
        //     int h = getHeight(adj, i, -1);
        //     if(h < currMn)
        //     {
        //         currMn = h;
        //         ans.clear();
        //         ans.push_back(i);
        //     }
        //     else if(h == currMn)
        //         ans.push_back(i);
        // }
        // return ans;
    }
};