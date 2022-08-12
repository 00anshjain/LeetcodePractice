class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            if(ans < (r-1) - (l+1) + 1)
            {
                start = l+1;
                ans = (r-1) - (l+1) + 1;
            }
            // ans = max(ans, (l+1 + r-1 + 1));
            if(i + 1 == n)
                continue;
            l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
            }
            if(ans < (r-1) - (l+1) + 1)
            {
                start = l+1;
                ans = (r-1) - (l+1) + 1;
            }
            // ans = max(ans, (l+1 + r-1 + 1));
        }
        return s.substr(start, ans);
    }
};