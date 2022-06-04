class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        for(string w : words)
        {
            int n = w.size();
            if(n == 0)
                continue;
            dict.erase(w);
            vector<bool> dp(n+1, false);
            dp[0] = true;
            for(int j = 1; j <= n; j++)
            {
                for(int i = j-1; i>= 0; i--)
                {
                    if(dp[i] && (dict.find(w.substr(i, j-i)) != dict.end()) )
                    {
                        dp[j] = true;
                        break;
                    }
                }
            }
            if(dp[n])
                res.push_back(w);
            dict.insert(w);
        }
        return res;
    }
};