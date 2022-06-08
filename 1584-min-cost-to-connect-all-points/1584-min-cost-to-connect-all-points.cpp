class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int curr = 0;
        int n = points.size();
        int ans = 0;
        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        // for(int k = 0; k < n-1; k++)
        while(1)
        {
            visited[curr] = true;
            for(int i = 0; i < n; i++)
            {
                if(visited[i])
                    continue;
                dist[i] = min(dist[i], abs(points[curr][0]-points[i][0])+abs(points[curr][1]-points[i][1]));
            }
            curr=min_element(dist.begin(),dist.end())-dist.begin();
            if(dist[curr] == INT_MAX)
                return ans;
            ans += dist[curr];
            dist[curr] = INT_MAX;
        }
        return ans;
    }
};