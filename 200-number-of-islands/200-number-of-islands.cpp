class Solution {
public:
    int n, m;
    bool isSafe(vector<vector<char>>& grid, int row, int col)
    {
        if(row >= 0 && col >= 0 && row < n && col < m && grid[row][col] == '1')
            return true;
        return false;
    }
    void helper(vector<vector<char>>& grid, int row, int col)
    {
        grid[row][col] = '2';
        if(isSafe(grid, row-1, col))
            helper(grid, row-1, col);
        if(isSafe(grid, row+1, col))
            helper(grid, row+1, col);
        if(isSafe(grid, row, col-1))
            helper(grid, row, col-1);
        if(isSafe(grid, row, col+1))
            helper(grid, row, col+1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    helper(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};