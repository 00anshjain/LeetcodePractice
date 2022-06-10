class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        int m = edges.size();
        for(int i = 0; i < m; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> dist(n, 0);
        vector<bool> visited(n, false);
        priority_queue<pair<double, int>> pq;
        if(start == end)
            return 1;
        pq.push({(double)1, start});
        dist[start] = 1;
        while(!pq.empty())
        {
            int u = pq.top().second;
            double pro = pq.top().first;
            pq.pop();
            if(visited[u])
                continue;
            visited[u] = true;
            if(u == end)
                return pro;
            for(auto x : adj[u])
            {
                int v = x.first;
                if(visited[v])
                    continue;
                double prob_uv = x.second;
                if(dist[v] < dist[u]*prob_uv)
                {
                    dist[v] = dist[u]*prob_uv;
                    pq.push({dist[v], v});
                }

            }
        }
        return 0;
    }
};