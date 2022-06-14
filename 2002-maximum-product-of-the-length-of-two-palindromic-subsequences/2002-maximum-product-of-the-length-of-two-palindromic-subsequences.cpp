class Solution {
public:
    int n, ans;
    bool isPalin(string &s)
    {
        int i = 0, k = s.size()-1;
        while(i < k)
        {
            if(s[i++] != s[k--])
                return false;
        }
        return true;
        
    }
    int LPS(string &s)
    {
        int k = s.size();
        if(k <= 1)
            return k;
        vector<vector<int>> dp(k, vector<int>(k));
        int ans = 0;
        for(int i = 0; i < k-1; i++)
        {
            dp[i][i] = 1;
            ans = 1;
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 2;
                ans = 2;
            }
            else
                dp[i][i+1] = 1;
        }
        dp[k-1][k-1] = 1;
        ans = max(ans, dp[k-1][k-1]);
        for(int i = k-3; i >= 0; i--)
        {
            for(int j = i+2; j< k; j++)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i+1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return ans;
    }
    void recur(int i, string& s1, string &s, int mask)
    {
        if(i == n)
        {
            if(isPalin(s1))
            {
                string g = "";
                for(int j = 0; j < n; j++)
                {
                    if(!(mask & (1<<j)))
                    {
                        g += s[j];
                    }
                }
                int k = s1.size();
                int l = LPS(g);
                // cout<<s1<<" "<<s2<<endl;
                
                ans = max(ans, k*l);
            }
            return;
        }
        recur(i+1, s1, s, mask);
        s1 += s[i];
        recur(i+1, s1, s, mask | (1<<i));
        s1.pop_back();
    }
    int maxProduct(string s) {
        ans = 0;
        n = s.size();
        int mask = 0;
        string s1 = "";
        recur(0, s1, s, mask);
        return ans;
    }
};