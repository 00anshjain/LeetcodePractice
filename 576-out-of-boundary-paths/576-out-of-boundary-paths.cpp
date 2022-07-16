class Solution {
public:
    typedef long long ll;
    int M, N;
    ll visited[51][51][51];
    int rDir[4] = {1, -1, 0, 0};
    int cDir[4] = {0, 0, 1, -1};
    int mod = 1e9+7;
    int recur(int r, int c, int move)
    {
        if(r < 0 || c < 0 || r >= M || c>= N)
            return 1;
        if(move == 0)
            return 0;
        if(visited[r][c][move] != -1)
            return visited[r][c][move];
        ll ans = 0;
        for(int i = 0; i < 4; i++)
        {
            ans += recur(r + rDir[i], c + cDir[i], move - 1);
            ans %= mod;
        }
        return visited[r][c][move] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M = m; N = n;
        memset(visited, -1, sizeof(visited));
        
        // vector<vector<vector<ll>>> visited(m, vector<vector<ll>>(n, vector<ll>(maxMove+1, -1)));
        return recur(startRow, startColumn, maxMove);
        // return -1;
    }
};