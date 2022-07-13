class Solution {
public:
    int n, m, t;
    bool flag = false;
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
                if(grid[i][j] && !visited[i][j])
                {
                    cnt++;
                    DFS(grid, i, j, visited);
                }
            }
        }
        return cnt;
    }
    bool isSafe2(int r, int c)
    {
        if(r < 0 || c < 0 || r>= n || c >= m)
            return false;
        return true;
    }
    void checkArticulation(vector<vector<int>> &dis, vector<vector<int>> &low, int r, int c, int p, vector<vector<int>>& grid)
    {
        if(flag)
            return;
        dis[r][c] = ++t;
        low[r][c] = dis[r][c];
        int child = 0;
        for(int i = 0; i < 4; i++)
        {
            int R = r + dir[i][0];
            int C = c + dir[i][1];
            if(!isSafe2(R, C) || grid[R][C] == 0)
            {
                continue;
            }
            if(dis[R][C] == -1)
            {
                checkArticulation(dis, low, R, C, 0, grid);
                if(flag)
                    return;
                low[r][c] = min(low[r][c], low[R][C]);
                if(low[R][C] >= dis[r][c] && p != -1)
                {
                    // cout<<R<<" "<<C<<endl;
                    flag = true;
                    return;
                }
                child++;
            }
            else
            {
                low[r][c] = min(low[r][c], dis[R][C]);
            }
        }
        if(p == -1 && child > 1)
        {
            flag = true;
        }
        
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(countDFS(grid) != 1)
        {
            return 0;
        }
        t = 0;
        flag = false;
        // vector<vector<bool>> isArti(n, vector<bool>(m, false));
        vector<vector<int>> dis(n, vector<int>(m, -1));
        vector<vector<int>> low(n, vector<int>(m, -1));
        bool gotOne = false;
        int R, C;
        int cntOne = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    cntOne++;
                    if(!gotOne)
                    {
                    R = i; 
                    C = j;
                    gotOne = true;
                    }//break;
                }
            }
            // if(gotOne)
            //     break;
        }
        if(cntOne == 1)
            return 1;
        checkArticulation(dis, low, R, C, -1, grid);
        if(flag)
            return 1;
        return 2;
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(grid[i][j] == 1)
//                 {
//                     grid[i][j] = 0;
//                     if(countDFS(grid) != 1)
//                         return 1;
//                     grid[i][j] = 1;
//                 }
//             }
//         }
        // return 2;
    }
};