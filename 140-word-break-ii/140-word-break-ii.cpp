class Solution {
public:
    void recur(vector<string> &res, string &s, vector<bool> &dp, unordered_set<string> &dict, int i, int n, string curr)
    {
        if(i == n)
        {
            res.push_back(curr);
            return;
        }
        for(int j = i; j < n; j++)
        {
            if(dp[j+1])
            {
                string z = s.substr(i, j-i+1);
                if(dict.find(z) != dict.end())
                {
                    if(i == 0)
                        recur(res, s, dp, dict, j+1, n, curr + z);
                    else
                        recur(res, s, dp, dict, j+1, n, curr+ ' '+ z);
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        // recur()
        for(int j = 1; j <= n; j++)
        {
            for(int i = j-1; i >= 0; i--)
            {
                if(dp[i] && (dict.find(s.substr(i, j-i)) != dict.end()))
                {
                    dp[j] = true;
                    break;
                }
            }
        }
        vector<string> res;
        if(!dp[n])
            return res;
        string curr = "";
        recur(res, s, dp, dict, 0, n, curr);
        return res;
    }
};