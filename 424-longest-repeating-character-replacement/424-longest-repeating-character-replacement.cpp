class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int j = 0, longest = 0;
        int res = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            longest = max(longest, mp[s[i]]);
            if(i - j + 1 - longest > k)
                mp[s[j++]]--;
            res = max(res, i - j + 1);
        }
        return res;
    }
};