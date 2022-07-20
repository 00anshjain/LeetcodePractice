class Solution {
public:
    bool isMatch(string &x, vector<vector<int>> &cnt)
    {
        int n = x.size();
        int last = -1;
        for(int i = 0; i <n; i++)
        {
            int c = x[i] - 'a';
            auto t = upper_bound(cnt[c].begin(), cnt[c].end(), last);
            if(t == cnt[c].end())
                return false;
            last = *t;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        for(auto x : words)
            mp[x]++;
        vector<vector<int>> cnt(26);
        int n = s.size();
        for(int i = 0; i < n; i++)
            cnt[s[i] - 'a'].push_back(i);
        int ans = 0;
        for(auto z : mp)
        {
            string x = z.first;
            if(isMatch(x, cnt))
                ans += z.second;
        }
        return ans;
    }
};