class Solution {
public:
    int n;
    void recur(int i, vector<bool> &dp, string curr, vector<string> &res, unordered_set<string> &dict, string &s)
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
                string k = s.substr(i, j-i+1);
                if(dict.find(k) != dict.end())
                {
                    string g = curr;
                    if(i == 0)
                    {
                        g += k;
                    }
                    else
                    {
                        g += " ";
                        g += k;
                    }
                    recur(j+1, dp, g, res, dict, s);
                }
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i-1; j>= 0; j--)
            {
                if(dp[j])
                {
                    if(dict.find(s.substr(j, i-j)) != dict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        vector<string> res;
        if(!dp[n])
            return res;
        string curr = "";
        recur(0, dp, curr, res, dict, s);
        return res;
    }
};