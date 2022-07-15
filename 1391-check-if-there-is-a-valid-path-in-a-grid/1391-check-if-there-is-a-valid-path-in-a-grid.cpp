class Solution {
public:
    int n, m;
    bool check(int x, int y, int parx, int pary, map<int, vector<pair<int, int>>> &dir, vector<vector<int>>& grid)
    {
        if(x < 0 || y < 0 || x >= n || y >= m)
            return false;
        int k = grid[x][y];
        if(k == 0)
            return false;
        //already visited vertex// so as when cycle form we can stop
        // grid[x][y] = 0;
        if(parx == x + dir[k][0].first && pary == y + dir[k][0].second)
        {
            if(x == n-1 && y == m-1) //placed inside if conditon so that parent is verified of the current cell
                return true;
            grid[x][y] = 0;
            return check(x + dir[k][1].first, y + dir[k][1].second, x, y, dir, grid);
        }
        else if(parx == x + dir[k][1].first && pary == y + dir[k][1].second)
        {
            if(x == n-1 && y == m-1)//placed inside if conditon so that parent is verified of the current cell
                return true;
            grid[x][y] = 0;
            return check(x + dir[k][0].first, y + dir[k][0].second, x, y, dir, grid);
        }
        else
            return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        map<int, vector<pair<int, int>>> dir;
        dir[1].push_back({0, -1});
        dir[1].push_back({0, +1});
        dir[2].push_back({-1, 0});
        dir[2].push_back({1, 0});
        dir[3].push_back({0, -1});
        dir[3].push_back({1, 0});
        dir[4].push_back({0, 1});
        dir[4].push_back({1, 0});
        dir[5].push_back({-1, 0});
        dir[5].push_back({0, -1});
        dir[6].push_back({-1, 0});
        dir[6].push_back({0, +1});
        
        n = grid.size();
        m = grid[0].size();
        int x = 0, y = 0;
        if(x == n-1 && y == m-1)
            return true;
        vector<vector<int>> a, b, c, d;
        a = grid;
        b = grid;
        c = grid;
        d = grid;
        
        return check(0, 0, -1, 0, dir, a) || check(0, 0, 0, -1, dir, b) || 
            check(0, 0, 1, 0, dir, c) ||check(0, 0, 0, 1, dir, d) ;
    }
};