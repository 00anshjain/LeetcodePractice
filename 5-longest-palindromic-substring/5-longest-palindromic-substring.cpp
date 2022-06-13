class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        int start = -1;
        int n = s.size();
        int sz = 0;
        for(int i = 0; i < n; i++)
        {
            int l = i, r = i;
            // if(l >= 0 && r < n && s[l] == s[r])
            // {
                while(l >= 0 && r < n && s[l] == s[r])
                {
                        r++;
                        l--;
                }
                if(ans < r - l - 1)
                {
                    start = l+1;
                    ans = r - l - 1;
                }
            // }
            l = i, r = i+1;
            if(l >= 0 && r < n && s[l] == s[r])
            {
                while(l >= 0 && r < n && s[l] == s[r])
                {       
                    r++;
                    l--;
                }
                if(ans < r - l - 1)
                {
                    start = l+1;
                    ans = r - l - 1;
                }
            }
        }
        return (s.substr(start, ans));
    }
};