class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        int x = times.size();
        for(int i = 0; i<x; i++)
        {
            adj[times[i][0]].push_back({times[i][2], times[i][1]});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        vector<bool> visited(n+1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // vector<bool> visited(n+1, false);
        pq.push(make_pair(0, k));
        // for(int i = 1; i<= n; i++)
        while(!pq.empty())
        {
            auto y = pq.top();
            pq.pop();
            int u = y.second;
            if(visited[u])
                continue;
            visited[u] = true;
            // cout<<u<<endl;
            int dis_u = y.first;
            
            for(auto x : adj[u])
            {
                int v = x.second;
                int d = x.first;
                if(!visited[v] && dist[v] > dis_u + d)
                {
                    dist[v] = d + dis_u;
                    // cout<<dist[u]<<" "<<dist[v] <<" "<<v<<endl;
                    pq.push({dist[v], v});
                }
                
            }
        }
        int mx = INT_MIN;
        for(int i = 1; i<= n; i++)
        {
            // cout<<dist[i]<<" ";
            mx = max(dist[i], mx);
        }
        // cout<<endl;
        if(mx == INT_MAX)
            return -1;
        return mx;
        
        // pq.push({0, k});
        
        
        
        
        
    }
};