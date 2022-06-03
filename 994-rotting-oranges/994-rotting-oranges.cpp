class Solution {
public:
    // vector<int> xDir = {0, 0, 1, -1};
    // vector<int> yDir = {1, -1, 0, 0};
    int xDir[4] = {0, 0, 1, -1};
    int yDir[4] = {1, -1, 0, 0};
    bool isFresh(int r, int c, int n, int m, vector<vector<int>>& grid)
    {
        if(r<0 || c<0 || r >= n || c >= m || grid[r][c] != 1)
        {
            // cout<<"f  "<<endl;
            return false;
        }    
        // cout<<"t"<<endl;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int turn = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        // cout<<"size ="<<q.size()<<endl;
        while(!q.empty())
        {
            int z = q.size();
            turn++;
            while(z--)
            {
                int i = q.front().first;
                int j = q.front().second;
                // cout<<i<<"  "<<j<<" done"<<endl;
                q.pop();
                for(int k = 0; k < 4; k++)
                {
                    // cout<<"i"<<i+xDir[k]<<" j"<<j+yDir[k]<<"   fresh to unfresh"<<endl;
                    if(isFresh(i+xDir[k], j+yDir[k], n, m, grid))
                    {
                        // cout<<"i"<<i<<" j"<<j<<"   in here"<<endl;
                        q.push({i+xDir[k], j+yDir[k]});
                        grid[i+xDir[k]][j+yDir[k]] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        if(turn == 0)
            return 0;
        return turn-1;
    }
};