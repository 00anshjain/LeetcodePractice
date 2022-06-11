class Solution {
public:
    int cutStick(int l, int r, vector<vector<int>> &dp, vector<int> &cuts, int left, int right)
    {
        if(l == r)
            return right - left;
        if(l > r)
            return 0;
        if(dp[l][r]  != -1)
            return dp[l][r];
        int cost = right - left;
        int finalAns = INT_MAX;
        for(int i = l; i <= r; i++)
        {
            int ans = cutStick(l, i-1, dp, cuts, left, cuts[i]) + cutStick(i+1, r, dp, cuts, cuts[i], right);
            finalAns = min(finalAns, ans);
        }
        return dp[l][r] = cost + finalAns;
    }
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        return cutStick(0, m-1, dp, cuts, 0, n);
    }
};