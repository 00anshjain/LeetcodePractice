class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                adj[i].push_back({j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
            }
            
        }
        int ans = 0;
        int cnt = 0;
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n, INT_MAX);
        pq.push({0, 0});
        distance[0] = 0;
        while(cnt != n)
        {
            auto t = pq.top();
            pq.pop();
            int u = t.second;
            if(visited[u])
                continue;
            int d = t.first;
            ans += d;
            visited[u] = true;
            cnt++;
            for(auto x : adj[u])
            {
                if(!visited[x.first] && x.second < distance[x.first])
                {
                    distance[x.first] = x.second;
                    pq.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};