class Solution {
public:
    unordered_set<string> hasFormed;
    bool canForm(string w, unordered_set<string> &dict)
    {
        if(hasFormed.count(w))
            return true;
        int n = w.size();
        for(int i = 1; i < n; i++)
        {
            string left = w.substr(0, i);
            string right = w.substr(i);
            if(dict.find(left) != dict.end())
            {
                if(dict.find(right) != dict.end() || canForm(right, dict)) 
                {
                    hasFormed.insert(w);
                    return true;
                }
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        for(string w : words)
        {
            if(canForm(w, dict))
            {
                // hasFormed.insert(w);
                res.push_back(w);
            }
        }
        // for(string w : words)
        // {
        //     int n = w.size();
        //     if(n == 0)
        //         continue;
        //     dict.erase(w);
        //     vector<bool> dp(n+1, false);
        //     dp[0] = true;
        //     for(int j = 1; j <= n; j++)
        //     {
        //         for(int i = j-1; i>= 0; i--)
        //         {
        //             if(dp[i] && (dict.find(w.substr(i, j-i)) != dict.end()) )
        //             {
        //                 dp[j] = true;
        //                 break;
        //             }
        //         }
        //     }
        //     if(dp[n])
        //         res.push_back(w);
        //     dict.insert(w);
        // }
        return res;
    }
};