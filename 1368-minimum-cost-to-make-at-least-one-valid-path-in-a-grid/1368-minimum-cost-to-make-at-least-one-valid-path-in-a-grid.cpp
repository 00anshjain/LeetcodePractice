class Solution {
public:
    int colInc[5] = {0, 1, -1, 0, 0};
    int rowInc[5] = {0, 0, 0, 1, -1};
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        deque<pair<pair<int, int>, int>> q;
        q.push_back({{0, 0}, 0});
        while(!q.empty())
        {
            auto [z, d] = q.front();
            auto [r, c] = z;
            q.pop_front();
            if(visited[r][c])
                continue;
            visited[r][c] = true;
            if(r == n-1 && c == m-1)
                return d;
            for(int i = 1; i <= 4; i++)
            {
                int R = r + rowInc[i];
                int C = c + colInc[i];
                if(R < 0 || C < 0 || R>= n || C >= m || visited[R][C])
                    continue;
                if(grid[r][c] == i)
                    q.push_front({{R, C}, d});
                else
                    q.push_back({{R, C}, d+1});
            }
        }
        return -1;
    }
};