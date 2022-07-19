class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) {
        vector<vector<int>> dist(n, vector<int>(n, -1));
        for(auto x : edges)
        {
            dist[x[0]][x[1]] = x[2];
            dist[x[1]][x[0]] = x[2];
        }
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    dist[j][j] = 0;
                    if(i == k || j == k)
                        continue;
                    if(dist[i][k] != -1 && dist[k][j] != -1)
                    {
                        if(dist[i][j] == -1)
                            dist[i][j] = dist[i][k] + dist[k][j];
                        else
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        int ans = 0, ansCnt = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(dist[i][j] <= thresh && dist[i][j] != -1)
                    cnt++;
            }
            // cout<<i<<" "<<ansCnt<<" "<<cnt<<endl;
            if(cnt <= ansCnt)
            {
                ansCnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};