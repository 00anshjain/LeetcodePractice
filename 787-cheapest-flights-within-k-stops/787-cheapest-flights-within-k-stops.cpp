class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for(int i = 0; i <= k; i++)
        {
            vector<int> pri = dist;
            for(auto x : flights)
            {
                int u = x[0];
                int v = x[1];
                int c = x[2];
                if(dist[u] != INT_MAX && pri[v] > dist[u] + c)
                {
                    pri[v] = dist[u]+ c;
                }
            }
            dist = pri;
        }
        return dist[dst] == INT_MAX ? -1: dist[dst];
    }
};