class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        vector<long long> ways(n, 0l);
        for(auto x : roads)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0l, 0});
        vector<long long> dist(n, LONG_MAX);
        dist[0] = 0l;
        ways[0] = 1l;
        // long long cnt = 0l;
        while(!pq.empty())
        {
            pair<long long, int> p = pq.top();
            pq.pop();
            int u = p.second;
            long long d = p.first;
            if(dist[u] < d)
                continue;
            if(u == n-1)
            // {
            //     cnt++;
            //     cnt %= mod;
                continue;
            // }
            if(d >= dist[n-1])
                continue;
            for(auto t : adj[u])
            {
                int v = t.first;
                long long duv = t.second;
                if(dist[v] > dist[u] + duv)
                {
                    ways[v] = ways[u];
                    dist[v] = dist[u] + duv;
                    pq.push({dist[v], v});
                }
                else if(dist[v] == dist[u] + duv)
                {
                    ways[v] += ways[u];
                    ways[v] %= mod;
                    // dist[v] = dist[u] + duv;
                    // pq.push({dist[v], v});
                }
            }
        }
        // cout<<dist[n-1]<<endl;
        return ways[n-1];
    }
};