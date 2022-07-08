class Solution {
public:
    int q[4][2] = {{4, 0},
                   {3, 1},
                   {2, 2},
                   {1, 3}};
    double dp[201][201];
    double recur(int n, int m)
    {
        // cout<<n<<" "<<m<<endl;
        if(n <= 0 && m <= 0)    return 0.5;
        else if(n <= 0)     return 1.0;
        else if(m <= 0)     return 0.0;
        if(dp[n][m] > 0)  return dp[n][m];
        double ans = 0.0;
        for(int i = 0; i < 4; i++)
        {
            ans += (0.25 * recur(n - q[i][0], m - q[i][1]));
        }
        return dp[n][m] = ans;
    }
    double soupServings(int n) {
        // double ans = 0.0;
        if(n > 4800)
            return 1;
        memset(dp, -1, sizeof(dp));
        // vector<vector<double>> dp(200, vector<double> (200, -1));
        return recur((n+24)/25, (n+24)/25);
    }
};