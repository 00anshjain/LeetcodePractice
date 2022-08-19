class Solution {
public:
    struct cell{
        public:
        int r;
        int c;
        int cost;
        cell(int r, int c, int cost)
        {
            this->r = r;
            this->c = c;
            this->cost = cost;
        }
    };
    struct comp{
        bool operator()(cell &a, cell &b)
        {
          return a.cost > b.cost;
        }
    };
    vector<int> rdir = {0, 0, 1, -1};
    vector<int> cdir = {1, -1, 0, 0};
    bool isSafe(int r, int c, int n, int m)
    {
        if(r < 0 || c < 0 || r>= n || c >= m)
            return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = 0;
        priority_queue<cell, vector<cell>, comp> pq;
        pq.push(cell(0, 0, 0));
        while(!pq.empty())
        {
            cell t = pq.top();
            pq.pop();
            int r = t.r;
            int c = t.c;
            int cost = t.cost;
            if(r == n-1 && c == m-1)
                return cost;
            if(dp[r][c] < cost)
                continue;
            for(int k = 0; k < 4; k++)
            {
                int R = r + rdir[k];
                int C = c + cdir[k];
                if(!isSafe(R, C, n, m))
                    continue;
                int pr = max(dp[r][c], abs(heights[r][c] - heights[R][C]));
                if(dp[R][C] > pr)
                {
                    dp[R][C] = min(dp[R][C], pr);
                    pq.push(cell(R, C, dp[R][C]));
                }
            }
        }
        return -1;
    }
};