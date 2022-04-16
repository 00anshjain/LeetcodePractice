class Solution {
public:
    int ans = 0, n;
    bool isPalin(string &s)
    {
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int recur(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == j)
            return dp[i][j] = 1;
        if(s[i] == s[j])
            return dp[i][j] = 2 + recur(s, i+1, j-1, dp);
        return dp[i][j] = max(recur(s, i+1, j, dp), recur(s, i, j-1, dp));
    }
    void func(string &s, int i, string curr, int mask)
    {
        if(i == n)
        {
            if(!isPalin(curr))
                return;
            string p = "";
            for(int j = 0; j < n; j++)
            {
                if(!(mask & (1<<j)))
                {
                    p += s[j];
                }
            }
            int k = curr.size();
            int sz = p.size();
            vector<vector<int>> dp(sz + 1, vector<int>(sz+1, -1));
            ans = max(ans, k * recur(p, 0, sz - 1, dp));
            return;
        }
        func(s, i+1, curr, mask);
        func(s, i+1, curr+ s[i], mask | (1<<i));
    }
    int maxProduct(string s) {
        ans = 0;
        n = s.size();
        string curr = "";
        func(s, 0, curr, 0);
        return ans;
    }
};