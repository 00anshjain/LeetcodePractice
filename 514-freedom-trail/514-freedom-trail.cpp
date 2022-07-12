class Solution {
public:
    int n, m;
    int recur(string &ring, int i, string &key, int j, vector<int> arr[], vector<vector<int>>& dp)
    {
        if(j == m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(auto x : arr[key[j] - 'a'])
        {
            ans = min(ans, 1 + min(abs(i-x), n - abs(i - x)) + recur(ring, x, key, j+1, arr, dp));
        }
        return dp[i][j] = ans;
    }
    int findRotateSteps(string ring, string key) {
        vector<int> pos[26];
        n = ring.size();
        m = key.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < ring.size(); i++)
            pos[ring[i] - 'a'].push_back(i);
        return recur(ring, 0, key, 0, pos, dp);
    }
};