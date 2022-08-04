class Solution {
public:
    struct Cell{
        int row;
        int col;
        int cost;
        Cell(int r, int c, int co)
        {
            row = r;
            col = c;
            cost = co;
        }
    };
    int rdir[5] = {0, 0, 0, 1, -1};
    int cdir[5] = {0, 1, -1, 0, 0};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        deque<Cell> q;
        q.push_back(Cell(0, 0, 0));
        while(!q.empty())
        {
            Cell cell = q.front();
            q.pop_front();
            int r = cell.row;
            int c = cell.col;
            int co = cell.cost;
            if(grid[r][c] == -1)
                continue;
            if(r == n-1 && c == m-1)
                return co;
            // grid[r][c] = -1;
            for(int k = 1; k <= 4; k++)
            {
                int R = r + rdir[k];
                int C = c + cdir[k];
                if(R < 0 || C < 0 || R >= n || C >= m)
                    continue;
                if(grid[r][c] == k)
                    q.push_front(Cell(R, C, co));
                else
                    q.push_back(Cell(R, C, co+1));
            }
            grid[r][c] = -1;
        }
        return -1;
    }
};