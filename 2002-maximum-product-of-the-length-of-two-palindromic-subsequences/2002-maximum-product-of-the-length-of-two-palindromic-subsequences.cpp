class Solution {
public:
    int ans, n;
    bool isPalin(string s)
    {
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    int fun(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == s[j])
            return dp[i][j] = 2 + fun(s, i+1, j-1, dp);
        return max(fun(s, i, j-1, dp), fun(s, i+1, j, dp));
    }
    void func(string &s, int i, string curr, int mask)
    {
        if(i == n)
        {
            if(!isPalin(curr))
                return;
            string check = "";
            int k = curr.size();
            for(int j = 0; j < n; j++)
            {
                if((mask & (1<<j))  == 0)
                {
                    check += s[j];
                }
            }
            int sz = check.size();
            vector<vector<int>> dp(sz, vector<int>(sz, -1));
            ans = max(ans, k * fun(check, 0, sz - 1, dp));
            return;
        }
        func(s, i+1, curr, mask);
        func(s, i+1, curr + s[i], mask | (1<<i));
    }
    int maxProduct(string s) {
        ans = 0;
        n = s.size();
        string curr = "";
        func(s, 0, curr, 0);
        return ans;
    }
};