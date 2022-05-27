class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> charArray(256, false);
        int n = s.size();
        int mx = 0;
        int j = 0, i = 0;
        for(int i = 0; i < n; i++)
        {
            int c = s[i]; 
            while(charArray[c])
            {
                charArray[s[j++]] = false;
            }
            charArray[c] = true;
            mx = max(mx,i - j + 1);
        }
        return mx;
    }
};