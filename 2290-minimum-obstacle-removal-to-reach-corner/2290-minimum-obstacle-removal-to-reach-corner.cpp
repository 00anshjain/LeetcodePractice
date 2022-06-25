class Solution {
public:
    int xDir[4] = {0, 0, 1, -1};
    int yDir[4] = {1, -1, 0, 0};
    bool isSafe(int r, int c, int n, int m)
    {
        if(r < 0 || c < 0 || r >= n || c >= m)
            return false;
        return true;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        if(grid[0][0] == 1)
            pq.push({1, 0, 0});
        else
            pq.push({0, 0, 0});
        if(n == 1 && m == 1)
            return (pq.top())[0];
        // visited[0][0] = true;
        dist[0][0] = (pq.top())[0];
        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            int r = t[1];
            int c = t[2];
            int d = t[0];
            if(d > dist[r][c])
                continue;
            // if(visited[r][c])
            //     continue;
            // visited[r][c] = true;
            for(int i = 0; i < 4; i++)
            {
                int R = r + xDir[i];
                int C = c + yDir[i];
                if(!isSafe(R, C, n, m))
                    continue;
                int D = d; 
                if(grid[R][C] == 1)
                    D = d + 1;
                if(dist[R][C] > D)
                {
                    dist[R][C] = D;
                    pq.push({D, R, C});
                }
                // visited[R][C] = true;
            }
            
        }
        return dist[n-1][m-1];
        
        
    }
};