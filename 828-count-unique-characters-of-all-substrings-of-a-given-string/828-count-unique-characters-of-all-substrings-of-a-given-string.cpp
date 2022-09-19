class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        // vector<vector<int>> pre(n+1,vector<int>(26,0));
        vector<int> left(n,-1), right(n, n);
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                left[i] = mp[s[i]];
            }
            mp[s[i]] = i;
        }
        mp.clear();
        for(int i = n-1; i >= 0; i--)
        {
            if(mp.find(s[i]) != mp.end())
            {
                right[i] = mp[s[i]];
            }
            mp[s[i]] = i;
        }
        int ans = 0;
        for(int i= 0; i < n; i++)
        {
            ans += (i - left[i])*(right[i] - i);
        }
        return ans;
    }
};