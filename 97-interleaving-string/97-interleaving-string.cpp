class Solution {
public:
    bool recur(string &s1, string &s2, string &s3, int n, int m, vector<vector<bool>> &dp)
    {
        if(!dp[n][m])
            return false;
        if(n == 0 && m == 0)
            return true;
        // cout<<n<<" "<<m<<" "<<n+m-1<<endl;
        if(n > 0 && s1[n-1] == s3[n+m-1])
        {
            if(recur(s1, s2, s3, n-1, m, dp))
                return true;
        }
        if(m > 0 && s2[m-1] == s3[n+m-1])
        {
            if(recur(s1, s2, s3, n, m-1, dp))
                return true;
        }
        return dp[n][m] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, true));
        return recur(s1, s2, s3, s1.size(), s2.size(), dp);
    }
};