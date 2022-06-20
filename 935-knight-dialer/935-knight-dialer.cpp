class Solution {
public:
    typedef long long ll;
    int mod = 1e9+7;
    ll dp[4][3][5001];
    int xDir[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int yDir[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    bool isSafe(int r, int c)
    {
        if(r < 0 || r > 3)
            return false;
        if(c < 0 || c > 2)
            return false;
        if(r == 3 && c != 1)
            return false;
        return true;
        
    }
    int helper(int r, int c, int n)
    {
        if(!isSafe(r, c))
            return 0;
        if(n == 0)
            return 1;
        if(dp[r][c][n] != -1)
            return dp[r][c][n];
        ll ans = 0;
        for(int i = 0; i < 8; i++)
        {
            ans += helper(r + xDir[i], c + yDir[i], n-1);
            ans %= mod;
        }
        return dp[r][c][n] = ans;
    }
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        ll ans = 0;
        ans += helper(3, 1, n-1);
        for(int i = 1; i <= 9; i++)
        {
            ans += helper((i-1)/3, (i-1)%3, n-1);
            ans %=  mod;
        }
        return ans;
    }
};