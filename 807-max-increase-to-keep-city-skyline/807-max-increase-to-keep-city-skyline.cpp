class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int mx1 = 0, mx2 = 0;
                for(int k = 0; k < n; k++)
                {
                    mx1 = max(mx1, grid[k][j]);
                }
                for(int k = 0; k < m; k++)
                {
                    mx2 = max(mx2, grid[i][k]);
                }
                ans += (min(mx1, mx2) - grid[i][j]);
                // grid[i][j] = min(mx1, mx2);
            }
        }
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j)
        // }
        return ans;
    }
};