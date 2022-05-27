class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> mp;
        if(s == "")
            return 0;
        for(auto c : s)
            mp[c]++;
        int ans = 0;
        int i = -1, n = s.size();
        for(int j = 0; j < n; j++)
        {
            if(mp[s[j]] < k)
            {
                ans = max(ans, longestSubstring(s.substr(i+1, j-i-1), k));
                i = j;
            }
        }
        if(i == -1)
            ans = max(ans, n-i-1);
        else
            ans = max(ans, longestSubstring(s.substr(i+1, n-i-1), k));
        // cout<<ans<<" "<<s<<"  "<<n<<" "<<i<<endl;
        // ans = max(ans, n-i-1);
        return ans;
    }
};