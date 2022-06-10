class Solution {
public:
    typedef long long ll;
    int mod = 1e9+7;
    int Dijkstra(vector<pair<ll, ll>> adj[], ll n, ll src)
    {
        vector<ll> ways(n);
        vector<ll> distance(n, LONG_MAX);
        distance[src] = 0;
        ways[src] = 1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, src});
        while(!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > distance[u])  // skip if d is not updated
                continue;
            for(auto [v, dis] : adj[u])
            {
                if(distance[v] > d + dis)
                {
                    distance[v] = d + dis;
                    ways[v] = ways[u];
                    pq.push({distance[v], v});
                }
                else if(distance[v] == d + dis)
                {
                    ways[v] = (ways[v] +ways[u])%mod;
                    // ways[v] %= mod;
                }
            }
        }
        return (int)ways[n-1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll, ll>> adj[n];
        for(auto r : roads)
        {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        return Dijkstra(adj, n, 0);
        
    }
};