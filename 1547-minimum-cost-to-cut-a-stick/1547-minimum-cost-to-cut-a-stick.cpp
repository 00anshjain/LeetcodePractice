class Solution {
public:
    int cutStick(int l, int r, vector<vector<int>> &dp, vector<int> &cuts)
    {
        if(l + 1 >= r)
            return 0;
        if(dp[l][r]  != -1)
            return dp[l][r];
        // int cost = right - left;
        int finalAns = INT_MAX;
        for(int i = l+1; i < r; i++)
        {
            int ans = cutStick(l, i, dp, cuts) + cutStick(i, r, dp, cuts) + cuts[r] - cuts[l];
            finalAns = min(finalAns, ans);
        }
        // if(finalAns == INT_MAX)
        //     return dp[l][r] = cuts[r] - cuts[l];
        return dp[l][r] = finalAns;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        return cutStick(0, m-1, dp, cuts);
    }
};