class Solution {
public:
    bool isPalin(string &s, int l, int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        while(l < r)
        {
            if(s[l] != s[r])
            {
                if(isPalin(s, l, r-1) || isPalin(s, l+1, r))
                    return true;
                return false;
            }
            l++;
            r--;
        }
        return true;//becuase it is a palindrome itself
        
    }
};