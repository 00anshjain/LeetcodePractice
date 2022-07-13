class Solution {
public:
    int n, m;
    bool isSafe(int i, int j, vector<vector<bool>> &visited)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j])
            return false;
        return true;
    }
    int dir[4][2] = {{1, 0},
                     {-1, 0},
                     {0, 1},
                     {0, -1}};
    void DFS(vector<vector<int>>& grid, int r, int c, vector<vector<bool>> &visited)
    {
        visited[r][c] = true;
        for(int i = 0; i < 4; i++)
        {
            if(isSafe(r+dir[i][0], c+dir[i][1], visited) && grid[r+dir[i][0]][c+dir[i][1]])
                DFS(grid, r+dir[i][0], c+dir[i][1], visited);
        }
    }
    int countDFS(vector<vector<int>>& grid)
    {
        int cnt = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // cout<<i<<" "<<j<<"visited = "<<visited[i][j]<<endl;
                if(grid[i][j] && !visited[i][j])
                {
                    cnt++;
                    // cout<<i<<" "<<j<<endl;
                    DFS(grid, i, j, visited);
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        // cout<<countDFS(grid)<<endl;
        if(countDFS(grid) != 1)
        {
            return 0;
        }
        // int c =  countDFS(grid);
//         if(c != 1)
//             return 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    if(countDFS(grid) != 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};