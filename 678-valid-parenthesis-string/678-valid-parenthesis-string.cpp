class Solution {
public:
    bool recur(int cnt, string &s, int i, int n, vector<vector<bool>>& dp)
    {
        if(cnt < 0)
            return false;
        if(dp[i][cnt] == false)
            return false;
        if(i == n)
        {
            return dp[i][cnt] = (cnt == 0);
        }
        if(s[i] == '(')
        {
            return dp[i][cnt] = (recur(cnt+1, s, i+1, n, dp));
        }
        else if(s[i] == ')')
        {
            // cnt--;
            // if(cnt == 0)
            //     return false;
            return dp[i][cnt] = recur(cnt-1, s, i+1, n, dp);
        }
        else
        {
            return dp[i][cnt] = ((recur(cnt-1, s, i+1, n, dp) || recur(cnt+1, s, i+1, n, dp) || recur(cnt, s, i+1, n, dp)));
        }
        // return false;
    }
    bool checkValidString(string s) {
        // stack<int> st;
        int cnt = 0;
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, true));
        return recur(cnt, s, 0, s.size(), dp);
        
    }
};