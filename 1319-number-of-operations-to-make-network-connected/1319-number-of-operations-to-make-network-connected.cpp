class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        if(con.size() < n-1)
            return -1;
        vector<int> adj[n];
        for(auto x : con)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            
        }
        vector<int> dist(n, INT_MAX);
        int cnt = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                cnt++;
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
                pq.push({0, i});
                dist[i] = 0;
                // visited[i] = true;
                while(!pq.empty())
                {
                    int u = pq.top().second;
                    int d = pq.top().first;
                    pq.pop();
                    if(visited[u])
                        continue;
                    visited[u] = true;
                    for(auto v : adj[u])
                    {
                        if(dist[v] == INT_MAX || dist[v] >= d + 1)
                        {
                            dist[v] = dist[u] + 1;
                            pq.push({dist[v],v});
                        }
                    }
                }
            }
        }
        return cnt-1;
    }
};