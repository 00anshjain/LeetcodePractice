class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> r(n, vector<int>(n, 0));
        vector<int> total(n, 0); //total number of roads from one vertex
        for(auto x : roads)
        {
            r[x[0]][x[1]]++;
            r[x[1]][x[0]]++;
            total[x[0]]++;
            total[x[1]]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
               ans = max(ans, total[i] + total[j] - r[i][j]); 
            }
        }
        // for(auto x : roads)
        // {
        //     ans = max(ans, total[x[0]] + total[x[1]] - r[x[0]][x[1]]);
        // }
        return ans;
    }
};