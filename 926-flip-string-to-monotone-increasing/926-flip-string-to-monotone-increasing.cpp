class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
                ones++;
        }
        int ans = n;
        ans = min(ans, ones);
        int removeZero = 0;
        for(int i = n-1;i>= 0; i--)
        {
            if(s[i] == '0')
                removeZero++;
            else
                ones--;
            ans = min(ans, removeZero+ones);
        }
        return ans;
    }
};