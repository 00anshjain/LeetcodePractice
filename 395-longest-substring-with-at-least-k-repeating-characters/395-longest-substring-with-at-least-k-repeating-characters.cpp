class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if(n < k)
            return 0;
        unordered_map<char, int> mp;
        for(auto c : s)
            mp[c]++;
        int ans = 0;
        int i = -1;
        for(int j =0 ; j < n; j++)
        {
            if(mp[s[j]] < k)
            {    
                ans = max(ans, longestSubstring(s.substr(i+1, j-i-1), k));
                i = j;
                // cout<<ans<<" "<<i<<" "<<j<<endl;
            }
        }
        // cout<<i<<endl;
        if(i == -1)
            return n-i-1;
        else 
            ans = max(ans, longestSubstring(s.substr(i+1, n-i-1), k));
        return ans;
    }
};