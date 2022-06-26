class Solution {
public:
//     Using 0-1 DFS
    int xDir[4] = {0, 0, 1, -1};
    int yDir[4] = {1, -1, 0, 0};
    bool isSafe(int r, int c, int n, int m, vector<vector<bool>> &visited)
    {
        if(r < 0 || c < 0 || r >= n || c >= m || visited[r][c])
            return false;
        return true;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        deque<vector<int>> q;
        if(grid[0][0] == 1)
            q.push_back({1, 0, 0});
        else
            q.push_back({0, 0, 0});
        if(n == 1 && m == 1)
            return (q.front())[0];
        // visited[0][0] = true;
        // dist[0][0] = (q.front())[0];
        while(!q.empty())
        {
            auto t = q.front();
            q.pop_front();
            int r = t[1];
            int c = t[2];
            int d = t[0];
            if(visited[r][c])
                continue;
            visited[r][c] = true;
            if(r == n-1 && c == m-1)
                return d;
            for(int i = 0; i < 4; i++)
            {
                int R = r + xDir[i];
                int C = c + yDir[i];
                if(!isSafe(R, C, n, m, visited))
                    continue;
                if(grid[R][C] == 1)
                    q.push_back({d+1, R, C});
                else
                    q.push_front({d, R, C});
            }
            
        }
        return -1;
        
        
    }
};