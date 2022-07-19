class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int, int>> adj[n];
        for(auto x : edges)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        int ans = -1;
        int mnNghbr = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});
            while(!pq.empty())
            {
                auto t = pq.top();
                pq.pop();
                int d = t.first;
                int u = t.second;
                if(d > threshold)
                    continue;
                for(auto x : adj[u])
                {
                    int v = x.first;
                    int duv = x.second;
                    if(dist[v] >= dist[u] + duv)
                    {
                        dist[v] = dist[u] + duv;
                        pq.push({dist[v], v});
                    }
                }
            }
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(dist[j] <= threshold)
                    cnt++;
            }
            if(cnt <= mnNghbr)
            {
                ans = i;
                mnNghbr = cnt;
            }
        }
        return ans;
    }
};