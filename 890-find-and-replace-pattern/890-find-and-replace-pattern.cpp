class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;
        int n = p.size();
        for(auto w : words)
        {
            unordered_map<char, int> mp, mp2;
            if(w.size() != n)
                continue;
            int i;
            for(i = 0; i < n; i++)
            {
                if(mp.find(p[i]) == mp.end() && mp2.find(w[i]) == mp2.end())
                {
                    mp[p[i]] = w[i];
                    mp2[w[i]] = p[i];
                }
                else if(mp.find(p[i]) == mp.end()  || mp2.find(w[i]) == mp2.end())
                    break;
                else
                {
                    if(mp[p[i]] != w[i])
                        break;
                }
            }
            if(i == n)
                ans.push_back(w);
        }
        return ans;
    }
};