class Solution {
public:
    int n, m;
    int DFS(int i, int j, vector<vector<int>> &grid)
    {
        if(i < 0 || j < 0 || i>= n || j >= m || grid[i][j] == 0)
            return 0;
        int ans = 1;
        grid[i][j] = 0;
        ans += DFS(i-1, j, grid);
        ans += DFS(i+1, j, grid);
        ans += DFS(i, j-1, grid);
        ans += DFS(i, j+1, grid);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    ans = max(ans, DFS(i, j, grid));
            }
        }
        return ans;
    }
};