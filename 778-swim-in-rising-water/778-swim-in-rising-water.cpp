class Solution {
public:
    class Cell{
      public:
        int r;
        int c;
        int cost;
        Cell(int r, int c, int cost)
        {
            this->r = r;
            this->c = c;
            this->cost = cost;
        }
    };
    struct comp{
        bool operator()(Cell &a, Cell &b)
        {
            return a.cost > b.cost;
        }
    };
    int rdir[4] = {0, 0, 1, -1};
    int cdir[4] = {1, -1, 0, 0};
    bool isSafe(int r, int c, int n, int m)
    {
        if(r < 0 || c < 0 || r >= n || c >= m)
            return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<Cell, vector<Cell>, comp> pq;
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        pq.push(Cell(0, 0, grid[0][0]));
        while(!pq.empty())
        {
            Cell t= pq.top();
            pq.pop();
            int r = t.r;
            int c = t.c;
            int cost = t.cost;
            if(dp[r][c] < cost)
                continue;
            if(r == n-1 && c == m-1)
                return cost;
            for(int k = 0; k < 4; k++)
            {
                int R = r + rdir[k];
                int C = c + cdir[k];
                if(!isSafe(R, C, n, m))
                    continue;
                int p = max(cost, grid[R][C]);
                if(dp[R][C] > cost)
                {
                    dp[R][C] = p;
                    pq.push(Cell(R, C, dp[R][C]));
                }
            }
        }
        return -1;
    }
};