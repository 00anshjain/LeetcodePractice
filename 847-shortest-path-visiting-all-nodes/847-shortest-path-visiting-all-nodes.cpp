class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        int mask = 0;//for storing visited
        queue<pair<int, int>> q;
        int n = adj.size();
        vector<vector<bool>> visited(n, vector<bool>((1<<n+1)-1, false));
        for(int i = 0; i < n; i++)
        {
            q.push({i, mask | (1<<i)});
            visited[i][1<<i] = true;
            // visited[]
        }
        int maxMask = (1<<n) - 1;
        int path = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                pair<int, int> p = q.front();
                q.pop();
                int u = p.first;
                int m = p.second;
                if(m == maxMask)
                    return path;
                for(auto v : adj[u])
                {
                    if(!visited[v][m|(1<<v)])
                    {
                        q.push({v, m|(1<<v)});
                        visited[v][m|(1<<v)] = true;
                        // if(m == )
                    }
                }
            }
            path++;
        }
        return -1;
    }
};