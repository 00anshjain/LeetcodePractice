class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> left(n, -1), right(n, n);
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++)
        {
            if(mp.count(s[i]))
            {
                left[i] = mp[s[i]];
            }
            mp[s[i]] = i;
        }
        mp.clear();
        for(int i = n-1; i >= 0; i--)
        {
            if(mp.count(s[i]))
            {
                right[i] = mp[s[i]];
            }
            mp[s[i]] = i;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += (i - left[i]) * (right[i] - i);
        }
        return ans;
    }
};