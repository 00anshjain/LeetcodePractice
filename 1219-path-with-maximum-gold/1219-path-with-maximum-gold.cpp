class Solution {
public:
    int ans;
    int n, m;
    int xMove[4] = {-1, 1, 0, 0};
    int yMove[4] = {0, 0, 1, -1};
    void recur(vector<vector<int>>& grid, int row, int col, int cnt)
    {
        if(row >= n || row < 0 || col >= m || col < 0 || grid[row][col] == 0)
        {
            ans = max(ans, cnt);
            return;
        }
        int k = grid[row][col];
        grid[row][col] = 0;
        for(int i = 0; i < 4; i++)
        {
            recur(grid, row + xMove[i], col + yMove[i], cnt+k);
        }
        grid[row][col] = k;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <  m; j++)
            {
                recur(grid, i, j, 0);
            }
        }
        return ans;
    }
};